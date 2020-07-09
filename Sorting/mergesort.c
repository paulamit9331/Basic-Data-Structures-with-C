#include <stdio.h>
#include<stdlib.h>
#define MAX 10
void merge(int a[],int low,int high){
	int temp[MAX],i,j,k;
	int mid=(low+high)/2;
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high){
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=temp[i];
}
void mergesort(int a[],int low,int high){
	if(low>=high){
		return;
	}
	int mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,high);
}
int main(){
	int a[MAX],i,n;
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("After sorting the elements are: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}