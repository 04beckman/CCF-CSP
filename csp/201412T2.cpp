// ccf-Z字形扫描
#include <iostream>
using namespace std;
int main()
{
    // freopen("1.txt","r",stdin);
    int n;
    scanf("%d", &n);
    int a[501][501];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    // 程序是从(1,1)点进行斜扫描，下标之和正好是2到2n
    printf("%d ", a[1][1]);
    int mark = true; // 进行换方向的标志,如果斜对角线之和改变
    int sum;
    for (sum = 3; sum <= n * 2; sum++)
    {
        if (mark)
        {

            for (int i = 1; i < sum; i++)
            {
                if (sum - i <= n && i <= n)
                    printf("%d ", a[i][sum - i]); // 往左下进行打印
            }
            mark = false;
        }
        else if (!mark)
        {
            for (int i = 1; i < sum; i++)
            {
                if (sum - i <= n && i <= n)
                    printf("%d ", a[sum - i][i]); // 往右上进行打印
            }
            mark = true;
        }
        else
            break;
    }
    return 0;
}
