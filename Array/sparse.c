#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,mr,mc,sr,nz=0,s;
    printf("Enter the no. of rows and columns: ");
    scanf("%d%d",&mr,&mc);
    int arr[mr][mc];
    printf("Enter the elements in the matrix: ");
    for(i=0;i<mr;i++){
        for(j=0;j<mc;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The entered matrix is:\n");
    for(i=0;i<mr;i++){
        for(j=0;j<mc;j++){
            printf("%d\t",arr[i][j]);
            if(arr[i][j]!=0)
                nz++;
        }
        printf("\n");
    }
    if(nz>(mr*mc)/2){
        printf("Given matrix is not a sparse matrix");
        exit(-1);
    }
    sr=nz+1;
    int sparr[sr][3];
    sparr[0][0]=mr;
    sparr[0][1]=mc;
    sparr[0][2]=nz;
    s=1;
    for(i=0;i<mr;i++){
        for(j=0;j<mc;j++){
            if(arr[i][j]!=0){
                sparr[s][0]=i;
                sparr[s][1]=j;
                sparr[s][2]=arr[i][j];
                s++;
            }
        }
    }
    printf("The 3-tuple representation of sparse matrix is:\n");
    for(i=0;i<sr;i++){
        for(j=0;j<3;j++){
            printf("%d\t",sparr[i][j]);
        }
        printf("\n");
    }
    return 0;
}