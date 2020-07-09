#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* lc;
	struct node* rc;
} node;

node* makeNode(int data) {
	node* temp = (node*) malloc(sizeof(node));
	if(temp == NULL)
		exit(-1);

	temp->data = data;
	temp->lc = temp->rc = NULL;
}

node* insert(node* root, int data) {
	if(root == NULL)
		return makeNode(data);
	else if(data <= root->data)
		root->lc = insert(root->lc, data);
	else
		root->rc = insert(root->rc, data);

	return root;
}

node* inorder(node* root) {
	if(root != NULL) {
		inorder(root->lc);
		printf("%d ", root->data);
		inorder(root->rc);
	}
}

int main(int argc, char const *argv[]) {
	node* root = NULL;
	int array[5] = {-1, 3, 8, 0, 2};
	int i;
	for(i = 0; i < 5; ++i)
		root = insert(root, array[i]);

	inorder(root);
	
	return 0;
}