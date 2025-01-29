#include <algorithm>
#include <iostream>
using namespace std;
int a[601][601];
int b[601][601]; // 前缀和数组，相当于上文的 sum[]

int main()
{
    int n, l, r;
    double t;
    cin >> n >> l >> r >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j]; // 求前缀和
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            int x1 = max(1, i - r);
            int y1 = max(1, j - r);
            int x2 = min(n, i + r);
            int y2 = min(n, j + r);
            int number = (x2 - x1 + 1) * (y2 - y1 + 1);
            double k = b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
            double average = double(k / number);
            if (average <= t)
                ans++;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}