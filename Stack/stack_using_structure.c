#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct stack{
    int item[MAX];
    int top;
}stack;
stack p;
stack* s=&p;
void push(int item){
    if(s->top==MAX-1){
        printf("Error: Stack overflow");
        exit(-1);
    }
    s->top++;
    s->item[s->top]=item;
}
void pop(){
    if(s->top==-1){
        printf("Error: Stack underflow");
        exit(-1);
    }
    printf("The popped item is= %d\n",s->item[s->top]);
    s->top--;
}
void display(){
    int i;
    if(s->top==-1){
        printf("Error: Stack underflow");
        exit(-1);
    }
    for(i=0;i<=s->top;i++){
        printf("%d\t",s->item[i]);
    }
    printf("\n");
}
int main(){
    //stack p,*s;
    //s=&p;
    int n,num;
    s->top=-1;
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
