  1 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct node
  5 {
  6     int data;
  7     struct node *next;
  8 };
  9
 10 int main()
 11 {
 12     struct node *front = NULL, *rear = NULL, *newnode, *temp;
 13     int choice, value;
 14
 15     while (1)
 16     {
 17         printf("\n--- QUEUE USING LINKED LIST ---\n");
 18         printf("1. Enqueue\n");
 19         printf("2. Dequeue\n");
 20         printf("3. Display\n");
 21         printf("4. Exit\n");
 22         printf("Enter your choice: ");
 23         scanf("%d", &choice);
 24
 25         if (choice == 1)
 26         {
 27             newnode = (struct node *)malloc(sizeof(struct node));
 28
 29             printf("Enter value: ");
 30             scanf("%d", &value);
 31
 32             newnode->data = value;
 33             newnode->next = NULL;
 34
 35             if (front == NULL)
 36             {
 37                 front = rear = newnode;
 38             }
 39             else
 40             {
 41                 rear->next = newnode;
 42                 rear = newnode;
 43             }
 44
 45             printf("%d inserted into queue.\n", value);
 46         }
 47
 48         else if (choice == 2)
 49         {
 50             if (front == NULL)
 51             {
  52                 printf("Queue is empty.\n");
 53             }
 54             else
 55             {
 56                 temp = front;
 57                 printf("%d deleted from queue.\n", front->data);
 58
 59                 front = front->next;
 60
 61                 if (front == NULL)
 62                     rear = NULL;
 63
 64                 free(temp);
 65             }
 66         }
 67
 68         else if (choice == 3)
 69         {
 70             if (front == NULL)
 71             {
 72                 printf("Queue is empty.\n");
 73             }
 74             else
 75             {
 76                 temp = front;
 77
 78                 printf("Queue: ");
 79
 80                 while (temp != NULL)
 81                 {
 82                     printf("%d ", temp->data);
 83                     temp = temp->next;
 84                 }
 85
 86                 printf("\n");
 87             }
 88         }
 89
 90         else if (choice == 4)
 91         {
 92             exit(0);
 93         }
 94
 95         else
 96         {
 97             printf("Invalid choice.\n");
 98         }
 99     }
100
101     return 0;
102 }
103
           

--- QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 23
23 inserted into queue.

--- QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 34
34 inserted into queue.

--- QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 87
87 inserted into queue.

--- QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
23 deleted from queue.

--- QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue: 34 87

--- QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
