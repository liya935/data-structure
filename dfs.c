  1 #include <stdio.h>
  2
  3 int graph[10][10], visited[10], n;
  4
  5 void DFS(int v)
  6 {
  7     visited[v] = 1;
  8     printf("%d ", v);
  9
 10     for (int i = 1; i <= n; i++)
 11     {
 12         if (graph[v][i] == 1 && !visited[i])
 13         {
 14             DFS(i);
 15         }
 16     }
 17 }
 18
 19 int main()
 20 {
 21     int i, j, start;
 22
 23     printf("Enter number of vertices: ");
 24     scanf("%d", &n);
 25
 26     printf("Enter adjacency matrix:\n");
 27
 28     for (i = 1; i <= n; i++)
 29     {
 30         for (j = 1; j <= n; j++)
 31         {
 32             scanf("%d", &graph[i][j]);
 33         }
 34     }
 35
 36     for (i = 1; i <= n; i++)
 37         visited[i] = 0;
 38
 39     printf("Enter starting vertex: ");
 40     scanf("%d", &start);
 41
 42     printf("DFS Traversal: ");
 43     DFS(start);
 44
 45     return 0;
 46 }



Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex: 1
DFS Traversal: 1 2 4 3
