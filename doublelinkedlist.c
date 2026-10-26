#include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct node {
  5     int data;
  6     struct node *prev, *next;
  7 };
  8
  9 struct node *head = NULL;
 10
 11 void insertBeginning() {
 12     struct node *newnode;
 13     int value;
 14
 15     newnode = malloc(sizeof(struct node));
 16
 17     printf("Enter data: ");
 18     scanf("%d", &value);
 19
 20     newnode->data = value;
 21     newnode->prev = NULL;
 22     newnode->next = head;
 23
 24     if (head != NULL)
 25         head->prev = newnode;
 26
 27     head = newnode;
 28 }
 29
 30 void insertEnd() {
 31     struct node *newnode, *temp;
 32     int value;
 33
 34     newnode = malloc(sizeof(struct node));
 35
 36     printf("Enter data: ");
 37     scanf("%d", &value);
 38
 39     newnode->data = value;
 40     newnode->next = NULL;
 41     newnode->prev = NULL;
 42
 43     if (head == NULL) {
 44         head = newnode;
 45         return;
 46     }
 47
 48     temp = head;
 49
 50     while (temp->next != NULL)
 51         temp = temp->next;
 52
 53     temp->next = newnode;
 54     newnode->prev = temp;
 55 }
 56
 57 void displayForward() {
 58     struct node *temp = head;
 59
 60     if (head == NULL) {
 61         printf("List is empty\n");
 62         return;
 63     }
 64
 65     while (temp != NULL) {
 66         printf("%d <-> ", temp->data);
 67         temp = temp->next;
 68     }
 69
 70     printf("NULL\n");
 71 }
 72
 73 void deleteNode() {
 74     struct node *temp = head;
 75     int value;
 76
 77     if (head == NULL) {
 78         printf("List is empty\n");
 79         return;
 80     }
 81
 82     printf("Enter value to delete: ");
 83     scanf("%d", &value);
 84
 85     while (temp != NULL && temp->data != value)
 86         temp = temp->next;
 87
 88     if (temp == NULL) {
 89         printf("Node not found\n");
 90         return;
 91     }
 92
 93     if (temp->prev != NULL)
 94         temp->prev->next = temp->next;
 95     else
 96         head = temp->next;
 97
 98     if (temp->next != NULL)
 99         temp->next->prev = temp->prev;
100
101     free(temp);
102     printf("Node deleted\n");
103 }
104
105 void displayReverse() {
106     struct node *temp = head;
107
108     if (head == NULL) {
109         printf("List is empty\n");
110         return;
111     }
112
113     while (temp->next != NULL)
114         temp = temp->next;
115
116     while (temp != NULL) {
117         printf("%d <-> ", temp->data);
118         temp = temp->prev;
119     }
120
121     printf("NULL\n");
122 }
123
124 int main() {
125     int choice;
126
127     while (1) {
128         printf("\n1. Insert at beginning\n");
129         printf("2. Insert at end\n");
130         printf("3. Display forward\n");
131         printf("4. Delete a node\n");
132         printf("5. Display reverse\n");
133         printf("6. Exit\n");
134         printf("Enter choice: ");
135         scanf("%d", &choice);
136
137         switch (choice) {
138             case 1:
139                 insertBeginning();
140                 break;
141             case 2:
142                 insertEnd();
143                 break;
144             case 3:
145                 displayForward();
146                 break;
147             case 4:
148                 deleteNode();
149                 break;
150             case 5:
151                 displayReverse();
152                 break;
153             case 6:
154                 return 0;
155             default:
156                 printf("Invalid choice\n");
157         }
158     }
159 }





1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 1
Enter data: 10

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 2
Enter data: 20

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 2
Enter data: 30

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 3
10 <-> 20 <-> 30 <-> NULL
1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 5
30 <-> 20 <-> 10 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 4
Enter value to delete: 20
Node deleted

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 3
10 <-> 30 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter choice: 6

                                  