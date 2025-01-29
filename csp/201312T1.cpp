#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> cnt(10001);
    while (n--)
    {
        int k;
        cin >> k;
        cnt[k]++;
    }
    int min1 = 0;
    int ans = 0;
    for (int i = 0; i < 10001; ++i)
    {
        if (cnt[i] > min1)
        {
            min1 = cnt[i];
            ans = i;
        }
    }
    cout << ans;
    return 0;
}