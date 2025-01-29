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
    unordered_map<int, vector<pair<int, int>>> un;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        un[a].emplace_back(b, c);
        un[b].emplace_back(a, c);
    }
    vector<int> cost(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    cost[1] = 0;
    dist[1] = 0;
    long long mincost = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    q.push(make_pair(0, make_pair(1, 0)));
    while (!q.empty())
    {
        auto temp = q.top();
        q.pop();
        auto x = temp.first;
        auto y = temp.second.first;
        auto z = temp.second.second;
        if (x > dist[y] || z > cost[y])
            continue;
        mincost += z;
        for (auto &u : un[y])
        {
            if (x + u.second < dist[u.first])
            {
                dist[u.first] = x + u.second;
                q.push(make_pair(dist[u.first], make_pair(u.first, u.second)));
                cost[u.first] = u.second;
            }
            else if (x + u.second == dist[u.first] && u.second < cost[u.first])
            {
                q.push(make_pair(dist[u.first], make_pair(u.first, u.second)));
                cost[u.first] = u.second;
            }
        }
    }
    cout << mincost;
    return 0;
}