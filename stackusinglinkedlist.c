  1 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct Node {
  5     int data;
  6     struct Node *next;
  7 };
  8
  9 struct Node *top = NULL;
 10
 11 void push(int value) {
 12     struct Node *newNode;
 13
 14     newNode = (struct Node *)malloc(sizeof(struct Node));
 15
 16     if (newNode == NULL) {
 17         printf("Stack Overflow\n");
 18         return;
 19     }
 20
 21     newNode->data = value;
 22     newNode->next = top;
 23     top = newNode;
 24
 25     printf("%d pushed into stack\n", value);
 26 }
 27
 28 void pop() {
 29     struct Node *temp;
 30
 31     if (top == NULL) {
 32         printf("Stack Underflow\n");
 33         return;
 34     }
 35
 36     temp = top;
 37     printf("%d popped from stack\n", top->data);
 38     top = top->next;
 39
 40     free(temp);
 41 }
 42
 43 void display() {
 44     struct Node *temp = top;
 45
 46     if (top == NULL) {
 47         printf("Stack is empty\n");
 48         return;
 49     }
 50
 51     printf("Stack elements are:\n");
 52
 53     while (temp != NULL) {
 54         printf("%d\n", temp->data);
 55         temp = temp->next;
 56     }
 57 }
 58
 59 int main() {
 60     int choice, value;
 61
 62     while (1) {
 63         printf("\n1. Push\n");
 64         printf("2. Pop\n");
 65         printf("3. Display\n");
 66         printf("4. Exit\n");
 67         printf("Enter your choice: ");
 68         scanf("%d", &choice);
 69
 70         switch (choice) {
 71             case 1:
 72                 printf("Enter value: ");
 73                 scanf("%d", &value);
 74                 push(value);
 75                 break;
 76
 77             case 2:
 78                 pop();
 79                 break;
 80
 81             case 3:
 82                 display();
 83                 break;
 84
 85             case 4:
 86                 exit(0);
 87
 88             default:
 89                 printf("Invalid choice\n");
 90         }
 91     }
 92
 93     return 0;
 94 }


1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value: 45
45 pushed into stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value: 78
78 pushed into stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value: 67
67 pushed into stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
67 popped from stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements are:
78
45

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
