#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *lc;
	struct node *rc;
} node;

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

int countNode(node *root) {
	int x, y;
	if(root != NULL) {
		x = countNode(root->lc);	// count nodes on left subtree
		y = countNode(root->rc);	// count nodes on right subtree

		return 1 + x + y;			// count one for the current node
	}
	return 0;
}

int sumOfAllNode(node *root) {
	int x, y;
	if(root != NULL) {
		x = sumOfAllNode(root->lc);				// count nodes on left subtree
		y = sumOfAllNode(root->rc);				// count nodes on right subtree

		return root->data + x + y;				// count one if current node has one child i.e. one of them are not null
	}
	return 0;
}

int heightOfTree(node *root) {
	int x, y;
	if(root != NULL) {
		x = heightOfTree(root->lc);				// count height of left subtree
		y = heightOfTree(root->rc);				// count height of right subtree

		if(x > y)								// greater height will be the height of the tree
			return x + 1;
		else
			return y + 1;
	}
	return 0;
}

int countSecondOrderedNode(node *root) {
	int x, y;
	if(root != NULL) {
		x = countSecondOrderedNode(root->lc);	// count nodes on left subtree
		y = countSecondOrderedNode(root->rc);	// count nodes on right subtree

		if(root->lc & root->rc)
			return 1 + x + y;					// count one if current node has two child i.e. both are not null
	}
	return 0;
}

int countFirstOrderedNode(node *root) {
	int x, y;
	if(root != NULL) {
		x = countFirstOrderedNode(root->lc);	// count nodes on left subtree
		y = countFirstOrderedNode(root->rc);	// count nodes on right subtree

		if(root->lc || root->rc)
			return 1 + x + y;					// count one if current node has one child i.e. one of them are not null
	}
	return 0;
}

int countLeafNode(node *root) {
	int x, y;
	if(root != NULL) {
		x = countLeafNode(root->lc);			// count nodes on left subtree
		y = countLeafNode(root->rc);			// count nodes on right subtree

		if(!root->lc && !root->rc)
			return 1 + x + y;					// count one if current node has zero child i.e. both of them are null
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	int choice, data;
	int quit = 0;
	node* root = NULL;

	printf("Enter 1 to insert a node\n");
	printf("Enter 2 to count number if nodes\n");
	printf("Enter 3 to sum of all nodes\n");
	printf("Enter 4 to count height of the tree\n");
	printf("Enter 5 to count second ordered nodes of the tree\n");
	printf("Enter 6 to count first ordered nodes of the tree\n");
	printf("Enter 7 to count leaf nodes of the tree\n");
	printf("Enter 8 to quit\n");
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

			case 2:	printf("%d\n", countNode(root));				break;

			case 3:	printf("%d\n", sumOfAllNode(root));				break;

			case 4:	printf("%d\n", heightOfTree(root));				break;

			case 5:	printf("%d\n", countSecondOrderedNode(root));	break;

			case 6:	printf("%d\n", countFirstOrderedNode(root));	break;

			case 7:	printf("%d\n", countLeafNode(root));			break;

			case 8:	quit = 1;	break;

			default	:	printf("Enter a valid choice\n");
		}
	}
	return 0;
}