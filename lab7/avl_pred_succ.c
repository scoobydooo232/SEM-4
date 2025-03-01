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
    
    // Perform rotation
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

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* successor(struct Node* root, int key) {
    struct Node* current = root;
    struct Node* succ = NULL;

    while (current != NULL) {
        if (key < current->key) {
            succ = current;
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            if (current->right != NULL) {
                succ = minValueNode(current->right);
            }
            break;
        }
    }
    return succ;
}

struct Node* predecessor(struct Node* root, int key) {
    struct Node* current = root;
    struct Node* pred = NULL;

    while (current != NULL) {
        if (key > current->key) {
            pred = current;
            current = current->right;
        } else if (key < current->key) {
            current = current->left;
        } else {
            if (current->left != NULL) {
                pred = minValueNode(current->left);
            }
            break;
        }
    }
    return pred;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);

    int key = 20;
    struct Node* succ = successor(root, key);
    struct Node* pred = predecessor(root, key);

    printf("In-order traversal of the AVL tree: ");
    inOrder(root);
    printf("\n");

    if (succ)
        printf("Successor of %d: %d\n", key, succ->key);
    else
        printf("No successor for %d\n", key);

    if (pred)
        printf("Predecessor of %d: %d\n", key, pred->key);
    else
        printf("No predecessor for %d\n", key);

    return 0;
}
