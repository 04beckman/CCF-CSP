#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
pair<int, int> nums[10010];
int n, m, k;
bool C(int t)
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i].first > t)
            ans = ans + (long long)(nums[i].first - t) * nums[i].second;
    }
    return ans <= m;
}
int main(void)
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        cin >> nums[i].first >> nums[i].second;
    int left = k;
    int right = 1e5;
    while (left < right)
    {
        int mid = (right + left) / 2;
        if (C(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << right;
    system("pause");
    return 0;
}