#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(void)
{
    int n, l, s;
    cin >> n >> l >> s;
    unordered_map<int, unordered_map<int, bool>> A;
    unordered_map<int, unordered_map<int, bool>> A1;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        A[x1][x2] = true;
        A1[x1][x2] = true;
        v.emplace_back(x1, x2);
    }
    vector<vector<int>> B(s + 1, vector<int>(s + 1));
    for (int i = s; i >= 0; i--)
        for (int j = 0; j <= s; j++)
            cin >> B[i][j];
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int z = v[i].first;
        int x = v[i].second;
        int flag = 0;
        for (int i = 0; i <= s; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (z + i <= l && x + j <= l && (B[i][j] == 0 && !A1[z + i][x + j]) || (B[i][j] == 1 && A1[z + i][x + j]))
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
            ans++;
    }
    cout << ans;
    system("pause");
    return 0;
}