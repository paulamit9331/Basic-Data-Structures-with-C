#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(int item){
    if(top==MAX){
        printf("Error: Stack overflow");
        exit(-1);
    }
    stack[++top]=item;
}
char pop(){
    if(top==-1){
        printf("Error: Stack underflow");
        exit(-1);
    }
    return stack[top--];
}
void rev_string(char a[]){
    int i=0;
    while(a[i]!='\0'){
        push(a[i++]);
    }
    i=0;
    while(top!=-1){
        a[i++]=pop();
    }
}
int main(){
    char c[MAX],i=0;
    printf("Enter a string:\n");
    gets(c);
    rev_string(c);
    printf("The new string is:\n");
    while(c[i]!='\0'){
        printf("%c",c[i++]);
    }
    return 0;
}