  1 #include <stdio.h>
  2
  3 #define SIZE 9
  4
  5 typedef struct {
  6     unsigned char x : 1;
  7 } bit;
  8
  9 
 10 const int uset[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 11
 12
 13 void readset(bit a[], int n);
 14 void printset(const bit a[]);
 15 void unionset(const bit a[], const bit b[], bit c[]);
 16 void intersect(const bit a[], const bit b[], bit c[]);
 17 void difference(const bit a[], const bit b[], bit c[]);
 18
 19 int main(void)
 20 {
 21     bit a[SIZE] = {{0}}, b[SIZE] = {{0}}, c[SIZE] = {{0}};
 22     int n;
 23
 24     printf("Universal set: {1,2,3,4,5,6,7,8,9}\n\n");
 25
 26     printf("No. of elements in set A: ");
 27     if (scanf("%d", &n) != 1) return 1;
 28     readset(a, n);
 29
 30     printf("No. of elements in set B: ");
 31     if (scanf("%d", &n) != 1) return 1;
 32     readset(b, n);
 33
 34     printf("\nSet A: ");
 35     printset(a);
 36
 37     printf("Set B: ");
 38     printset(b);
 39
 40     unionset(a, b, c);
 41     printf("\nA U B = ");
 42     printset(c);
 43
 44     intersect(a, b, c);
 45     printf("\nA intersect B = ");
 46     printset(c);
 47
 48     difference(a, b, c);
 49     printf("\nA - B = ");
 50     printset(c);
 51
 52     return 0;
 53 }
 54
 55 
 56 void readset(bit a[], int n)
 57 {
 58     int i, k, x;
 59
 60     if (n < 0 || n > SIZE) {
 61         printf("Invalid size; must be between 0 and %d.\n", SIZE);
 62         return;
 63     }
 64
 65     printf("Enter %d elements: ", n);
 66
 67     for (i = 0; i < n; i++) {
 68         if (scanf("%d", &x) != 1) return;
 69
 70         for (k = 0; k < SIZE; k++) {
 71             if (uset[k] == x) {
 72                 a[k].x = 1;
 73                 break;
 74             }
 75         }
 76
 77         if (k == SIZE)
 78             printf("%d is not in the universal set, ignored.\n", x);
 79     }
 80 }
 81
 82 
 83 void printset(const bit a[])
 84 {
 85     int k, first = 1;
 86
 87     printf("{");
 88
 89     for (k = 0; k < SIZE; k++) {
 90         if (a[k].x) {
 91             printf(first ? "%d" : ",%d", uset[k]);
 92             first = 0;
 93         }
 94     }
 95
 96     printf("}\n");
 97 }
 98
 99 
100 void unionset(const bit a[], const bit b[], bit c[])
101 {
102     for (int k = 0; k < SIZE; k++)
103         c[k].x = a[k].x | b[k].x;
104 }
105
106 
107 void intersect(const bit a[], const bit b[], bit c[])
108 {
109     for (int k = 0; k < SIZE; k++)
110         c[k].x = a[k].x & b[k].x;
111 }
112
113 
114 void difference(const bit a[], const bit b[], bit c[])
115 {
116     for (int k = 0; k < SIZE; k++)
117         c[k].x = a[k].x && !b[k].x;
118 }


Universal set: {1,2,3,4,5,6,7,8,9}

No. of elements in set A: 4
Enter 4 elements: 5
6
2
7
No. of elements in set B: 4
Enter 4 elements: 8
9
3
6

Set A: {2,5,6,7}
Set B: {3,6,8,9}

A U B = {2,3,5,6,7,8,9}

A intersect B = {6}

A - B = {2,5,7}
