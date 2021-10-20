#include<iostream>
#include <bits/stdc++.h> 

using namespace std ;

void insertion(int arr[], int l)
{   int count= 0;
    int j, i, key;
    for (j =1;j<l;j++)
    {
        key = arr[j];
        i =j-1;
        while(i>=0 && arr[i] >key ){
            arr[i+1] = arr[i];
            i= i-1;
        }
        count++;
        arr[i+1] = key;
    }
    cout<<count<<endl;
}
/*void insertion(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;   
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  */
  

void printArray(int arr[], int n) 
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  

int main(){
    int arr[] = {5,1,3,2},i;

    int l = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,l);
    printArray(arr, l); 
    return 0;
}