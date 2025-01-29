#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 2e5 + 10;
int n, m, k;
int key[16];
char y[101];
int C[101];
int a[101][101];
int ans = 0;
void dfs(int l)
{
    if (l == n + 1)
    {
        int flag = 0;
        for (int i = 0; i < m; ++i)
        {
            int temp = 0;
            for (int j = 0; j < C[i]; ++j)
            {
                if (key[a[i][j]] == 1)
                    temp++;
            }
            if (temp < k && y[i] == 'o')
                flag = 1;
            if (temp >= k && y[i] == 'x')
                flag = 1;
        }
        if (flag == 0)
            ans++;
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        key[l] = i;
        dfs(l + 1);
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        cin >> C[i];
        for (int j = 0; j < C[i]; ++j)
            cin >> a[i][j];
        cin >> y[i];
    }
    dfs(1);
    cout << ans << endl;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}