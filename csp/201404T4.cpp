#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;
struct node
{
    int x;
    int y;
    int k;
    node(int a, int b, int c)
    {
        x = a;
        y = b;
        k = c;
    }
};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, unordered_map<int, int>> g;
    int n, m, k;
    long long r;
    cin >> n >> m >> k >> r;
    vector<pair<int, int>> ps(n);
    vector<pair<int, int>> ks;
    for (int i = 0; i < n; ++i)
    {
        cin >> ps[i].first >> ps[i].second;
        g[ps[i].first][ps[i].second] = INT_MAX;
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = INT_MAX;
        ks.emplace_back(a, b);
    }
    g[ps[0].first][ps[0].second] = 0;
    queue<node> q;
    q.emplace(ps[0].first, ps[0].second, 0);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (temp.k > g[temp.x][temp.y])
            continue;
        if (temp.x == ps[1].first && temp.y == ps[1].second)
            continue;
        for (int i = 0; i < n; ++i)
        {
            long long t1 = ps[i].first;
            long long t2 = ps[i].second;
            if ((t1 - temp.x) * (t1 - temp.x) + (t2 - temp.y) * (t2 - temp.y) <= r * r && temp.k + 1 < g[t1][t2])
            {
                q.emplace(t1, t2, temp.k + 1);
                g[t1][t2] = temp.k + 1;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            long long t1 = ks[i].first;
            long long t2 = ks[i].second;
            if ((t1 - temp.x) * (t1 - temp.x) + (t2 - temp.y) * (t2 - temp.y) <= r * r && temp.k + 1 < g[t1][t2])
            {
                q.emplace(t1, t2, temp.k + 1);
                g[t1][t2] = temp.k + 1;
            }
        }
    }
    cout << g[ps[1].first][ps[1].second] - 1 << endl;
    return 0;
}