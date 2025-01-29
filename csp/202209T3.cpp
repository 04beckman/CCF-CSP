#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <set>
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    unordered_map<int, unordered_map<int, bool>> df;
    unordered_map<int, vector<vector<int>>> dy; // 某天用户数据 日期 用户 地区
    vector<set<int>> ans(n);
    for (int d = 0; d < n; d++)
    {
        int r, m;
        cin >> r >> m;
        for (int j = 0; j < r; ++j)
        {
            int p;
            cin >> p;
            for (int k = d; k < d + 7; ++k)
                df[k][p] = true;
        }
        for (int j = 0; j < m; ++j)
        {
            int dd, u, r;
            cin >> dd >> u >> r;
            dy[d].push_back({dd, u, r});
        }
        for (int d0 = d - 6; d0 <= d; d0++)
        {
            for (int i = 0; i < dy[d0].size(); ++i)
            {
                int &r = dy[d0][i][2];
                int &u = dy[d0][i][1];
                int &d1 = dy[d0][i][0];
                if (d1 >= d - 6 && d1 <= d)
                {
                    int z = d1;
                    for (; z <= d; ++z)
                    {
                        if (!df[z][r])
                            break;
                    }
                    if (z == d + 1)
                        ans[d].insert(u);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto &x : ans[i])
            cout << " " << x;
        cout << endl;
    }
    system("pause");
    return 0;
}
// 需要一个每天记录信息的哈希表 记录当日存在的风险地区<int,un<int,bool>>
// 需要一个哈希表记录某天漫游数据的用户信息 <int,tuple<int,int,int>>

/*
9
1 4 1
0 1 1
-1 1 1
-1 2 1
0 2 2
0 3
0 3 1
1 2 2
1 3 2
0 0
0 0
0 0
0 0
0 0
0 1
5 4 1
1 0 1
*/