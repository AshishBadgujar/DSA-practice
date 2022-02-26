#include<stdio.h>

void bubbleSort(int *A,int n){
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }   
    }
}

void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf(" %d ",A[i]);
    }
    printf("\n");
}

int main(){
    int A[]={7,11,9,2,17,4};
    int n=6;
    printArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);
}