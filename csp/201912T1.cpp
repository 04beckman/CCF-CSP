#include <stdio.h>
#include <stdlib.h>
void transpose(int (*matrix)[11], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < m; j++)
        {

            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int matrix[11][11];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    transpose(matrix, n, m);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                printf("%d ", matrix[i][j]);
            else
                printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}