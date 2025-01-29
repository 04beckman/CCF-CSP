#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
ULL n, m;
const ULL mod = 1e9 + 7;
const ULL N = 1e5 + 10;
struct node
{
    ULL x, y, z;
} ns[N];
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        ULL c = 0;
        cin >> c;
        if (c == 1)
        {
            ULL L, R, a, b, c;
            cin >> L >> R >> a >> b >> c;
            for (; L <= R; ++L)
            {
                ns[L].x += a;
                ns[L].y += b;
                ns[L].z += c;
            }
        }
        else if (c == 2)
        {
            ULL L, R, k;
            cin >> L >> R >> k;
            for (; L <= R; ++L)
            {
                ns[L].x *= k;
                ns[L].x = ns[L].x % mod;
                ns[L].y *= k;
                ns[L].y = ns[L].y % mod;
                ns[L].z *= k;
                ns[L].z = ns[L].z % mod;
            }
        }
        else if (c == 3)
        {
            ULL L, R;
            cin >> L >> R;
            for (; L <= R; ++L)
            {
                ULL x_ = ns[L].x;
                ULL y_ = ns[L].y;
                ULL z_ = ns[L].z;
                ns[L].x = y_;
                ns[L].y = z_;
                ns[L].z = x_;
            }
        }
        else
        {
            ULL L, R;
            cin >> L >> R;
            ULL sx = 0;
            ULL sy = 0;
            ULL sz = 0;
            for (; L <= R; ++L)
            {
                sx += ns[L].x;
                sy += ns[L].y;
                sz += ns[L].z;
            }
            sx = sx % mod;
            sy = sy % mod;
            sz = sz % mod;
            ULL k = (sx * sx % mod + sy * sy % mod + sz * sz % mod) % mod;
            cout << k << endl;
        }
    }
    return 0;
}