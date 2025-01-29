#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int count(vector<int> &arr)
{
    int cnt = 0;
    int first = -1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            if (i - first > 1)
                cnt++;
            first = i;
        }
    }
    if (arr[n - 1] != 0 && first != -1)
        cnt++;
    return cnt;
}
int main(void)
{
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int feiling = count(nums);
    int start = 2;
    int end = 1e4;
    while (start < end)
    {
        vector<int> temp = nums;
        for (int i = 0; i < n; ++i)
        {
            if (temp[i] < start)
                temp[i] = 0;
        }
        feiling = max(count(temp), feiling);
        start++;
    }
    cout << feiling;
    system("pause");
    return 0;
}