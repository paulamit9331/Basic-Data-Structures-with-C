#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX],front=-1,rear=-1;
void enqueue(int item){
    if((front==0 && rear==MAX-1)||(front==rear+1)){
        printf("Queue is full");
        exit(-1)  
    }else{
        if(rear==-1){
            rear=front=0;
        }else if(rear==MAX-1){
            rear=0;
        }else{
            rear++;
        }
        queue[rear]=item;
    }
}
void dequeue(){
    if(front==-1){
        printf("Queue is empty");
        exit(-1);
    }else{
        printf("The deleted item is= %d\n",queue[front]);
        if(rear==front){
            rear=front=-1;
        }else if(front==MAX-1){
            front=0;
        }else{
            front++;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty");
        exit(-1);
    }else{
        int i;
        if(front>rear){
            printf("front->\t");
            for(i=front;i<=MAX-1;i++){
                printf("%d\t",queue[i]);
            }
            for(i=0;i<=rear;i++){
                printf("%d\t",queue[i]);
            }
            printf("<-rear\n");
        }else{
            printf("front->\t");
            for(i=front;i<=rear;i++){
                printf("%d\t",queue[i]);
            }
            printf("<-rear\n");
        }
    }
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
