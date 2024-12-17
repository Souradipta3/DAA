#include <stdio.h> 

#define MAX_VERTICES 50

int G[MAX_VERTICES][MAX_VERTICES], x[MAX_VERTICES];
void display(int n) {
    printf("Colors of vertices -->\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex[%d] : %d\n", i + 1, x[i]);
    }
}

int is_safe(int k, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (G[k][i] && c == x[i]) {
            return 0;
        }
    }
    return 1;
}

void next_color(int k, int n) {
    if (k == n) {
        display(n);
        return;
    }
    for (int c = 1; c <= n; c++) {
        if (is_safe(k, c, n)) {
            x[k] = c;
            next_color(k + 1, n);
            x[k] = 0;
        }
    }
}

int main() {
    int no, eg, k, l;

    printf("Enter no. of vertices (max 50): ");
    scanf("%d", &no);
    if (no < 1 || no > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter no. of edges: ");
    scanf("%d", &eg);
    if (eg < 0 || eg > no * (no - 1) / 2) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    for (int i = 0; i < no; i++) {
        for (int j = 0; j < no; j++) {
            G[i][j] = 0;
        }
    }

    printf("Enter edges (vertex indexes separated by space):\n");
    for (int i = 0; i < eg; i++) {
        scanf("%d %d", &k, &l);
        if (k < 0 || k >= no || l < 0 || l >= no) {
            printf("Invalid edge.\n");
            return 1;
        }
        G[k][l] = 1;
        G[l][k] = 1;
    }

    next_color(0, no);

    return 0;
}