#include<iostream>
#include <bits/stdc++.h> 

using namespace std ;

void selectionSort(int arr[], int n)
{   int i,temp=0, j,min =0;
    int c = 0;
    for(i =0;i<n-1;i++)
    {   min = i;
        for(j = i+1;j<n;j++)
        {
            if(arr[j]< arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        c= c+1;
        
    }
    cout<<c<<endl;
}

  

void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  

int main(){
    int arr[] = {1,2,3};
    int l = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,l);
    printArray(arr, l); 
    return 0;
}