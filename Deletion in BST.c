#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

Node* successor(Node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* delNode(Node* root, int x) {
    if (root == NULL)
        return root;

    if (x < root->data) {
        root->left = delNode(root->left, x);
    } else if (x > root->data) {
        root->right = delNode(root->right, x);
    } else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* succ = successor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

int main() {
    Node* root = create(10);
    root->left = create(5);
    root->right = create(15);
    root->right->left = create(12);
    root->right->right = create(18);

    int x = 15;
    root = delNode(root, x);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
