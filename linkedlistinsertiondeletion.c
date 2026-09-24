#include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct Node {
  5     int data;
  6     struct Node* next;
  7 };
  8
  9 struct Node* createNode(int data) {
 10     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 11
 12     if (newNode == NULL) {
 13         printf("Memory allocation failed!\n");
 14         exit(1);
 15     }
 16
 17     newNode->data = data;
 18     newNode->next = NULL;
 19
 20     return newNode;
 21 }
 22
 23 void display(struct Node* head) {
 24     struct Node* temp = head;
 25
 26     if (temp == NULL) {
 27         printf("List is empty\n");
 28         return;
 29     }
 30
 31     printf("Linked List: ");
 32
 33     while (temp != NULL) {
 34         printf("%d -> ", temp->data);
 35         temp = temp->next;
 36     }
 37
 38     printf("NULL\n");
 39 }
 40
 41 void insertAtBeginning(struct Node** head, int data) {
 42     struct Node* newNode = createNode(data);
 43
 44     newNode->next = *head;
 45     *head = newNode;
 46 }
 47
 48 void insertAtEnd(struct Node** head, int data) {
 49     struct Node* newNode = createNode(data);
 50
 51     if (*head == NULL) {
  51     if (*head == NULL) {
 52         *head = newNode;
 53         return;
 54     }
 55
 56     struct Node* temp = *head;
 57
 58     while (temp->next != NULL)
 59         temp = temp->next;
 60
 61     temp->next = newNode;
 62 }
 63
 64 void insertAtPosition(struct Node** head, int data, int position) {
 65     if (position < 1) {
 66         printf("Invalid position!\n");
 67         return;
 68     }
 69
 70     if (position == 1) {
 71         insertAtBeginning(head, data);
 72         return;
 73     }
 74
 75     struct Node* temp = *head;
 76
 77     for (int i = 1; i < position - 1 && temp != NULL; i++)
 78         temp = temp->next;
 79
 80     if (temp == NULL) {
 81         printf("Position out of range!\n");
 82         return;
 83     }
 84
 85     struct Node* newNode = createNode(data);
 86
 87     newNode->next = temp->next;
 88     temp->next = newNode;
 89 }
 90
 91 void deleteAtBeginning(struct Node** head) {
 92     if (*head == NULL) {
 93         printf("List is empty!\n");
 94         return;
 95     }
 96
 97     struct Node* temp = *head;
 98
 99     *head = temp->next;
100     free(temp);
101 }
102
103 void deleteAtEnd(struct Node** head) {
104     if (*head == NULL) {
105         printf("List is empty!\n");
106         return;
107     }
108
109     if ((*head)->next == NULL) {
110         free(*head);
111         *head = NULL;
112         return;
113     }
114
115     struct Node* temp = *head;
116
117     while (temp->next->next != NULL)
118         temp = temp->next;
119
120     free(temp->next);
121     temp->next = NULL;
122 }
123
124 void deleteAtPosition(struct Node** head, int position) {
125     if (*head == NULL) {
126         printf("List is empty!\n");
127         return;
128     }
129
130     if (position < 1) {
131         printf("Invalid position!\n");
132         return;
133     }
134
135     struct Node* temp = *head;
136
137     if (position == 1) {
138         *head = temp->next;
139         free(temp);
140         return;
141     }
142
143     for (int i = 1; temp != NULL && i < position - 1; i++)
144         temp = temp->next;
145
146     if (temp == NULL || temp->next == NULL) {
147         printf("Position out of range!\n");
148         return;
149     }
150
151     struct Node* nextNode = temp->next->next;
152
153     free(temp->next);
154     temp->next = nextNode;
155 }
156
157 void freeList(struct Node** head) {
158     struct Node* temp;
159
160     while (*head != NULL) {
161         temp = *head;
162         *head = (*head)->next;
163         free(temp);
164     }
165 }
166
167 int main() {
168     struct Node* head = NULL;
169     int choice, data, pos;
170
171     while (1) {
172         printf("\n-- Linked List Menu --\n");
173         printf("1. Insert at Beginning\n");
174         printf("2. Insert at End\n");
175         printf("3. Insert at Position\n");
176         printf("4. Delete at Beginning\n");
177         printf("5. Delete at End\n");
178         printf("6. Delete at Position\n");
179         printf("7. Display\n");
180         printf("8. Exit\n");
181
182         printf("Enter your choice: ");
183
184         if (scanf("%d", &choice) != 1) {
185             freeList(&head);
186             return 0;
187         }
188
189         switch (choice) {
190
191             case 1:
192                 printf("Enter data: ");
193                 scanf("%d", &data);
194                 insertAtBeginning(&head, data);
195                 break;
196
197             case 2:
198                 printf("Enter data: ");
199                 scanf("%d", &data);
200                 insertAtEnd(&head, data);
201                 break;
202
203             case 3:
204                 printf("Enter data and position: ");
205                 scanf("%d %d", &data, &pos);
206                 insertAtPosition(&head, data, pos);
207                 break;
208
209             case 4:
210                 deleteAtBeginning(&head);
211                 break;
212
213             case 5:
214                 deleteAtEnd(&head);
215                 break;
216
217             case 6:
218                 printf("Enter position: ");
219                 scanf("%d", &pos);
220                 deleteAtPosition(&head, pos);
221                 break;
222
223             case 7:
224                 display(head);
225                 break;
226
227             case 8:
228                 freeList(&head);
229                 exit(0);
230
231             default:
232                 printf("Invalid choice!\n");
233         }
234     }
235
236     return 0;
237 }
          -- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 1
Enter data: 20

-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 1
Enter data: 30

-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 20
Invalid choice!

-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 7
Linked List: 20 -> NULL

-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit

                                            