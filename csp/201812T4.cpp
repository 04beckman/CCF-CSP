#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
using namespace std;
int main(void)
{
    int ans = 0;
    int n, m, root;
    cin >> n >> m >> root;
    vector<int> mincost(50010, INT_MAX);
    vector<bool> used(50010, false);
    mincost[root] = 0;
    used[root] = true;
    unordered_map<int, vector<pair<int, int>>> g;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, root);
    while (!pq.empty())
    {
        auto temp = pq.top();
        int &x = temp.first;
        int &y = temp.second;
        pq.pop();
        if (x > mincost[y])
            continue;
        ans = max(ans, x);
        used[y] = true;
        for (auto &k : g[y])
        {
            int &u = k.first;
            int &w = k.second;
            if (w < mincost[u] && !used[u])
            {
                mincost[u] = w;
                pq.emplace(w, u);
            }
        }
    }
    cout << ans;
    system("pause");
    return 0;
}