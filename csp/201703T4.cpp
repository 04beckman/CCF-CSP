#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    unordered_map<int, vector<pair<int, int>>> g;
    vector<int> mincost(n + 1, INT_MAX);
    mincost[1] = 0;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(c, b);
        g[b].emplace_back(c, a);
    }
    queue<pair<int, int>> q;
    q.emplace(0, 1);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (temp.second == n)
            continue;
        if (temp.first > mincost[temp.second])
            continue;
        for (auto &u : g[temp.second])
        {
            int k = max(temp.first, u.first);
            if (k >= mincost[u.second])
            {
                continue;
            }
            else
            {
                q.emplace(k, u.second);
                mincost[u.second] = k;
            }
        }
    }
    cout << mincost[n];
    system("pause");
    return 0;
}