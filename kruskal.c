  1 #include <stdio.h>
  2
  3 int main()
  4 {
  5     int n;
  6
  7     printf("Enter number of vertices: ");
  8     scanf("%d", &n);
  9
 10     int cost[10][10], parent[10];
 11     int a, b, u, v, min, edges = 0, total = 0;
 12
 13     printf("Enter cost adjacency matrix (0 = no edge):\n");
 14
 15     for (int i = 0; i < n; i++)
 16         for (int j = 0; j < n; j++)
 17             scanf("%d", &cost[i][j]);
 18
 19     for (int i = 0; i < n; i++)
 20         parent[i] = i;
 21
 22     printf("\nEdges selected:\n");
 23
 24     while (edges < n - 1)
 25     {
 26         min = 9999;
 27
 28         for (int i = 0; i < n; i++)
 29             for (int j = 0; j < n; j++)
 30                 if (cost[i][j] != 0 && cost[i][j] < min) {
 31                     min = cost[i][j];
 32                     a = i;
 33                     b = j;
 34                 }
 35
 36         u = a;
 37         while (parent[u] != u)
 38             u = parent[u];
 39
 40         v = b;
 41         while (parent[v] != v)
 42             v = parent[v];
 43
 44         if (u != v) {
 45             printf("%d => %d (cost = %d)\n", a, b, min);
 46             parent[u] = v;
 47             total += min;
 48             edges++;
 49         }
 50
 51         cost[a][b] = cost[b][a] = 9999;
 52     }
 53
 54     printf("\nTotal minimum cost = %d\n", total);
 55
 56     return 0;
 57 }




Enter number of vertices: 4
Enter cost adjacency matrix (0 = no edge):
0 10 6 5
10 0 15 0
6 15 0 4
5 0 4 0

Edges selected:
2 => 3 (cost = 4)
0 => 3 (cost = 5)
0 => 1 (cost = 10)

Total minimum cost = 19
