#include<stdio.h>
void selection_sort(int a[],int n){
    int i,j,pos,smallest,temp;
    for(i=0;i<n-1;i++)
	{
		smallest=a[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<smallest)
			{
				smallest=a[j];
				pos=j;
			}
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
}
int main()
{
	int a[100],i,n;
	printf("Enter the no. of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection_sort(a,n);
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
