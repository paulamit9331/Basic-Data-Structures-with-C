#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
	node* prev;
} node;

node* head = NULL;

node* makeNode(int data) {
	node* temp = (node*) malloc(sizeof(node));
	if(temp == NULL) {
		printf("Memory couldn't be allocated\n");
		exit(-1);
	}
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
}

void insertBegin(int data) {
	node *temp = makeNode(data);
	temp->next = head;
	if(head != NULL)
		head->prev = temp;
	head = temp;
}

void insertEnd(int data) {
	node* temp = makeNode(data);
	if(head == NULL)
		head = temp;
	else {
		node* ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
		temp->prev = ptr;
	}
}

void insertAny(int data, int pos) {
	if(pos > size()) {
		printf("Invalid Position\n");
		return;
	}
	node* temp = makeNode(data);
	if(pos == 0)
		insertBegin(data);
	else if(pos == size())
		insertEnd();
	else {
		node* ptr = head;
		for(int i = 0; i < pos - 1; i++)
			ptr = ptr->next;
		temp->next = ptr-next;
		ptr->next->prev = temp;
		ptr->next = temp;
		temp->prev = ptr;
	}
}

void deleteBegin() {
	if(head == NULL) {
		printf("Empty List\n");
		return;
	}
	node* temp = head;
	head = head->next;
	free(temp);
	temp = NULL;
}

void deleteEnd() {

}

void deleteAny() {

}

int main(int argc, char const *argv[]) {
	
	return 0;
}