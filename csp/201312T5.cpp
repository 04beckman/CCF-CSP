#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define d(x) cout << x << endl

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 50 + 10;

int R, C, sx, sy, ex, ey;
const int di[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char a[N][N];
int check[N][N], vis[N][N];
struct node
{
    int x, y;
};

void bfs(int x, int y)
{
    queue<node> q;
    q.push(node{x, y});
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        int tx = cur.x, ty = cur.y;
        check[tx][ty] = 1;
        for (int i = 0; i < 4; i++)
        {
            if ((i > 1 && a[tx][ty] == '|') || (i < 2 && a[tx][ty] == '-'))
                continue;
            if (i != 1 && a[tx][ty] == '.')
                continue;
            int xx = tx + di[i][0], yy = ty + di[i][1];
            if (xx >= 0 && xx < R && yy >= 0 && yy < C && !vis[xx][yy] && a[xx][yy] != '#')
            {
                vis[xx][yy] = 1;
                q.push(node{xx, yy});
            }
        }
    }
}
int main()
{
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        scanf("%s", a[i]);
        for (int j = 0; j < C; j++)
        {
            if (a[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (a[i][j] == 'T')
            {
                ex = i;
                ey = j;
            }
        }
    }
    bfs(sx, sy);
    if (check[ex][ey] == 0)
    {
        printf("I'm stuck!\n");
        return 0;
    }
    else
    {
        int ans = 0;
        int tmp[N][N];
        memcpy(tmp, check, sizeof(check));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (tmp[i][j] == 1)
                {
                    memset(check, 0, sizeof(check));
                    bfs(i, j);
                    if (check[ex][ey] == 0)
                        ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}