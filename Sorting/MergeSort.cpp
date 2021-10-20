#include<iostream>
#include <bits/stdc++.h> 

using namespace std ;
void merge1(int arr[],int low,int mid,int high)
{ 
    int p = mid-low+1;
    int q = high-mid;
    int L[p], R[q];
    int i,j;
    cout<<"a";
    for(i =0;i<p;i++)
    {
        L[i] = arr[low + i-1];
    }
    
    for(j =0;j<q;j++)
    {
        R[j] = arr[mid+j];
    }
    //L[p+1] = 1000;
    //R[q+1] = 1000;

    i =1;j=0;
    cout<<"in merge ";
    for(int k =low;k<=high;k++)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i =i+1;
        }
        else
        {
            arr[k] = R[j];
            j = j+1;
        }
    }
    cout<<"b";

}

void Merge_sort(int arr[], int low ,int high)
{  int n =high;
    if(low <high)
    {
    int mid;
    mid = (low +( high-low))/2;
    Merge_sort(arr,low,mid);
    Merge_sort(arr,mid+1,high);
    
    merge1(arr,low,mid,high);
    }
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;
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
    int low,high;
    int mid;
    low = 0;
    high = sizeof(arr)/sizeof(arr[0]);

    cout<<"Given array is \n"; 
    printArray(arr,high);
    Merge_sort(arr,low,high-1);
    printArray(arr, high); 
    return 0;
}