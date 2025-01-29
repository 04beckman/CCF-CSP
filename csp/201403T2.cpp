#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int nums[2660][1440];
int main(void)
{
    unordered_map<int, vector<int>> un;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        un[i] = {a, b, c, d};
        for (int j = a; j <= c; ++j)
        {
            for (int k = b; k <= d; ++k)
            {
                nums[j][k] = i;
            }
        }
    }
    for (int z = 0; z < m; ++z)
    {
        int x, y;
        cin >> x >> y;
        int i = nums[x][y];
        if (i == 0)
            cout << "IGNORED" << endl;
        else
        {
            cout << nums[x][y] << endl;
            int a = un[i][0];
            int b = un[i][1];
            int c = un[i][2];
            int d = un[i][3];
            for (int j = a; j <= c; ++j)
            {
                for (int k = b; k <= d; ++k)
                {
                    nums[j][k] = i;
                }
            }
        }
    }
    system("pause");
    return 0;
}