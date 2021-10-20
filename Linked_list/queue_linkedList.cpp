
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

struct Queue
{
    node *Front, *Rear;
};

void enqueue(Queue *Q, node *newnode)
{
    if(Q->Rear ==NULL)
    { 
        Q->Front =newnode;
        Q->Rear = newnode;
    }
    else{
    Q->Rear->next =newnode;
    
    Q->Rear =newnode;
    cout<<Q->Front->data;
    }
}
 
void dequeue(Queue *Q)
{
    
    if(Q->Front ==NULL)
    {
        std::cout<<"Queue is empty"<<endl;
        
    }
    node *t;
    t = Q->Front;
    Q->Front = Q->Front->next;
    if(Q->Front ==NULL)
    {
        Q->Rear = NULL;
    }
    cout<<t->data<<endl;
    
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


int main(){
    int i ;
    Queue *Q;  
    Q = (Queue*)malloc(sizeof(Queue));
    Q->Front = NULL;
    Q->Rear = NULL;
    std::cout<<"\n\t QUEUE OPERATIONS USING LINKED LIST";
    std::cout<<"\n\t--------------------------------";
    std::cout<<"\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;
    do{
    std::cout<<"enter choice: ";
    cin>>i;

    switch(i){

        case 1: node* newnode;
                int data;
                std::cout<<"Enter the integer to enqueue : ";
                cin>>data;
                newnode->data = data;
                newnode ->next =NULL;
                enqueue(Q,newnode);
                break;
        
        case 2: dequeue(Q);
                break;

        case 3:     int  y;
                    y= display(&Q->Front);
                    cout<<"Total node : "<<y;
                    cout<<endl;
                    break;
        case 4:
                std::cout<<"EXIT POINT";
                break;
        default:
                std::cout<<"\n\t Please Enter a Valid Choice(1/2/3)"<<endl;
                break;


    }
    }while(i !=4);
    return 0;
}
