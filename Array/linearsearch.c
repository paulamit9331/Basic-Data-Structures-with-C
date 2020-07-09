#include <stdio.h>
#include<stdlib.h>
int linear_search(int* a,int n,int search){
    int i;
    for(i=0;i<n;i++)
	{
		if(*(a+i)==search)
		{
			return (i);
		}
	}
	if(i==n)
	{
		printf("Invalid location\n");
		exit(-1);
	}
}
int main()
{
	int search,pos,i,n;
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	int* a=(int*)malloc(n*sizeof(int));
	printf("Enter the elements:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
	printf("Enter a number to search\n");
	scanf("%d",&search);
	pos=linear_search(a,n,search);
    printf("The position of the element is %d\n",pos);
	return 0;
}
