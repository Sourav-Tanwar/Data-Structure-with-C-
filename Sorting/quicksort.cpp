#include<iostream>
#include <bits/stdc++.h> 

using namespace std ;


int Partition(int arr[],int lb, int ub)
{   
    int start, end, temp;
    int pivot = arr[lb];
    start =lb;
    end = ub;
    while(start < end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start < end )
        {
            temp = arr[end];
            arr[end] =arr[start];
            arr[start] = temp;      
        }
    }
    temp = arr[end];
    arr[end] =arr[lb];
    arr[lb] = temp;
    return end;
}


void quickSort(int arr[],int lb, int ub)
{   
    if(lb < ub)
    {
        int loc  = Partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }

}

  

void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  

int main(){
    int arr[] ={9,8,67,65,5,4,3,2,1};
    int l = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,l-1);
    printArray(arr, l); 
    return 0;
}