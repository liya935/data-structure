1  #include <stdio.h>
2
3  int main()
4  {
5      int a[100], b[100], c[200];
6      int n1, n2, i, j;
7
8      printf("Enter size of first array: ");
9      scanf("%d", &n1);
10
11     printf("Enter elements of first array:\n");
12     for(i = 0; i < n1; i++)
13         scanf("%d", &a[i]);
14
15     printf("Enter size of second array: ");
16     scanf("%d", &n2);
17
18     printf("Enter elements of second array:\n");
19     for(i = 0; i < n2; i++)
20         scanf("%d", &b[i]);
21
22     for(i = 0; i < n1; i++)
23         c[i] = a[i];
24
25     for(j = 0; j < n2; j++)
26         c[i + j] = b[j];
27
28     printf("Merged array:\n");
29     for(i = 0; i < n1 + n2; i++)
30         printf("%d ", c[i]);
31
32     return 0;
33 }