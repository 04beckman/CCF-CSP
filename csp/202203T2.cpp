#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int res[N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;
        // 在【l, r】时间段内做核酸，则t时刻可进入
        int l = max(t - k - c + 1, 0);
        l = min(l, 200000);
        int r = max(0, t - k);
        r = min(r, 200000);
        // 在【l, r】时间段内能出行的计划个数加一
        res[l] += 1;
        res[r + 1] -= 1;
    }
    // 利用差分计算每个时间的能出行个数
    for (int i = 1; i < 200001; i++)
    {
        res[i] += res[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << res[q] << endl;
    }
    return 0;
}
// 差分的思想 可以使得在此区间内+1