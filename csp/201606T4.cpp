#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;
int main()
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> nums(n + 1, vector<int>(m + 1, INT_MAX));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    nums[0][0] = 0;
    vector<vector<pair<int, int>>> shike(n + 1, vector<pair<int, int>>(m + 1));
    while (t--)
    {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        shike[r][c].first = a;
        shike[r][c].second = b;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
    q.push({0, 1, 1});
    int ans = INT_MAX;
    while (!q.empty())
    {
        auto t = q.top()[0];
        auto y = q.top()[1];
        auto x = q.top()[2];
        q.pop();
        if (x == n && y == m)
        {
            ans = min(ans, t);
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > n || nx < 1 || ny > m || ny < 1 || t + 1 > nums[nx][ny] || vis[nx][ny])
                continue;
            if (t + 1 <= shike[nx][ny].second && t + 1 >= shike[nx][ny].first)
            {
                if (t % 2)
                {
                    if (shike[nx][ny].second % 2)
                    {
                        int nt = shike[nx][ny].second + 1;
                        if (nt > nums[nx][ny])
                            continue;
                        q.push({shike[nx][ny].second + 1, ny, nx});
                        nums[nx][ny] = shike[nx][ny].second + 1;
                    }
                    else
                    {
                        int nt = shike[nx][ny].second + 2;
                        if (nt > nums[nx][ny])
                            continue;
                        q.push({shike[nx][ny].second + 2, ny, nx});
                        nums[nx][ny] = shike[nx][ny].second + 2;
                    }
                }
                else
                {
                    if (shike[nx][ny].second % 2)
                    {
                        int nt = shike[nx][ny].second + 2;
                        if (nt > nums[nx][ny])
                            continue;
                        q.push({shike[nx][ny].second + 2, ny, nx});
                        nums[nx][ny] = shike[nx][ny].second + 2;
                    }
                    else
                    {
                        int nt = shike[nx][ny].second + 1;
                        if (nt > nums[nx][ny])
                            continue;
                        q.push({shike[nx][ny].second + 1, ny, nx});
                        nums[nx][ny] = shike[nx][ny].second + 1;
                    }
                }
            }
            else
            {
                q.push({t + 1, ny, nx});
                nums[nx][ny] = t + 1;
            }
            vis[nx][ny] = true;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}