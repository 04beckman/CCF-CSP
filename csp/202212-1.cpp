#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int ans = 0;
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i].second >> nums[i].first;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            int a = nums[i].second;
            int b = nums[i].first;
            if (b <= pq.size())
            {
                if (!pq.empty() && a > pq.top().first)
                {
                    ans += a - pq.top().first;
                    pq.pop();
                    pq.emplace(a, b);
                }
            }
            else
            {
                ans += a;
                pq.emplace(a, b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}