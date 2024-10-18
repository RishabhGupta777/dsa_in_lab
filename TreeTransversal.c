#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

int size(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);  // Corrected printf syntax
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);  // Corrected printf syntax
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);  // Corrected printf syntax
}

struct Node* createNode(int value) {     //create a fn which return struct Node type newnode
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create nodes
    struct Node* a = createNode(1);
    struct Node* b = createNode(2);
    struct Node* c = createNode(3);
    struct Node* d = createNode(4);
    struct Node* e = createNode(5);
    struct Node* f = createNode(6);
    struct Node* g = createNode(7);

    // Construct the binary tree
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    printf("Size of BT is: %d\n", size(a));  // Corrected printf syntax
    printf("Preorder: ");
    preorder(a);    
    printf("\nInorder: ");
    inorder(a);     
    printf("\nPostorder: ");
    postorder(a);
    printf("\n");

    // Free allocated memory (important in a real application)
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);

    return 0;
}
