#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    int n, L, t;
    cin >> n >> L >> t;
    // n表示个数 L表示长度 t表示t秒后
    // a记录第i个球初始位置 b记录最终坐标 mp的key自动排序，可用来求最终坐标
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    // 记录t秒后该球的坐标
    for (int i = 0; i < n; ++i)
    {
        int k = a[i] + t;
        if ((k / L) % 2 == 0)
            b[i] = k % L;
        else
            b[i] = L - (k % L);
    }
    int i = 0;
    sort(b.begin(), b.end());
    for (auto &x : mp)
        x.second = b[i++];
    for (int i = 0; i < n; ++i)
        cout << mp[a[i]] << " ";
    return 0;
}