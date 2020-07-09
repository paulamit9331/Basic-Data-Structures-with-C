#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

node* head = NULL;

void insertBegin(int data) {
	node* temp = (node*) malloc(sizeof(node));
	if(temp == NULL) {
		printf("Memory couldn't be allocated\n");
		exit(-1);
	}
	temp->data = data;
	temp->next = head;
	head = temp;
}

void insertEnd(int data) {
	node* temp = (node*) malloc(sizeof(node));
	if(temp == NULL) {
		printf("Memory couldn't be allocated\n");
		exit(-1);
	}
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else {
		node* ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = temp;
	}
}

void insertAny(int data, int pos) {
	if(pos > size()) {
		printf("Invalid Position\n");
		exit(-1);
	}

	if(pos == 0 || head == NULL)
		insertBegin(data);
	else if(pos == size())
		insertEnd(data);
	else {
		node* temp = (node*) malloc(sizeof(node));
		if(temp == NULL) {
			printf("Memory couldn't be allocated\n");
			exit(-1);
		}
		temp->data = data;
		int i;
		node* ptr = head;
		for(i = 0; i < pos - 1; i++)
			ptr = ptr->next;

		temp->next = ptr->next;
		ptr->next = temp;
	}
}

void deleteBegin() {
	if(head == NULL) {
		printf("Linked List is Empty\n");
		exit(-1);
	}
	node* temp = head;
	head = head->next;
	free(temp);
}

void deleteEnd() {
	if(head == NULL) {
		printf("Linked List is Empty\n");
		exit(-1);
	}
	if(head->next == NULL)
		head = NULL;
	else {
		node* ptr = head;
		while(ptr->next->next != NULL)
			ptr = ptr->next;

		free(ptr->next);
		ptr->next = NULL;
	}
}

void deleteAny(int pos) {
	if(head == NULL || pos > size() - 1) {
		printf("Invalid\n");
		exit(-1);
	}
	if(pos == 0)
		deleteBegin();
	else if(pos == size() - 1)
		deleteEnd();
	else {
		int i;
		node* ptr = head;
		for(i = 0; i < size() - 1; i++)
			ptr = ptr->next;

		node temp = ptr->next;
		ptr->next = temp->next;
		free(temp);
	}
}

void reverse() {
	if(head == NULL) {
		printf("Linked List is Empty\n");
		exit(-1);
	}
	node* temp = head, *ptr=NULL, *nextnode;
    while(temp!=NULL){
        nextnode=temp->next;
        temp->next=ptr;
        ptr=temp;
        temp=nextnode;
    }
    head=ptr;
}

void search(int data) {
	if(head == NULL)
		exit(-1);
	int count = -1;
	node* ptr = head;
	while(ptr != NULL && ptr->data != data) {
		ptr == ptr->next;
		count++;
	}
	if(ptr != NULL)
		printf("Element %d is present in %d node\n", data, count);
	else
		printf("Element is not present\n");
}

void findMiddle() {
	if(head == NULL)
		return;
	node* p, *q;
	p = q = head;
	while(p != NULL && p->next != NULL) {
		p = p->next->next;
		q = q->next;
	}
	printf("Middle Element: %d\n", q->data);
}

void checkLoop() {
	if(head == NULL)
		return;
	node* p, *q;
	p = q = head;
	while(p != NULL && p->next != NULL && p != q) {
		p = p->next->next;
		q = q->next;
	}
	if(p == q)
		printf("Loop Starts at %d node\n", p->data);
	else
		printf("Loop is not present\n");
}

void display() {
	if(head == NULL)
		return 0;
	else {
		printf("head-> ");
		node* ptr = head;
		while(ptr != NULL) {
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
		printf(" <-NULL\n");
	}
}

int size() {
	if(head == NULL)
		return 0;
	else {
		int count = 0;
		node* ptr = head;
		while(ptr != NULL) {
			ptr = ptr->next;
			count++;
		}
		return count;
	}
}

int main(int argc, char const *argv[]) {
	int choice = 0;
	int flag = 0;
	int n, pos;

	printf("Enter 1 to insert at begin\n");
	printf("Enter 2 to insert at end\n");
	printf("Enter 3 to insert at any position\n");
	printf("Enter 4 to delete at begin\n");
	printf("Enter 5 to delete at end\n");
	printf("Enter 6 to delete at any position\n");
	printf("Enter 7 to reverse the Linked List\n");
	printf("Enter 8 to get the size of the Linked List\n");
	printf("Enter 9 to display the Linked List\n");
	printf("Enter 10 to exit\n");
	printf("==========================================================\n");

	while(!flag) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	{
				printf("Enter a number to insert: ");
				scanf("%d", &n);
				insertBegin(n);
				break;
			}

			case 2: {
				printf("Enter a number to insert: ");
				scanf("%d", &n);
				insertEnd(n);
				break;
			}

			case 3: {
				printf("Enter a number  and a position to insert: ");
				scanf("%d%d", &n, &pos);
				insertAny(n, pos);
										break;
			}

			case 4:	deleteBegin();		break;

			case 5:	deleteEnd();		break;

			case 6:	{
				printf("Enter a position to delete: ");
				scanf("%d", &pos);
				deleteAny(pos);
										break;
			}

			case 7:	reverse();			break;

			case 8:	printf("size = %d", size());		break;

			case 9:	display();			break;

			case 10:flag = 1;			break;

			default:	printf("Enter a valid choice\n");
		}
	}
	return 0;
}