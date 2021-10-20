#include<iostream>
#include <bits/stdc++.h> 

using namespace std;
int top1, top2;
void push1(int *S, int n ){
    if(top1 <top2 -1){
        int x;
        cout<<"enter the integer to push in stack 1 : "; 
        cin>>x;
        S[++top1] = x;
    }
    else{
        cout<<"stackoverflow"<<endl;
    }
}

void push2(int *S, int n ){
    
    if(top2 > top1 +1){
        int x;
        cout<<"enter the integer to push in stack 2 : "; 
        cin>>x;
        S[--top2] = x;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}


void pop1(int *S){
    if(top1>=0){
        cout<<"poped element is : "<<S[top1]<<endl;
        top1--;
    }
    else{
        cout<<"Stack underlow"<<endl;
    }

}

void pop2(int *S, int n){
    if(top2<n){
        cout<<"poped element is : "<<S[top2]<<endl;
        top2++;
    }
    else{
        cout<<"Stack underlow"<<endl;
    }
}




void display1(int *S){
    int i;
    if(top1 >=0){
        for(i=top1;i>=0;i--){
            cout<<"\n"<<S[i];
            
        }
        cout<<endl;
    }
    else {
        cout<<"stack is empty"<<endl;
    }  
}

void display2(int *S,int n ){
    int i;
    if(top2 <n){
        for(i=top2;i<n;i++){
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
    top1 =-1;
    int S[10];
    n = sizeof(S)/sizeof(S[0]);
    top2 = n;
    cout<<"\n\t STACK OPERATIONS USING ARRAY";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.PUSH1\n\t 2.POP1\n\t 3.PUSH2\n\t 4.POP2\n\t 5.DISPLAY1\n\t 6.DISPLAY2\n\t 7.EXIT\n\t"<<endl;
    do{
    cout<<"enter choice: ";
    cin>>i;
    switch (i)
    {
    case 1: push1(S,n);
        break;
    case 2: pop1(S);
        break;
    case 3: push2(S,n);
        break;
    case 4: pop2(S ,n);
        break;
    case 5:display1(S);
        break;
    case 6:display2(S,n);
        break;
    case 7:cout<<"Exit point";
        break;
    default:
        cout<<"\n\t Please Enter a Valid Choice(1/2/3)"<<endl;
        break;
    }
    }while(i!=7);
    return 0;

}