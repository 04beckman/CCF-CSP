#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(void)
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    unordered_map<int, bool> un;
    un[0] = true;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        if (!un[r])
            ans++;
        un[l] = true;
    }
    cout << ans;
    system("pause");
    return 0;
}