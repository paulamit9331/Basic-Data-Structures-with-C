#include<stdio.h>
#include<stdlib.h>
int partition(int* a,int lb,int ub){
	int pivot,i,j,temp;
	pivot=a[lb];
	j=lb;
	for(i=j+1;i<=ub;i++){
		if(pivot>a[i]){
			j++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int* a,int lb,int ub){
	int j;
	if(lb<ub){
		j=partition(a,lb,ub);
		quicksort(a,lb,j-1);
		quicksort(a,j+1,ub);
	}
}
void print_array(int* a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
	printf("\n");
}
int main(){
	int n,i;
	printf("Enter the no. of elements: \n");
	scanf("%d",&n);
	int* a=(int*)malloc(n*sizeof(int));
	printf("Enter the elements in the array: \n");
	for(i=0;i<n;i++){
		scanf("%d",(a+i));
	}
	printf("Before sorting the array is: ");
	print_array(a,n);
	quicksort(a,0,n-1);
	printf("After sorting the array is: ");
	print_array(a,n);
	return 0;
}