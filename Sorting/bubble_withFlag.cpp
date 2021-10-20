#include<iostream>
#include <bits/stdc++.h> 

using namespace std ;

void bubble_with_flag(int arr[], int n)
{   int i,temp=0, j;
    for(i=0;i<n;i++)
    {   
        int swapped =0;
        
        for(j=0;j<(n-(i+1));j++)
        {
            if(arr[j] >arr[j+1])
            {
                temp =arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped =1;
            }
        }
        if(swapped ==0)
        {   
            break;
        }
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
    int arr[] = {9,8,67,65,5,4,3,2,1};
    int l = sizeof(arr)/sizeof(arr[0]);
    bubble_with_flag(arr,l);
    printArray(arr, l); 
    return 0;
}