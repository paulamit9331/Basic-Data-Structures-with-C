#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void radixsort(int* a, int n){
	int buck[10],bucket[10][MAX];
	int divisor=1,i,j,k,largest,numcount=0,pass,r;
	largest=a[0];
	for(i=1;i<n;i++){
		if(a[i]>largest)
			largest=a[i];
	}
	while(largest>0){
		numcount++;
		largest/=10;
	}
	for(pass=1;pass<=numcount;pass++){
		for(k=0;k<10;k++)
			buck[k]=0;
		for(i=0;i<n;i++){
			r=(a[i]/divisor)%10;
			bucket[r][buck[r]++]=a[i];
		}
		i=0;
		for(k=0;k<10;k++){
			for(j=0;j<buck[k];j++){
				a[i++]=bucket[k][j];
			}
		}
		divisor*=10;
	}
}
int main(){
	int i,n;
	printf("Enter no. of elememts: ");
	scanf("%d",&n);
	int* a=(int*)malloc(n*sizeof(int));
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	printf("Before sorting the array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",*(a+i));
	printf("\n");
	radixsort(a,n);
	printf("After sorting the array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",*(a+i));
	printf("\n");
	return 0;
}