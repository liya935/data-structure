 1 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct Node {
  5     int data;
  6     struct Node *next;
  7 };
  8
  9 struct Node *front = NULL;
 10 struct Node *rear = NULL;
 11
 12 void enqueue(int value) {
 13     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 14
 15     if (newNode == NULL) {
 16         printf("Queue overflow\n");
 17         return;
 18     }
 19
 20     newNode->data = value;
 21     newNode->next = NULL;
 22
 23     if (rear == NULL) {
 24         front = rear = newNode;
 25     } else {
 26         rear->next = newNode;
 27         rear = newNode;
 28     }
 29
 30     rear->next = front;
 31     printf("%d enqueued to queue\n", value);
 32 }
 33
 34 void dequeue() {
 35     if (front == NULL) {
 36         printf("Queue underflow\n");
 37         return;
 38     }
 39
 40     struct Node *temp = front;
 41     printf("%d dequeued from queue\n", front->data);
 42
 43     if (front == rear) {
 44         front = rear = NULL;
 45     } else {
 46         front = front->next;
 47         rear->next = front;
 48     }
 49
 50     free(temp);
 51 }
 52
 53 void display() {
 54     if (front == NULL) {
 55         printf("Queue is empty\n");
 56         return;
 57     }
 58
 59     struct Node *temp = front;
 60     printf("Queue elements: ");
 61
 62     do {
 63         printf("%d -> ", temp->data);
 64         temp = temp->next;
 65     } while (temp != front);
 66
 67     printf("(back to front)\n");
 68 }
 69
 70 int main() {
 71     int choice, value;
 72
 73     while (1) {
 74         printf("\n1. Enqueue");
 75         printf("\n2. Dequeue");
 76         printf("\n3. Display");
 77         printf("\n4. Exit");
 78
 79         printf("\nEnter your choice: ");
 80         scanf("%d", &choice);
 81
 82         switch (choice) {
 83             case 1:
 84                 printf("Enter value: ");
 85                 scanf("%d", &value);
 86                 enqueue(value);
 87                 break;
 88
 89             case 2:
 90                 dequeue();
 91                 break;
 92
 93             case 3:
 94                 display();
 95                 break;
 96
 97             case 4:
 98                 return 0;
 99
100             default:
101                 printf("Invalid choice\n");
102         }
103     }
104
105     return 0;
106 }
          





1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 10
10 enqueued to queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 20
20 enqueued to queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 30
30 enqueued to queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 10 -> 20 -> 30 -> (back to front)

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
10 dequeued from queue

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 20 -> 30 -> (back to front)

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
                                       