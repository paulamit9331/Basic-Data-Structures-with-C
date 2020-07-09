#include<stdio.h>
#include<stdlib.h>
int binarysearch(int* a,int key,int lb,int ub){
	if(lb<=ub){
		int mid=(lb+ub)/2;
		if(*(a+mid)==key){
			return (mid);
		}
		else if(key<*(a+mid)){
			return (binarysearch(a,key,lb,mid-1));
		}
		else{
			return (binarysearch(a,key,mid+1,ub));
		}
	}
	else{
		printf("Invalid key\n");
		exit(-1);
	}
}
int main(){
	int n,i,k,pos;
	printf("Enter the no. of elements ");
	scanf("%d",&n);
	int *x=(int*)malloc(n*sizeof(int));
	printf("Enter the sorted elements ");
	for(i=0;i<n;i++){
		scanf("%d",x+i);
	}
	printf("Enter the element you want to find:");
	scanf("%d",&k);
	pos=binarysearch(x,k,0,n-1);
	printf("The index of the searched no.=%d\n",pos);
	return 0;
}
