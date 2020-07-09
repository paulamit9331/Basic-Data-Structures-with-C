#include<stdio.h>
#include<stdlib.h>
void insert_element(int* a,int n,int value,int p){
    int i;
    for(i=n-1;i>=p;i--)
	{
		a[i+1]=a[i];
	}
	a[p]=value;
}
int main()
{
	int *a,n,p,value,i;
	printf("Insert no. of elements in array : ");
	scanf("%d",&n);
	printf("Enter the elements in the array:\n");
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	printf("Write a number to insert: ");
	scanf("%d",&value);
	printf("Write the position :");
	scanf("%d",&p);
	insert_element(a,n,value,p);
	printf("Print the new array:\n");
	for(i=0;i<=n;i++)
	{
		printf("%d\t",*(a+i));
	}
	return 0;
}
