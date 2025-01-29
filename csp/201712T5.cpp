#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<long long> nums(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> nums[i];
    for (int i = 0; i < m; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            for (int i = l; i <= r; ++i)
            {
                if (nums[i] % v == 0)
                    nums[i] /= v;
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            long long ans = 0;
            for (int i = l; i <= r; ++i)
                ans += nums[i];
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}