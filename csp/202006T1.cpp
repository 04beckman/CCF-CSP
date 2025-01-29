#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    unordered_map<int, long long> x1;
    unordered_map<int, long long> x2;
    for (int i = 0; i < a; ++i)
    {
        int x, y;
        cin >> x >> y;
        x1[x] = y;
    }
    for (int i = 0; i < b; ++i)
    {
        int x, y;
        cin >> x >> y;
        x2[x] = y;
    }
    long long ans = 0;
    for (auto &x : x1)
        ans += x.second * x2[x.first];
    cout << ans << endl;
    return 0;
}