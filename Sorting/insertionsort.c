#include<stdio.h>
#include <stdlib.h>
void insertion_sort(int* a,int n){
    int i,k,pos,smallest;
    for(i=1;i<n;i++)
	{
		pos=i;
		smallest=*(a+pos);
		while(pos>0 && a[pos-1]>smallest)
		{
			a[pos]=a[pos-1];
			pos--;
		}
		*(a+pos)=smallest;
		printf("After %d pass the array\n",i);
		for(k=0;k<n;k++)
		{
			printf("%d\t",*(a+k));
		}
		printf("\n");
	}
}
int main()
{
	int n,i;
	printf("Enter the no. of elements:\n");
	scanf("%d",&n);
	int* a=(int*)malloc(n*sizeof(int));
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
	insertion_sort(a,n);
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(a+i));
	}
	return 0;
}
