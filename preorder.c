  1 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct Node {
  5     int data;
  6     struct Node *left, *right;
  7 };
  8
  9 struct Node* createNode(int data) {
 10     struct Node* newNode = malloc(sizeof(struct Node));
 11
 12     if (newNode == NULL) {
 13         printf("Memory allocation failed!\n");
 14         exit(1);
 15     }
 16
 17     newNode->data = data;
 18     newNode->left = NULL;
 19     newNode->right = NULL;
 20
 21     return newNode;
 22 }
 23
 24 struct Node* insert(struct Node* root, int data) {
 25     if (root == NULL)
 26         return createNode(data);
 27
 28     if (data < root->data)
 29         root->left = insert(root->left, data);
 30     else if (data > root->data)
 31         root->right = insert(root->right, data);
 32
 33     return root;
 34 }
 35
 36 void preorder(struct Node* root) {
 37     if (root != NULL) {
 38         printf("%d ", root->data);
 39         preorder(root->left);
 40         preorder(root->right);
 41     }
 42 }
 43
 44 struct Node* search(struct Node* root, int key) {
 45     if (root == NULL || root->data == key)
 46         return root;
 47
 48     struct Node* result = search(root->left, key);
 49
 50     if (result != NULL)
 51         return result;
 52
 53     return search(root->right, key);
 54 }
 55
 56 struct Node* findMin(struct Node* root) {
 57     while (root != NULL && root->left != NULL)
 58         root = root->left;
 59
 60     return root;
 61 }
 62
 63 struct Node* deleteNode(struct Node* root, int key) {
 64     if (root == NULL)
 65         return NULL;
 66
 67     if (key < root->data)
 68         root->left = deleteNode(root->left, key);
 69     else if (key > root->data)
 70         root->right = deleteNode(root->right, key);
 71     else {
 72         if (root->left == NULL) {
 73             struct Node* temp = root->right;
 74             free(root);
 75             return temp;
 76         }
 77
 78         if (root->right == NULL) {
 79             struct Node* temp = root->left;
 80             free(root);
 81             return temp;
 82         }
 83
 84         struct Node* temp = findMin(root->right);
 85         root->data = temp->data;
 86         root->right = deleteNode(root->right, temp->data);
 87     }
 88
 89     return root;
 90 }
 91
 92 void freeTree(struct Node* root) {
 93     if (root != NULL) {
 94         freeTree(root->left);
 95         freeTree(root->right);
 96         free(root);
 97     }
 98 }
 99
100 int main() {
101     struct Node* root = NULL;
102     int choice, n, data, i;
103
104     do {
105         printf("\n\n1. Create BST");
106         printf("\n2. Preorder Traversal");
107         printf("\n3. Search");
108         printf("\n4. Delete");
109         printf("\n5. Exit");
110         printf("\nEnter your choice: ");
111         scanf("%d", &choice);
112
113         switch (choice) {
114             case 1:
115                 printf("Enter number of nodes: ");
116                 scanf("%d", &n);
117
118                 for (i = 0; i < n; i++) {
119                     printf("Enter data: ");
120                     scanf("%d", &data);
121                     root = insert(root, data);
122                 }
123                 break;
124
125             case 2:
126                 printf("Preorder Traversal: ");
127                 preorder(root);
128                 printf("\n");
129                 break;
130
131             case 3:
132                 printf("Enter value to search: ");
133                 scanf("%d", &data);
134
135                 if (search(root, data) != NULL)
136                     printf("Element found!\n");
137                 else
138                     printf("Element not found!\n");
139                 break;
140
141             case 4:
142                 printf("Enter value to delete: ");
143                 scanf("%d", &data);
144
145                 if (search(root, data) != NULL) {
146                     root = deleteNode(root, data);
147                     printf("Element deleted successfully!\n");
148                 } else {
149                     printf("Element not found!\n");
150                 }
151                 break;
152
153             case 5:
154                 printf("Exiting...\n");
155                 break;
156
157             default:
158                 printf("Invalid choice!\n");
159         }
160
161     } while (choice != 5);
162
163     freeTree(root);
164
165     return 0;
166 }
 

1. Create BST
2. Preorder Traversal
3. Search
4. Delete
5. Exit
Enter your choice: 1
Enter number of nodes: 3
Enter data: 4
Enter data: 5
Enter data: 6


1. Create BST
2. Preorder Traversal
3. Search
4. Delete
5. Exit
Enter your choice: 1
Enter number of nodes: 3
Enter data: 5
Enter data: 6
Enter data: 7


1. Create BST
2. Preorder Traversal
3. Search
4. Delete
5. Exit
Enter your choice: 2
Preorder Traversal: 4 5 6 7
1. Create BST
2. Preorder Traversal
3. Search
4. Delete
5. Exit
Enter your choice: 3
Enter value to search: 4
Element found!


1. Create BST
2. Preorder Traversal
3. Search
4. Delete
5. Exit
Enter your choice: 4
Enter value to delete: 4
Element deleted successfully!


1. Create BST
2. Preorder Traversal
3. Search
4. Delete
5. Exit
Enter your choice: 5
Exiting...
                                                 