#include <stdio.h>

void bfs(int v, int n, int a[][20], int visited[], int q[], int *f, int *r)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && !visited[i])
        {
            q[++(*r)] = i;
            visited[i] = 1;
        }
    }
    if (*f <= *r)
    {
        bfs(q[(*f)++], n, a, visited, q, f, r);
    }
}

void displayBFS(int n, int visited[])
{
    int i;
    printf("\nBFS sequence:\n");
    for (i = 0; i < n; i++)
    {
        if (visited[i])
        {
            printf("%d\t", i);
        }
    }
    if (!visited[n - 1])
    {
        printf("\nBFS is not possible\n");
    }
}

int main()
{
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int a[20][20];
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int q[20] = {0}, visited[20] = {0}, f = 0, r = -1;
    bfs(0, n, a, visited, q, &f, &r);
    displayBFS(n, visited);

    return 0;
}
