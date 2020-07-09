#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* lc;
	struct node* rc;
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

node* search(node* root, int data) {
	if(root == NULL || root->data == data)
		return root;
	else if(data < root->data)
		return search(root->lc, data);
	else
		return search(root->rc, data);
}

node* minValue(node* root) {
	node* ptr = root;
	while(ptr->lc != NULL)
		ptr = ptr->lc;
	return ptr;
}

node* deletion(node* root, int data) {
	if(search(root, data) == NULL)
		printf("Item is not Present\n");
	else {
		if(root == NULL)
			return root;
		else if(data < root->data)
			root->lc = deletion(root->lc, data);
		else if(data > root->data)
			root->rc = deletion(root->rc, data);
		else {											// we found the data
			if(root->lc == NULL && root->rc == NULL) {	// case 1: if no child
				free(root);
				root = NULL;
			} else if(root->lc == NULL) {				// case 2a: if only right child is present
				node* temp = root;
				root = root->rc;
				free(temp);
			} else if(root->rc == NULL) {				// case 2b: if only left child is present
				node* temp = root;
				root = root->lc;
				free(temp);
			} else {									// case 3: if only both child is present
				node* temp = minValue(root->rc);
				root->data = temp->data;
				root->rc = deletion(root->rc, temp->data);
			}
		}
	}
	return root;
}

node* inorderSuccessor(node* root, int data) {
	node* temp = search(root, data);
	if(temp == NULL)				// if data is not present
		return NULL;
	
	else if(temp->rc != NULL)		// case 1: if right child is present find minimum in the right child
		return minValue(temp->rc);
	
	else {							// case 2: if right child is not present go to left and find deepest ancestor
		node* successor = NULL;
		node* ancestor = root;
		while(ancestor != temp) {
			if(temp->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->lc;
			} else {
				ancestor = ancestor->rc;
			}
		}
		return successor;
	}
}

node* inorder(node* root) {
	if(root != NULL) {
		inorder(root->lc);
		printf("%d ", root->data);
		inorder(root->rc);
	}
}

node* preorder(node* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		preorder(root->lc);
		preorder(root->rc);
	}
}

node* postorder(node* root) {
	if(root != NULL) {
		postorder(root->lc);
		postorder(root->rc);
		printf("%d ", root->data);
	}
}

int main(int argc, char const *argv[]) {
	int choice, data;
	int quit = 0;
	node* root = NULL;

	printf("Enter 1 to insert a node\n");
	printf("Enter 2 to delete a node\n");
	printf("Enter 3 to search a node\n");
	printf("Enter 4 to get inorder successor of a given node\n");
	printf("Enter 5 to get inorder traversal of the BST\n");
	printf("Enter 6 to get preorder traversal of the BST\n");
	printf("Enter 7 to get postorder traversal of the BST\n");
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

			case 2: {
				printf("Enter an item to delete: ");
				scanf("%d", &data);
				root = deletion(root, data);

				break;
			}

			case 3: {
				printf("Enter an item to search: ");
				scanf("%d", &data);
				if(search(root, data) == NULL)
					printf("Item is not present in the Tree\n");
				else
					printf("Item found\n");

				break;
			}

			case 4:	{
				printf("Enter an item to find its inorder successor: ");
				scanf("%d", &data);
				node* temp = inorderSuccessor(root, data);
				if(temp == NULL)
					printf("No successor for the given node\n");
				else
					printf("Inorder successor of %d is = %d\n", data, temp->data);

				break;
			}

			case 5:	inorder(root);		break;

			case 6:	preorder(root);		break;

			case 7:	postorder(root);	break;

			case 8:	quit = 1;			break;

			default:	printf("Enter a valid choice\n");
		}
	}
	return 0;
}