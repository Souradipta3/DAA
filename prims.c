#include <stdio.h>
#include <limits.h>

int visited[20] = {0}, mincost = 0, ne = 1;

void primMST(int n, int cost[20][20])
{
    int i, j, a, b, u, v, min;
    visited[1] = 1;
    printf("\n");
    while (ne < n)
    {
        min = INT_MAX;
        for (i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (j = 1; j <= n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (!visited[v])
        {
            printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
}

void display(int n, int temp[20][20])
{
    int i, j;
    printf("\nInput cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            if (temp[i][j] == INT_MAX)
                printf("%3d", 0);
            else
                printf("%3d", temp[i][j]);
        }
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main()
{
    int n, i, j, cost[20][20], temp[20][20];
    printf("\n Enter the number of nodes:");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            temp[i][j] = cost[i][j];
    primMST(n, cost);
    display(n, temp);
    return 0;
}