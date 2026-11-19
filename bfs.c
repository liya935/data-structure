  1#include <stdio.h>
  2
  3 int main() {
  4     int n, graph[10][10], visited[10] = {0};
  5     int queue[10], front = 0, rear = -1;
  6
  7     printf("Enter number of nodes: ");
  8     scanf("%d", &n);
  9
 10     printf("Enter adjacency matrix:\n");
 11
 12     for (int i = 0; i < n; i++)
 13         for (int j = 0; j < n; j++)
 14             scanf("%d", &graph[i][j]);
 15
 16     int start;
 17     printf("Enter starting node: ");
 18     scanf("%d", &start);
 19
 20     visited[start] = 1;
 21     queue[++rear] = start;
 22
 23     printf("BFS order: ");
 24
 25     while (front <= rear) {
 26         int node = queue[front++];
 27         printf("%d ", node);
 28
 29         for (int i = 0; i < n; i++) {
 30             if (graph[node][i] == 1 && visited[i] == 0) {
 31                 visited[i] = 1;
 32                 queue[++rear] = i;
 33             }
 34         }
 35     }
 36
 37     return 0;
 38 }




Enter number of nodes: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting node: 0
BFS order: 0 1 2 3 