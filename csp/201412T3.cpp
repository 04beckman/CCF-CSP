#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5010;
struct NODE
{
    bool sell;
    double price;
    int num;
} node[N];
long long buy[N] = {0}, sell[N] = {0};
bool cmp(NODE a, NODE b)
{
    if (a.price == b.price)
        return a.sell > b.sell; // 价格相等，从sell方到buy方
    return a.price < b.price;   // 价格不等，按照价格从小到大
}
int main()
{
    string s;
    int index = 1, num_cancal;
    while (cin >> s)
    {
        if (s == "buy")
        {
            cin >> node[index].price >> node[index].num;
            node[index].sell = false;
        }
        else if (s == "sell")
        {
            cin >> node[index].price >> node[index].num;
            node[index].sell = true;
        }
        else
        {
            cin >> num_cancal;
            node[num_cancal].price = node[num_cancal].num = 0;
        }
        index++;
    }
    sort(node, node + index, cmp);
    int left = 1, high = index - 1;
    long long ans = 0, total = 0, sum = 0;
    double bestprice = 0;
    while (node[left].price == 0)
        left++;
    for (int i = high; i >= left; i--)
    {
        if (!node[i].sell)
            sum += node[i].num;
        buy[i] = sum;
    }
    sum = 0;
    for (int i = left; i <= high; i++)
    {
        if (node[i].sell)
            sum += node[i].num;
        sell[i] = sum;
    }
    for (int i = left; i <= high; i++)
    {
        ans = min(buy[i], sell[i]);
        if (ans >= total)
        {
            total = ans;
            bestprice = node[i].price;
        }
    }
    printf("%.2lf %lld", bestprice, total);
    return 0;
}
