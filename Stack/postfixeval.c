#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 100
int stack[MAX];
int top=-1;
push(int item){
	if(top==MAX-1){
		printf("stack overflow\n");
		exit(-1);
	}
	stack[++top]=item;
}
int pop(){
	if(top==-1){
		printf("stack underflow\n");
		exit(-1);
	}
	return stack[top--];
}
int is_operand(char c){
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return 1;
	else
		return 0;
}
int evaluation(int a,int b,char s){
	switch(s){
		case '+':
			return (a+b);
			break;
		case '-':
			return (a-b);
			break;
		case '*':
			return (a*b);
			break;
		case '/':
			return (a/b);
			break;
		case '^':
			return pow(a,b);
			break;
	}
}
int postfix_value(char postfix[]){
	int op2,op1,result;
	int i=0,m;
	char c;
	while(postfix[i]!='\0'){
		c=postfix[i++];
		if(is_operand(c)==1){
			printf("Enter the value of %c: ",c);
			scanf("%d",&m);
			push(m);	
		}else{
			op1=pop();
			op2=pop();
			result=evaluation(op1,op2,c);
			push(result);
		}
		//i++;
	}
	return pop();
}
int main(){
	char postfix[MAX];
	int i,n,sol;
	printf("Enter the expression:\n");
	gets(postfix);
	sol=postfix_value(postfix);
	printf("The solution is: %d\n",sol);
	return 0;
}