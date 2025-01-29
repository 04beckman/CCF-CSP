#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, sum;
    cin >> n >> sum;
    vector<int> book(n);
    for (int i = 0; i < n; ++i)
        cin >> book[i];
    sort(book.begin(), book.end());
    int k = sum + book[book.size() - 1];
    vector<int> dp(sum + book[book.size() - 1] + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= book[i]; j--)
            dp[j] = dp[j] | dp[j - book[i]];
    }
    int i = sum;
    for (; i <= k; i++)
        if (dp[i])
            break;
    cout << i;
    return 0;
}