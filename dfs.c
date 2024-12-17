#include <stdio.h>

int G[10][10], visited[10];

void displayDFS(int v)
{
    printf("\t%d", v);
}

void DFS(int i, int n)
{
    int j;
    displayDFS(i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (!visited[j] && G[i][j] == 1)
        {
            DFS(j, n);
        }
    }
}

int main()
{
    int i, j, n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix (Transitive closure) of the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS Sequence:\n");
    DFS(0, n);
    return 0;
}
