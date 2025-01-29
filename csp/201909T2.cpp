#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> flag(n);
    for (int i = 0; i < n; ++i)
    {
        int m, number;
        cin >> m >> number;
        for (int j = 0; j < m - 1; ++j)
        {
            int b;
            cin >> b;
            if (b < 0)
                number += b;
            else if (b > 0)
            {
                if (b == number)
                    continue;
                else
                {
                    flag[i] = 1;
                    number = b;
                }
            }
        }
        nums[i] = number;
    }
    int t = 0, d = 0, e = 0;
    for (int i = 0; i < n; ++i)
    {
        t += nums[i];
        if (flag[i])
            d++;
        if (flag[i] && flag[(i + 1) % n] && flag[(i + 2) % n])
            e++;
    }
    cout << t << " " << d << " " << e;
    return 0;
}