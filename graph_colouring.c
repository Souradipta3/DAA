#include <stdio.h>
#include <stdbool.h> 
int G[50][50], x[50];

void display(int n)
{
    int i;
    printf("Colors of vertices -->\n");
    int distinct_colors = 0; 
    for (i = 0; i < n; i++)
    {
        if (x[i] > distinct_colors)
        {
            distinct_colors = x[i]; 
        }
    }
    for (i = 0; i < n; i++)
        printf("Vertex[%d] : %d\n", i + 1, x[i]);
    printf("Number of colors: %d\n", distinct_colors); 
}

void next_color(int k, int n)
{
    int i, j;
    if (k == n)
    {
        display(n);
        return;
    }
    x[k] = 1;
    for (i = 0; i < k; i++)
    {
        if (G[i][k] != 0 && x[k] == x[i])
            x[k] = x[i] + 1;
    }
    next_color(k + 1, n);
}

int main()
{
    int no, eg, i, j, k, l;
    printf("\nEnter no. of vertices : ");
    scanf("%d", &no);
    printf("\nEnter no. of edges : ");
    scanf("%d", &eg);
    for (i = 0; i < no; i++)
        for (j = 0; j < no; j++)
            G[i][j] = 0;

    printf("Enter indexes where value is 1-->\n");
    for (i = 0; i < eg; i++)
    {
        scanf("%d %d", &k, &l);
        G[k][l] = 1;
        G[l][k] = 1;
    }
    next_color(0, no);
    return 0;
}