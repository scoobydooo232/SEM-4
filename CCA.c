#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree() {
    int data;
    printf("Enter the root node: ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct TreeNode* root = newNode(data);
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* current = queue[front++];
        printf("Enter left child of %d: ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->left = newNode(data);
            queue[rear++] = current->left;
        }

        printf("Enter right child of %d: ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->right = newNode(data);
            queue[rear++] = current->right;
        }
    }

    return root;
}

struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {
    
    if (root == NULL || root->data == n1 || root->data == n2)
        return root;

    struct TreeNode* leftLCA = findLCA(root->left, n1, n2);
    struct TreeNode* rightLCA = findLCA(root->right, n1, n2);

  
    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}


int isNodePresent(struct TreeNode* root, int n) {
    if (root == NULL)
        return 0;
    if (root->data == n)
        return 1;
    return isNodePresent(root->left, n) || isNodePresent(root->right, n);
}


struct TreeNode* findCCA(struct TreeNode* root, int n1, int n2) {

    if (!isNodePresent(root, n1) || !isNodePresent(root, n2)) {
        printf("One or both nodes are not present in the tree.\n");
        return NULL;
    }

    return findLCA(root, n1, n2);
}


void printResult(struct TreeNode* cca) {
    if (cca != NULL) {
        printf("The Closest Common Ancestor is: %d\n", cca->data);
    } else {
        printf("No Common Ancestor found.\n");
    }
}

int main() {

    struct TreeNode* root = buildTree();

    int n1, n2;
    printf("Enter the first node value (n1): ");
    scanf("%d", &n1);
    printf("Enter the second node value (n2): ");
    scanf("%d", &n2);


    struct TreeNode* cca = findCCA(root, n1, n2);
    printResult(cca);

    return 0;
}
