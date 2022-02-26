// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
    int key=0;
    for (int i = 1;i<n; i++)
    {
        key=arr[i];
        for (int j =i-1 ; j>=0; j--)
        {
            if (arr[j]>key)
            {
                arr[j+1]=arr[j];
                arr[j]=key;
            }
        }
    }
}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

int main()
{
    int arr[]={7,11,9,2,17,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    cout<<"Sorted array:\n";
    printArray(arr,n);
    return 0;
}