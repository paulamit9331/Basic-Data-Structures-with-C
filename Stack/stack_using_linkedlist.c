#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;
node* top=NULL;
node* push(int item){
    node* temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Memory couldn't be allocated");
        exit(-1);
    }
    temp->data=item;
    temp->link=top;
    top=temp;
}
node* pop(){
    if(top==NULL){
        printf("stack underflow");
        exit(-1);
    }else{
        node* ptr=top;
        top=top->link;
        free(ptr);
    }
}
node* display(){
    node* i=top;
    printf("top->");
    while(i->link!=NULL){
        printf("%d\t",i->data);
        i=i->link;
    }
    printf("%d",i->data);
    printf("\n");
}
int main(){
    int n,num;
    printf("\n Enter 1 to push an item\n Enter 2 to pop an item\n Enter 3 to display the stack\n Enter 4 to exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter a number to push: ");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid choice\n");

        }
    }
    return 0;
}
