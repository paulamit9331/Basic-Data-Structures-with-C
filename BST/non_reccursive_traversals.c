#include <stdio.h>
#include <stdlib.h>

// node definition
typedef struct node {
	int data;
	struct node* lc;
	struct node* rc;
} node;

// write your own stack implementation which can hold address of the node structure
// and define push(), pop(), isEmpty()
#define MAX 100
typedef struct Stack {
	node* store[MAX];
	int top = -1;
} Stack;

void push(Stack *st, node *add) {
	if(top == MAX - 1)
		return;
	st->store[++st->top] = add;
}

node* pop(Stack *st) {
	if(top == -1)
		return;
	node *add = st->store[st->top--];
	return add;
}

int isEmpty(Stack *st) {
	if(top == -1)
		return 0;
	return 1;
}

typedef struct node {
	int data;
	struct node* lc;
	struct node* rc;
} node;
//End of stack

node* createNode(int data) {
	node* temp = (node*) malloc(sizeof(node));
	if(temp == NULL) {
		printf("Memory couldn't be allocated\n");
		exit(-1);
	}
	temp->data = data;
	temp->lc = temp->rc = NULL;

	return temp;
}

node* insertion(node* root, int data) {
	if(root == NULL)
		return createNode(data);
	if(data < root->data)
		root->lc = insertion(root->lc, data);
	else if(data > root->data)
		root->rc = insertion(root->rc, data);

	return root;
}

void preOrder(node *root) {
	struct Stack st;
	if(root || !isEmpty(st)) {
		if(root != NULL) {
			printf("%d ", root->data);
			push(st, root);
			root = root->lc;
		
		} else {
			root = pop(st);
			root = root->rc;
		}
	}
}

void inOrder(node *root) {
	struct Stack st;
	if(root || !isEmpty(st)) {
		if(root != NULL) {
			push(st, root);
			root = root->lc;
		
		} else {
			root = pop(st);
			printf("%d\n", root->data);
			root = root->rc;
		}
	}
}

void postOrder(node *root) {
	struct stack st;
	if(root || !isEmpty(st)) {
		if(root != NULL) {
			push(st, root);
			root = root->lc;
		
		} else {
			node *temp = pop(st);
			if(temp->rc == NULL)
				printf("%d ", root->data);
			root = temp;
			root = root->rc;
		}
	}
}

int main(int argc, char const *argv[]) {
	int choice, data;
	int quit = 0;
	node* root = NULL;

	printf("Enter 1 to insert a node\n");
	printf("Enter 2 to get iterarive inorder traversal of the BST\n");
	printf("Enter 3 to get iterarive preorder traversal of the BST\n");
	printf("Enter 4 to get iterarive postorder traversal of the BST\n");
	printf("Enter 5 to quit\n");
	printf("=========================================================\n");

	while(!quit) {
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				printf("Enter an item to insert: ");
				scanf("%d", &data);
				root = insertion(root, data);

				break;
			}

			case 2:	inorder(root);		break;

			case 3:	preorder(root);		break;

			case 4:	postorder(root);	break;

			case 5:	quit = 1;			break;

			default:	printf("Enter a valid choice\n");
		}
	}
	return 0;
}