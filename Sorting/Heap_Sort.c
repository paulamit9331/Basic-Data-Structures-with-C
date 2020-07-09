#include<stdio.h>
#include<stdlib.h>
void max_heap(int *a,int i,int n)
{
			int l,r,largest_pos,temp,k;
			l=2*i+1;
			r=2*i+2;
			largest_pos=i;
			if(l<n&&*(a+l)>*(a+i))
				largest_pos=l;
			if(r<n&&*(a+r)>*(a+largest_pos))
				largest_pos=r;
			if(largest_pos!=i)
			{
				temp=*(a+largest_pos);
				*(a+largest_pos)=*(a+i);
				*(a+i)=temp;
				max_heap(a,largest_pos,n);
			}
}
void heapify(int *a, int n)
{
		int i;
		for(i=n/2-1;i>=0;i--)
			max_heap(a,i,n);
		/*for(i=n/2;i>=1;i--)
			max_heap(a,i-1,n);*/
}
void heapsort(int *a,int n)
{
		int temp,j=1,k,i;
		heapify(a,n);
		for(i=n-1;i>=1;i--)
		{
				temp=*(a+i);
				*(a+i)=*(a+0);
				*(a+0)=temp;
				printf("After pass%d elements are:\n",j++);
				for(k=0;k<n;k++)
					printf("%d\n",*(a+k)); 
				max_heap(a,0,i);
		}
}
int main()
{
		int *a,n,i;
		printf("\nEnter no of elements:");
		scanf("%d",&n);
		a=(int *)malloc(n*sizeof(int));
		printf("\nEnter elements to be sorted:\n");
		for(i=0;i<n;i++)
				scanf("%d",a+i);
		heapsort(a,n);
		printf("\nSORTED ELEMENT\n\n");
		for(i=0;i<n;i++)
				printf("%d\t",*(a+i));
		return 0;
}
