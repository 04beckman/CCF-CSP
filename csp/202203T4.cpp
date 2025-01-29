#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> need(n + 1, vector<int>(k));
    vector<int> left(k + 1, n * 2);
    vector<int> right(k + 1, -1);
    vector<vector<long long>> g(n + 1, vector<long long>(n + 1, LLONG_MAX));
    vector<long long> ms(k, LLONG_MAX);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            cin >> need[i][j];
            if (need[i][j])
            {
                left[j] = min(left[j], i);
                right[j] = max(right[j], i);
            }
        }
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (g[i][k] != LLONG_MAX && g[k][j] != LLONG_MAX)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    long long ans = -1;
    for (int i = 1; i <= k; ++i)
    {
        if (left[i] == right[i])
            ms[i] = 0;
        else
            ms[i] = g[left[i]][right[i]];
        if (ms[i] != LLONG_MAX)
            ans = max(ms[i], ans);
    }
    cout << ans << endl;
    return 0;
}