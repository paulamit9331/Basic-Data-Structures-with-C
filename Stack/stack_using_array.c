#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],top;
void push(int item){
    if(top==MAX){
        printf("Error: Stack overflow");
        exit(-1);
    }
    top++;
    stack[top]=item;
}
int pop(){
    if(top==-1){
        printf("Error: Stack underflow");
        exit(-1);
    }
    item=stack[top];
    top--;
    return item;
}
void display(){
    int i;
    if(top==-1){
        printf("Error: Stack is empty.");
    }
    printf("top->\t", );
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
int main(){
    int n,num;
    top=-1;
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
                printf("%d\n",pop());
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
