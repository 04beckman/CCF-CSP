#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    unordered_map<int, int> un1;
    unordered_map<int, int> un0;
    vector<int> jilu;
    unordered_map<int, bool> k;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        nums[i][0] = a;
        nums[i][1] = b;
        if (!k[a])
            jilu.push_back(a);
        k[a] = true;
    }
    sort(jilu.begin(), jilu.end());
    sort(nums.begin(), nums.end());
    int num_1 = 0;
    int num_0 = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (nums[i][1] == 1)
        {
            num_1++;
            un1[nums[i][0]] = num_1;
        }
    }
    for (int i = 0; i < n; ++i)
    {

        if (nums[i][1] == 0)
        {
            num_0++;
            un0[nums[i][0]] = num_0;
        }
    }
    int ans = 0;
    int ri = 0;
    for (int i = 0; i < jilu.size(); ++i)
    {
        int temp = 0;
        temp += un1[jilu[i]];
        if (i != 0)
            temp += un0[jilu[i - 1]];
        if (ans <= temp)
        {
            ans = temp;
            ri = jilu[i];
        }
    }
    cout << ri;
    system("pause");
    return 0;
}