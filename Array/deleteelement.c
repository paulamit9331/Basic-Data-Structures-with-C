#include <stdio.h>
#include<stdlib.h>
void delete_element(int* a,int n,int p){
    int i;
    if (p>=n){
        exit(0);
    }
    else{
        for (i=p;i<n-1;i++){
            a[i]=a[i+1];
        }
    }
}
int main()
{
    int p,i,n;
    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    int* a=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements\n", n);
    for (i=0;i<n;i++){
        scanf("%d",(a+i));
    }
    printf("Enter the location where you wish to delete element\n");
    scanf("%d",&p);
    delete_element(a,n,p);
    printf("Resultant array:\n");
    for (i=0;i<n-1;i++){
        printf("%d\t",*(a+i));
    }
    return 0;
}
