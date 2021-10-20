
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

node *Top =NULL;

void push(int data)
{
    node* newnode;
    newnode =(node*)malloc(sizeof(node));
    if(!newnode)
    {
        cout<<"memory error"<<endl;
    }
    newnode->data =data;
    newnode->next = Top;
    Top = newnode;
}

void pop()
{
    node *t;
    if(!Top)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        t = Top;
        Top = Top ->next;
        t->next =NULL;
        free(t);
    }
}


int display(node **Head)
{
   node* ptr;
   int count =0;
   ptr = *Head;
   while (ptr) {
       count++;
       cout<< ptr->data <<" ";
       ptr = ptr->next;
    }
   cout<<endl;
   return count;

}

int main()
{   int i,data;
    cout<<"\n\t STACK OPERATIONS USING LINKED LIST";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;
    do{
    cout<<"enter choice: ";
    cin>>i;

    switch(i){
        case 1: cout<<"Enter the integer to push : ";
                cin>>data;
                push(data);
                break;
        
        case 2: pop();
                break;
        case 3: int  y;
                    y= display(&Top);
                    cout<<"Total node : "<<y;
                    cout<<endl;
                    break;


        case 4: cout<<"Exit point";
                break;
        default:
            cout<<"\n\t Please Enter a Valid Choice(1/2/3)"<<endl;
            break;
            
    }
    }
    while(i !=4);
    return 0;
}