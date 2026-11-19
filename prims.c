 1 #include <stdio.h>
  2 #define INF 9999
  3
  4 int main()
  5 {
  6     int n;
  7
  8     printf("Enter number of nodes: ");
  9     scanf("%d", &n);
 10
 11     int cost[10][10], visited[10] = {0};
 12
 13     printf("Enter the adjacency matrix:\n");
 14
 15     for (int i = 0; i < n; i++)
 16         for (int j = 0; j < n; j++)
 17             scanf("%d", &cost[i][j]);
 18
 19     visited[0] = 1;
 20     int edges = 0;
 21
 22     printf("Edges in MST:\n");
 23
 24     while (edges < n - 1)
 25     {
 26         int min = INF, a = -1, b = -1;
 27
 28         for (int i = 0; i < n; i++)
 29         {
 30             if (visited[i])
 31             {
 32                 for (int j = 0; j < n; j++)
 33                 {
 34                     if (!visited[j] && cost[i][j] != 0 && cost[i][j] < min)
 35                     {
 36                         min = cost[i][j];
 37                         a = i;
 38                         b = j;
 39                     }
 40                 }
 41             }
 42         }
 43
 44         printf("%d -- %d (weight = %d)\n", a, b, min);
 45
 46         visited[b] = 1;
 47         edges++;
 48     }
 49
 50     return 0;
 51 }




Enter number of nodes: 4
Enter the adjacency matrix:
0 2 0 6
2 0 3 8
0 3 0 7
6 8 7 0
Edges in MST:
0 -- 1 (weight = 2)
1 -- 2 (weight = 3)
0 -- 3 (weight = 6)
