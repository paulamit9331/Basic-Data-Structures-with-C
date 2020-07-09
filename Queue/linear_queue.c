#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;
void enqueue(int item){
    if(rear==MAX-1){
        printf("Queue is full");
        exit(-1);
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=item;
}
void dequeue(){
    if((front==-1)||(front>rear)){
        printf("Queue is empty");
        exit(-1);
    }
    printf("the deleted element is=%d\n",queue[front++]);
}
void display(){
    if((front==-1)||(front>rear)){
        printf("Queue is empty");
        exit(-1);
    }
    int i;
    printf("front->\t");
    for(i=front;i<=rear;i++){
        printf("%d\t",queue[i]);
    }
    printf("<-rear");
    printf("\n");
}
int main(){
    int n,num;
    printf("\n Enter 1 to insert an item\n Enter 2 to delete an item\n Enter 3 to display the queue\n Enter 4 to exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                dequeue();
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
