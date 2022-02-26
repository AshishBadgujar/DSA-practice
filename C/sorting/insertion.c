#include<stdio.h>

void insertionSort(int *A,int n){
    int key=0;
    for (int i = 1;i<n; i++)
    {
        key=A[i];
        for (int j =i-1 ; j>=0; j--)
        {
            if (A[j]>key)
            {
                A[j+1]=A[j];
                A[j]=key;
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
    insertionSort(A,n);
    printArray(A,n);
}