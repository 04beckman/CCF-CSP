#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1e6 + 5;
int a[M];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x, y;
            cin >> x >> y;
            a[x] += 1;
            a[y] += -1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; ++i)
    {
        a[i] += a[i - 1];
        if (a[i] >= 2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}