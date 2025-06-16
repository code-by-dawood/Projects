#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree (BST)
typedef struct sll {
    int data;          // Stores the value of the node
    struct sll *left;  // Pointer to the left child
    struct sll *right; // Pointer to the right child
} Node;

// Function to create a new node with the given data
Node* createnode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for new node
    newNode->data = data;  // Assign data to the node
    newNode->left = NULL;  // Initialize left child as NULL
    newNode->right = NULL; // Initialize right child as NULL
    return newNode;        // Return the created node
}

// Function to insert a new node in the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {  // If tree is empty, create a new node as root
        return createnode(data);
    }
    else if (data < root->data) {  // If data is smaller, insert into left subtree
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {  // If data is larger, insert into right subtree
        root->right = insert(root->right, data);
    }
    return root;  // Return the unchanged root node
}

// Function to perform an inorder traversal (Left, Root, Right)
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);    // Visit left subtree
        printf("%d ", root->data); // Print node data
        inorder(root->right);   // Visit right subtree
    }
}

// Function to perform a preorder traversal (Root, Left, Right)
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print node data
        preorder(root->left);    // Visit left subtree
        preorder(root->right);   // Visit right subtree
    }
}

// Function to perform a postorder traversal (Left, Right, Root)
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);  // Visit left subtree
        postorder(root->right); // Visit right subtree
        printf("%d ", root->data); // Print node data
    }
}

int main() {
    Node* root = NULL;  // Initialize root node of BST
    int size;

    // Get the number of elements from the user
    printf("Enter size: ");
    scanf("%d", &size);

    // Allocate memory for the array to store input elements
    int *arr = (int*)malloc(size * sizeof(int));

    // Read elements from the user and insert them into the BST
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);  // Read element
        root = insert(root, arr[i]); // Insert element into BST
    }

    // Perform and display tree traversals
    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0; // Indicate successful execution
}
