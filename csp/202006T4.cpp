#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mod = 998244353;
int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n, vector<int>(7));
    dp[0][2] = 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i][2] = (dp[i][2] % mod + dp[i - 1][1] % mod) % mod;
        dp[i][1] = (dp[i][1] % mod + dp[i - 1][4] % mod) % mod;
        dp[i][4] = ((dp[i][6] % mod + dp[i - 1][6] % mod) % mod + dp[i - 1][2]) % mod;
        dp[i][6] = ((dp[i][6] % mod + dp[i - 1][6] % mod) % mod + dp[i - 1][4]) % mod;
    }
    cout << dp[n - 1][k];
    return 0;
}