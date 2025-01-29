#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, N;
    cin >> n >> N;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int ans = 0;
    for (int i = 0; i <= N - 1; i++)
    {
        auto iter = lower_bound(v.begin(), v.end(), i);
        if (*iter == i)
            ans += iter - v.begin();
        else
            ans += iter - v.begin() - 1;
    }
    cout << ans;
    system("pause");
    return 0;
}