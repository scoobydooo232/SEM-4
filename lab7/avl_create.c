#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;

   
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

struct Node* insert(struct Node* root, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    if (root == NULL) {
        return newNode;
    }

    struct Node* parent = NULL;
    struct Node* current = root;
    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return root; 
    }

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    while (parent != NULL) {
        parent->height = 1 + (height(parent->left) > height(parent->right) ? height(parent->left) : height(parent->right));
        
        int balance = getBalance(parent);

        if (balance > 1 && key < parent->left->key)
            parent = rightRotate(parent);

        else if (balance < -1 && key > parent->right->key)
            parent = leftRotate(parent);

        else if (balance > 1 && key > parent->left->key) {
            parent->left = leftRotate(parent->left);
            parent = rightRotate(parent);
        }

        else if (balance < -1 && key < parent->right->key) {
            parent->right = rightRotate(parent->right);
            parent = leftRotate(parent);
        }

        if (parent->left == newNode)
            newNode = parent->left;
        else if (parent->right == newNode)
            newNode = parent->right;

        parent = parent->left ? parent->left : parent->right;
    }

    return parent;
}

void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);

    printf("In-order traversal of the AVL tree: ");
    inOrder(root);

    return 0;
}
