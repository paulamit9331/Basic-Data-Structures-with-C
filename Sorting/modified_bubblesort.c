#include<stdio.h>
#include <stdlib.h>
void bubble_sort(int* a,int n){
    int i,j,k,temp,swapped;
    for(i=0;i<n;i++)
	{
		swapped=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=1;
			}
		}
		if (swapped==0)
		{
			break;
		}
		printf("After %d pass the array is:\n",i);
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
		scanf("%d",a+i);
	}
	bubble_sort(a,n);
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(a+i));
	}
	return 0;
}
