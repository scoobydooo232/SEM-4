#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	struct node* left;
	struct node* right;
	int data;
}node;


node* getNode(int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}



int countN(node* root){
	if(root == NULL)  return 0;

	return (countN(root->left) + countN(root->right) + 1);
}


node* buildTree() {
    int data;
    printf("Enter the root node: ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    node* root = getNode(data);
    node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        node* current = queue[front++];
        printf("Enter left child of %d: ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->left = getNode(data);
            queue[rear++] = current->left;
        }

        printf("Enter right child of %d: ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->right = getNode(data);
            queue[rear++] = current->right;
        }
    }

    return root;
}



int main(){


	node* root = buildTree();

	int height = countN(root);
	printf("the height of the tree is %d ",height);

	return 0;
}