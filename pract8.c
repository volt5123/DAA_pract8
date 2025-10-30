#include <stdio.h>

int isSafe(int v, int V, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;   
}

int solveColoring(int V, int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return 1;

    printf("\nVertex %c:\n", 'A' + v);
    for (int c = 1; c <= m; c++) {
        printf("  Trying Color %d...", c);
        if (isSafe(v, V, graph, color, c)) {
            printf(" Success!\n");
            color[v] = c;
            if (solveColoring(V, graph, m, color, v + 1))
                return 1;
            color[v] = 0;
            printf("  Backtracking...\n");
        } else {
            printf(" Conflict!\n");
        }
    }
    return 0;
}

void printSolution(int V, int color[]) {
    printf("\nFinal Color Assignment:\n");
    for (int i = 0; i < V; i++)
        printf("  Vertex %c ---> Color %d\n", 'A' + i, color[i]);
}

int main() {
    int V = 5;
    int graph[5][5] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int m = 3;
    int color[V];
    for (int i = 0; i < V; i++) color[i] = 0;

    printf("Adjacency Matrix:\n    ");
    for (int i = 0; i < V; i++) printf("%c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%c | ", 'A' + i);
        for (int j = 0; j < V; j++) printf("%d ", graph[i][j]);
        printf("\n");
    }

    if (solveColoring(V, graph, m, color, 0))
        printSolution(V, color);
    else
        printf("\nNo valid coloring possible.\n");

    return 0;
}
