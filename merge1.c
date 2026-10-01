1 #include <stdio.h>
  2
  3 int main()
  4 {
  5     int a[5], b[5], c[10];
  6     int i, j, k = 0, temp;
  7
  8     printf("Enter 5 elements of the first array:\n");
  9     for(i = 0; i < 5; i++)
 10     {
 11         scanf("%d", &a[i]);
 12     }
 13
 14     for(i = 0; i < 5; i++)
 15     {
 16         for(j = i + 1; j < 5; j++)
 17         {
 18             if(a[i] > a[j])
 19             {
 20                 temp = a[i];
 21                 a[i] = a[j];
 22                 a[j] = temp;
 23             }
 24         }
 25     }
 26
 27     printf("Sorted first array:\n");
 28     for(i = 0; i < 5; i++)
 29     {
 30         printf("%d ", a[i]);
 31     }
 32
 33     printf("\nEnter 5 elements of the second array:\n");
 34     for(i = 0; i < 5; i++)
 35     {
 36         scanf("%d", &b[i]);
 37     }
 38
 39     for(i = 0; i < 5; i++)
 40     {
 41         for(j = i + 1; j < 5; j++)
 42         {
 43             if(b[i] > b[j])
 44             {
 45                 temp = b[i];
 46                 b[i] = b[j];
 47                 b[j] = temp;
 48             }
 49         }
 50     }
 51
 52     printf("Sorted second array:\n");
 53     for(i = 0; i < 5; i++)
 54     {
 55         printf("%d ", b[i]);
 56     }
 57
 58     i = 0;
 59     j = 0;
 60     k = 0;
 61
 62     while(i < 5 && j < 5)
 63     {
 64         if(a[i] < b[j])
 65         {
 66             c[k] = a[i];
 67             i++;
 68         }
 69         else
 70         {
 71             c[k] = b[j];
 72             j++;
 73         }
 74         k++;
 75     }
 76
 77     while(i < 5)
 78     {
 79         c[k] = a[i];
 80         i++;
 81         k++;
 82     }
 83
 84     while(j < 5)
 85     {
 86         c[k] = b[j];
 87         j++;
 88         k++;
 89     }
 90
 91     printf("\nMerged sorted array:\n");
 92     for(i = 0; i < 10; i++)
 93     {
 94         printf("%d ", c[i]);
 95     }
 96
 97     return 0;
 98 } 


Enter 5 elements of the first array:
3
6
7
8
4
Sorted first array:
3 4 6 7 8
Enter 5 elements of the second array:
2
5
8
5
3
Sorted second array:
2 3 5 5 8
Merged sorted array:
2 3 3 4 5 5 6 7 8 8                            