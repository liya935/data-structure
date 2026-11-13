 #include <stdio.h>
  3 #include <stdlib.h>
  4
  5 struct Node {
  6     int data;
  7     struct Node *left, *right;
  8 };
  9
 10 struct Node* newNode(int key) {
 11     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 12     node->data = key;
 13     node->left = node->right = NULL;
 14     return node;
 15 }
 16
 17 struct Node* insert(struct Node* root, int key) {
 18     if (root == NULL)
 19         return newNode(key);
 20
 21     if (key < root->data)
 22         root->left = insert(root->left, key);
 23     else if (key > root->data)
 24         root->right = insert(root->right, key);
 25     else
 26         printf("%d already exists.\n", key);
 27
 28     return root;
 29 }
 30
 31 struct Node* minNode(struct Node* root) {
 32     while (root->left != NULL)
 33         root = root->left;
 34
 35     return root;
 36 }
 37
 38 struct Node* deleteNode(struct Node* root, int key) {
 39     if (root == NULL) {
 40         printf("%d not found.\n", key);
 41         return NULL;
 42     }
 43
 44     if (key < root->data)
 45         root->left = deleteNode(root->left, key);
 46     else if (key > root->data)
 47         root->right = deleteNode(root->right, key);
 48     else {
 49         if (root->left == NULL) {
 50             struct Node* temp = root->right;
 51             free(root);
  52             return temp;
 53         }
 54
 55         if (root->right == NULL) {
 56             struct Node* temp = root->left;
 57             free(root);
 58             return temp;
 59         }
 60
 61         struct Node* succ = minNode(root->right);
 62         root->data = succ->data;
 63         root->right = deleteNode(root->right, succ->data);
 64     }
 65
 66     return root;
 67 }
 68
 69 void inorder(struct Node* root) {
 70     if (root == NULL)
 71         return;
 72
 73     inorder(root->left);
 74     printf("%d ", root->data);
 75     inorder(root->right);
 76 }
 77
 78 void preorder(struct Node* root) {
 79     if (root == NULL)
 80         return;
 81
 82     printf("%d ", root->data);
 83     preorder(root->left);
 84     preorder(root->right);
 85 }
 86
 87 void postorder(struct Node* root) {
 88     if (root == NULL)
 89         return;
 90
 91     postorder(root->left);
 92     postorder(root->right);
 93     printf("%d ", root->data);
 94 }
 95
 96 void search(struct Node* root, int key) {
 97     if (root == NULL) {
  98         printf("%d not found.\n", key);
 99         return;
100     }
101
102     if (key == root->data) {
103         printf("%d found in the BST.\n", key);
104     }
105     else if (key < root->data) {
106         search(root->left, key);
107     }
108     else {
109         search(root->right, key);
110     }
111 }
112
113 int main() {
114     struct Node* root = NULL;
115     int choice, value;
116
117     while (1) {
118         printf("\n--- Binary Search Tree ---\n");
119         printf("1. Insert\n");
120         printf("2. Delete\n");
121         printf("3. Inorder\n");
122         printf("4. Preorder\n");
123         printf("5. Postorder\n");
124         printf("6. Search\n");
125         printf("7. Exit\n");
126
127         printf("Enter choice: ");
128         scanf("%d", &choice);
129
130         switch (choice) {
131             case 1:
132                 printf("Enter value to insert: ");
133                 scanf("%d", &value);
134                 root = insert(root, value);
135                 break;
136
137             case 2:
138                 printf("Enter value to delete: ");
139                 scanf("%d", &value);
140                 root = deleteNode(root, value);
141                 break;
142
143             case 3:
144                 printf("Inorder: ");
145                 inorder(root);
146                 printf("\n");
147                 break;
148
149             case 4:
150                 printf("Preorder: ");
151                 preorder(root);
152                 printf("\n");
153                 break;
154
155             case 5:
156                 printf("Postorder: ");
157                 postorder(root);
158                 printf("\n");
159                 break;
160
161             case 6:
162                 printf("Enter value to search: ");
163                 scanf("%d", &value);
164                 search(root, value);
165                 break;
166
167             case 7:
168                 return 0;
169
170             default:
171                 printf("Invalid choice.\n");
172         }
173     }
174
175     return 0;
176 }
177





--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 20

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 30

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 40

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter value to insert: 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 3
Inorder: 10 20 30 40 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 4
Preorder: 10 20 30 40 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 5
Postorder: 50 40 30 20 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 6
Enter value to search: 40
40 found in the BST.

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 2
Enter value to delete: 30

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 3
Inorder: 10 20 40 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 7

                                                                                                                   