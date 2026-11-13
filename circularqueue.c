 1
  2 #include <stdio.h>
  3 #define SIZE 5
  4
  5 int queue[SIZE];
  6 int front = -1, rear = -1;
  7
  8 void enqueue(int value) {
  9     if ((rear + 1) % SIZE == front) {
 10         printf("Queue is FULL (Overflow).\n");
 11         return;
 12     }
 13
 14     if (front == -1)
 15         front = 0;
 16
 17     rear = (rear + 1) % SIZE;
 18     queue[rear] = value;
 19
 20     printf("%d inserted.\n", value);
 21 }
 22
 23 void dequeue() {
 24     if (front == -1) {
 25         printf("Queue is EMPTY (Underflow).\n");
 26         return;
 27     }
 28
 29     printf("%d deleted.\n", queue[front]);
 30
 31     if (front == rear) {
 32         front = rear = -1;
 33     }
 34     else {
 35         front = (front + 1) % SIZE;
 36     }
 37 }
 38
 39 void display() {
 40     if (front == -1) {
 41         printf("Queue is EMPTY.\n");
 42         return;
 43     }
 44
 45     printf("Queue: ");
 46
 47     int i = front;
 48
 49     while (1) {
 50         printf("%d ", queue[i]);
 51
 52         if (i == rear)
 53             break;
 54
 55         i = (i + 1) % SIZE;
 56     }
 57
 58     printf("\n");
 59 }
 60
 61 int main() {
 62     int choice, value;
 63
 64     while (1) {
 65         printf("\n--- Circular Queue ---\n");
 66         printf("1. Insert\n");
 67         printf("2. Delete\n");
 68         printf("3. Display\n");
 69         printf("4. Exit\n");
 70
 71         printf("Enter choice: ");
 72
 73         if (scanf("%d", &choice) != 1) {
 74             printf("Invalid input.\n");
 75             return 1;
 76         }
 77
 78         switch (choice) {
 79             case 1:
 80                 printf("Enter value to insert: ");
 81                 if (scanf("%d", &value) != 1) {
 82                     printf("Invalid input.\n");
 83                     return 1;
 84                 }
 85                 enqueue(value);
 86                 break;
 87
 88             case 2:
 89                 dequeue();
 90                 break;
 91
 92             case 3:
 93                 display();
 94                 break;
 95
 96             case 4:
 97                 return 0;
 98
 99             default:
100                 printf("Invalid choice.\n");
101         }
102     }
103
104     return 0;
105 }
106




--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 20
20 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 50
50 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 40
40 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 30
30 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 90
90 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 20 50 40 30 90

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 2
20 deleted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 70
Invalid choice.
--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 70
70 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 50 40 30 90 70

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 4

                                             