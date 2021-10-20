#include<iostream>
#include <bits/stdc++.h> 

using namespace std;
int F,R;

void enqueue(int  *Q, int N){
    if (R == N-1){
        cout<<"Queue overflow"<<endl;
    }
    else{
        int x;
        cout<<"enter the element for insert : ";
        cin>>x;
        Q[++R] = x;
        if(F ==-1){
            F=0;
        }
    }
}

void dequeue(int *Q, int N){

    int y;
    if(F== -1){
        cout<<"Queue underflow"<<endl;

    }else
    {
    
    y  = Q[F];
    if(F==R){
        F = R = -1;
    }
    else{
        F  =F+1;
    }
    cout<<y<<endl;
    }
}

void display(int *S){
    int i;
    for(i=F; i<=R;i++){
        cout<<S[i]<<endl;
    }
}

int main(){
    F =-1, R=-1;
    int i , Q[20] , N;
    
    cout<<"enter the size of queue : ";
    cin>>N;

    
    cout<<"\n\t QUEUE OPERATIONS USING ARRAY";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;

    do{
    cout<<"enter choice: ";
    cin>>i;

    switch(i){

        case 1: enqueue(Q,N);
                break;
        
        case 2: dequeue(Q,N);
                break;
        
        case 3:display(Q);
                break;

        case 4:
                cout<<"EXIT POINT";
                break;
        default:
                cout<<"\n\t Please Enter a Valid Choice(1/2/3)"<<endl;
                break;


    }
    }while(i !=4);
    return 0;
}

