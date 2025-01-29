#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int ans = 0;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    for (int left = 0; left < n; ++left)
    {
        int height = nums[left];
        for (int right = left; right < n; ++right)
        {
            height = min(nums[right], height);
            ans = max(ans, (right - left + 1) * height);
        }
    }
    cout << ans;
    system("pause");
    return 0;
}