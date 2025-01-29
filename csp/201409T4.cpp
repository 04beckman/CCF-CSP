#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void)
{
    // 无穷是障碍
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    queue<pair<int, int>> q;
    vector<vector<int>> nums(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> mendian(m, vector<int>(2));
    vector<vector<int>> kehu(k, vector<int>(3));
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        mendian[i][0] = x;
        mendian[i][1] = y;
        nums[x][y] = 0;
        q.emplace(x, y);
    }
    for (int i = 0; i < k; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        kehu[i][0] = x;
        kehu[i][1] = y;
        kehu[i][2] = z;
    }
    for (int i = 0; i < d; ++i)
    {
        int x, y;
        cin >> x >> y;
        nums[x][y] = INT_MAX;
    }
    int max_1 = INT_MAX;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int xx = temp.first;
        int yy = temp.second;
        for (int i = 0; i < 4; ++i)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx > n || nx < 1 || ny > n || ny < 1 || nums[nx][ny] == INT_MAX || nums[nx][ny] != -1)
                continue;
            nums[nx][ny] = nums[xx][yy] + 1;
            q.emplace(nx, ny);
        }
    }
    long long ans = 0;
    for (int i = 0; i < kehu.size(); ++i)
    {
        int x = kehu[i][0];
        int y = kehu[i][1];
        int z = kehu[i][2];
        ans += nums[x][y] * z;
    }
    cout << ans;
    system("pause");
    return 0;
}