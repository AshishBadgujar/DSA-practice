#include<stdio.h>

void selectionSort(int *A,int n){
    int temp;
    for (int i = 0; i < n; i++)
    {   
        for (int j = i+1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                temp=A[j];
                A[j]=A[i];
                A[i]=temp;
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
    selectionSort(A,n);
    printArray(A,n);
}