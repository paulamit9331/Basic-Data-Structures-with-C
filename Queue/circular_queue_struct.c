#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct queue{
    int items[MAX];
    int rear,front;
}queue;
void enqueue(queue* q,int x){
    if((q->front==0 && q->rear==MAX-1)||(q->front==q->rear+1)){
        printf("Queue is full");
        exit(-1);
    }else{
        if(q->rear==-1){
            q->rear=q->front=0;
        }else if(q->rear==MAX-1){
            q->rear=0;
        }else{
            q->rear++;
        }
        q->items[q->rear]=x;
    }
}
void dequeue(queue* q){
    if(q->front==-1){
        printf("Queue is empty");
        exit(-1);
    }else{
        printf("The deleted item is= %d\n",q->items[q->front]);
        if(q->rear==q->front){
            q->rear=q->front=-1;
        }else if(q->front==MAX-1){
            q->front=0;
        }else{
            q->front++;
        }
    }
}
void display(queue* q){
    if(q->front==-1){
        printf("Queue is empty");
        exit(-1);
    }else{
        int i;
        if(q->front>q->rear){
            printf("front->\t");
            for(i=q->front;i<=MAX-1;i++){
                printf("%d\t",q->items[i]);
            }
            for(i=0;i<=q->rear;i++){
                printf("%d\t",q->items[i]);
            }
            printf("<-rear\n");
        }else{
            printf("front->\t");
            for(i=q->front;i<=q->rear;i++){
                printf("%d\t",q->items[i]);
            }
            printf("<-rear\n");
        }
    }
}
int main(){
    queue q;
    q.rear=q.front=-1;
    int n,num;
    printf("\n Enter 1 to insert an item\n Enter 2 to delete an item\n Enter 3 to display the queue\n Enter 4 to exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d",&num);
                enqueue(&q,num);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid choice\n");

        }
    }
    return 0;
}
