#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
} node;

node* head = NULL;

void display() {
	if(head == NULL)
		printf("Empty List\n");
	else {
		node* ptr = head;
		printf("head-> ");
		do {
			printf("%d-> ", ptr->data);
			ptr = ptr->next;
		} while(ptr != head);
	}
}

node* makeNode(int data) {
	node* temp = (node*) malloc(sizeof(node));
	if(temp == NULL) {
		printf("Memory couldn't be allocated\n");
		exit(-1);
	}
	temp->data = data;
	temp->next = temp;
}

void insertBeginOrEnd(int data) {
	node* temp = makeNode(data);
	if(head == NULL)
		head = temp;
	else {
		temp->next = head;
		node* ptr = head;
		while(ptr->next != head)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

void insertAny(int data, int pos) {
	if(pos > size())
		printf("Invalid Position\n");
	else if(pos == 0 || pos == size())
		insertBeginOrEnd(data);
	else {
		node* temp = makeNode(data);
		node* ptr = head;
		for(int i = 0; i < pos - 1; i++)
			ptr = ptr->next;
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

void deleteBeginOrEnd() {
	node* ptr = head;
	while(ptr->next != head)
		ptr = ptr->next;
	node* temp = ptr->next;
	head = head->next;
	free(temp);
	temp = NULL;
}

void deleteAny(int pos) {
	if(pos > size() - 1)
		printf("Invalid Position\n");
	else if(pos == 0)
		deleteBeginOrEnd();
	else {
		node* ptr = head;
		for(int i = 0; i < pos - 1; i++)
			ptr = ptr->next;
		node* temp = ptr->next;
		ptr->next = temp->next;
		free(temp);
		temp = NULL;
	}
}

int size() {
	if(head == NULL)
		return 0;
	else {
		int count = 0;
		node* ptr = head;
		do {
			count++;
			ptr = ptr->next;
		} while(ptr != head);

		return count;
	}
}

int main(int argc, char const *argv[]) {
	int choice = 0;
	int flag = 0;
	int n, pos;

	printf("Enter 1 to insert at begin or end\n");
	printf("Enter 2 to insert at any position\n");
	printf("Enter 3 to delete at begin or end\n");
	printf("Enter 4 to delete at any position\n");
	printf("Enter 5 to get the size of the Linked List\n");
	printf("Enter 6 to display the Linked List\n");
	printf("Enter 7 to exit\n");
	printf("==========================================================\n");

	while(!flag) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	{
				printf("Enter a number to insert: ");
				scanf("%d", &n);
				insertBeginOrEnd(n);
				break;
			}

			case 2: {
				printf("Enter a number  and a position to insert: ");
				scanf("%d%d", &n, &pos);
				insertAny(n, pos);
										break;
			}

			case 3:	deleteBeginOrEnd();	break;

			case 4:	{
				printf("Enter a position to delete: ");
				scanf("%d", &pos);
				deleteAny(pos);
										break;
			}

			case 5:	printf("size = %d", size());		break;

			case 6:	display();			break;

			case 7:	flag = 1;			break;

			default:	printf("Enter a valid choice\n");
		}
	}
	return 0;
}