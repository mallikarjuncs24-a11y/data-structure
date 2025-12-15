#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

void bfs(int start) {
    int i, v;
    queue[++rear] = start;
    visited[start] = 1;
    
    while (front <= rear) {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Error: Max vertices is %d.\n", MAX);
        return 1;
    }
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    if (start < 0 || start >= n) {
        printf("Invalid start vertex.\n");
        return 1;
    }

    printf("BFS traversal: ");
    bfs(start);
    return 0;
}
