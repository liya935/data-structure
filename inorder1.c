 #include <stdio.h>
  2 #include <stdlib.h>
  3
  4 struct Node {
  5     int data;
  6     struct Node *left, *right;
  7 };
  8
  9 struct Node* newNode(int key) {
 10     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 11     node->data = key;
 12     node->left = node->right = NULL;
 13     return node;
 14 }
 15
 16 struct Node* insert(struct Node* root, int key) {
 17     if (root == NULL)
 18         return newNode(key);
 19
 20     if (key < root->data)
 21         root->left = insert(root->left, key);
 22     else if (key > root->data)
 23         root->right = insert(root->right, key);
 24     else
 25         printf("%d already exists.\n", key);
 26
 27     return root;
 28 }
 29
 30 struct Node* minNode(struct Node* root) {
 31     while (root->left != NULL)
 32         root = root->left;
 33
 34     return root;
 35 }
 36
 37 struct Node* deleteNode(struct Node* root, int key) {
 38     if (root == NULL) {
 39         printf("%d not found.\n", key);
 40         return NULL;
 41     }
 42
 43     if (key < root->data)
 44         root->left = deleteNode(root->left, key);
 45     else if (key > root->data)
 46         root->right = deleteNode(root->right, key);
 47     else {
 48         if (root->left == NULL) {
 49             struct Node* temp = root->right;
 50             free(root);
 51             return temp;
 52         }
 53
 54         if (root->right == NULL) {
 55             struct Node* temp = root->left;
 56             free(root);
 57             return temp;
 58         }
 59
 60         struct Node* succ = minNode(root->right);
 61         root->data = succ->data;
 62         root->right = deleteNode(root->right, succ->data);
 63     }
 64
 65     return root;
 66 }
 67
 68 void inorder(struct Node* root) {
 69     if (root == NULL)
 70         return;
 71
 72     inorder(root->left);
 73     printf("%d ", root->data);
 74     inorder(root->right);
 75 }
 76
 77 int main() {
 78     struct Node* root = NULL;
 79     int choice, value;
 80
 81     while (1) {
 82         printf("\n1. Insert\n");
 83         printf("2. Delete\n");
 84         printf("3. Inorder\n");
 85         printf("4. Exit\n");
 86
 87         printf("Enter choice: ");
 88         scanf("%d", &choice);
 89
 90         switch (choice) {
 91             case 1:
 92                 printf("Enter value to insert: ");
 93                 scanf("%d", &value);
 94                 root = insert(root, value);
 95                 break;
 96
 97             case 2:
 98                 printf("Enter value to delete: ");
 99                 scanf("%d", &value);
100                 root = deleteNode(root, value);
101                 break;
102
103             case 3:
104                 printf("Inorder: ");
105                 inorder(root);
106                 printf("\n");
107                 break;
108
109             case 4:
110                 return 0;
111
112             default:
113                 printf("Invalid choice.\n");
114         }
115     }
116
117     return 0;
118 }
102
103             case 3:
104                 printf("Inorder: ");
105                 inorder(root);
106                 printf("\n");
107                 break;
108
109             case 4:
110                 return 0;
111
112             default:
113                 printf("Invalid choice.\n");
114         }
115     }
116
117     return 0;
118 }



1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 1
Enter value to insert: 50

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 1
Enter value to insert: 30

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 1
Enter value to insert: 70

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 1
Enter value to insert: 20

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 60
Invalid choice.

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 1
Enter value to insert: 80

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 3
Inorder: 20 30 50 70 80

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 2
Enter value to delete: 30

1. Insert
2. Delete
3. Inorder
4. Exit
Enter choice: 4
                                 