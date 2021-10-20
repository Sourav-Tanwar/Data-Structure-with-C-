#include<iostream>
#include <bits/stdc++.h> 

using namespace std;
int top;
void push(int *S, int n){
    int x;

    if (top == (n-1)){
        cout<<"stack overflow"<<endl;
        
    }
    else{
    cout<<"enter the integer to push : "; 
    cin>>x; 

    top = top +1;//S[++top] = x;
    S[top] =x; 
    }
    
}

void pop(int *S , int n){
    int m;
    if(top == -1){
        cout<<"stack underflow"<<endl;
        
    }
    else {
       m = S[top] ; 
       top = top -1;//m = s[top--]
       cout<<"poped element is : "<<m<<endl; 
    }
}

void display(int *S){
    int i;
    if(top >=0){
        for(i=top;i>=0;i--){
            cout<<"\n"<<S[i];
            
        }
        cout<<endl;
    }
    else {
        cout<<"stack is empty"<<endl;
    }  
}


int main(){
    int x, n,y, j,i;
    top =-1;
    int S[5];
    n = sizeof(S)/sizeof(S[0]);
    cout<<"\n\t STACK OPERATIONS USING ARRAY";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;
    do{
    cout<<"enter choice: ";
    cin>>i;

    switch(i){
        case 1: push(S,n);
                break;
        
        case 2: pop(S,n);
                break;
        case 3: display(S);
                break;


        case 4: cout<<"Exit point";
                break;
        default:
            cout<<"\n\t Please Enter a Valid Choice(1/2/3/4)"<<endl;
            break;
            
    }
    }
    while(i !=4);
    return 0;
}
