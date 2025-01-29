#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
struct node
{
    int num;
    int price;
    node(int a, int b) : num(a), price(b) {}
};
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> used(n + 1);
    unordered_map<int, vector<node>> un;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        un[a].push_back(node(b, c));
        un[b].push_back(node(a, c));
    }
    dist[1] = 0;
    long long ans = 0;
    while (true)
    {
        int u = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        if (u == -1)
            break;
        used[u] = true;
        ans += dist[u];
        for (int i = 0; i < un[u].size(); ++i)
        {
            dist[un[u][i].num] = min(dist[un[u][i].num], un[u][i].price);
        }
    }
    cout << ans;
    return 0;
}