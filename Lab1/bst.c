#include<stdio.h>
#include<stdlib.h> 

typedef struct node {
    struct node* lchild;
    struct node* rchild;
    int data;
} node;


node* newNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}


int search(node* root, int key) {
    if (root != NULL) {
        if (root->data == key) {
            printf("Found\n");
            return 1;
        }

        if (key < root->data)
            return search(root->lchild, key);
        else
            return search(root->rchild, key);
    }
    return -1;
}


node* insert(node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->data)
        root->lchild = insert(root->lchild, key);
    else if (key > root->data)
        root->rchild = insert(root->rchild, key);

    return root;
}


void inorder(node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(node* root){
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(node* root){
	if(root != NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ", root->data);
	}
}

int main() {
    node* root = newNode(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int result = search(root, 60);
    if (result == -1) {
        printf("Inserting 65 as it was not found.\n");
        root = insert(root, 65);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");


    return 0;
}
