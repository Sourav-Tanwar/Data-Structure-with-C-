#include<iostream>
#include <bits/stdc++.h> 

using namespace std;
void   bubble_sort(int arr[], int n){
    int i ,j,temp;

    for (i=0;i<n-1;i++){
        for(j=0;j<n-(i+1);j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] =temp;
            }

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
    int l;
    int a[] ={9,8,7,6,5,5,43,3,2,4324,5,42,3,25,1};
    l = sizeof(a)/sizeof(a[0]);
    cout<<l<<endl;
    printArray(a,l);

    bubble_sort(a,l);
    printArray(a,l);
    return 0;
}