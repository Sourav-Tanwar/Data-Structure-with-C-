/* PROGRAM FOR INSERTION, DELETION AND DISPLAY IN DOUBLY LINKED LIST*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/* STRUCTURE OF NODE */
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;

};
typedef struct Node node;
/* FUNCTION FOR COUNT THE NODE IN LINKED LIST*/
int count1(node ***Head)
{   
    node* ptr;
    int count =0;
    ptr = **Head;
    while (ptr) {
       count++;
       ptr = ptr->next;
    }
    cout<<endl;
    return count;

}
/* FUNCTION FOR INSERT NODE INTO LINKED LIST */
void insert_node_DLL(node **Head, node* newnode, int pos)
{
    int k=1,c;
    node *p,*q;
    p =*Head;
    c  = count1(&Head);
    if(c ==0){
        *Head = newnode;
    }else{
    if(pos ==1){ 
        newnode->next =*Head;
        (*Head)->prev = newnode; 
        *Head = newnode;
    }
    else{
        if (c+1>=pos){
        while(p !=NULL && k<pos)
        {
            k++;
            q=p;
            p =p->next;
        }
        if(p==NULL)
        {
            q ->next =newnode;
            newnode ->prev =q;
        }
        else
        { 
            newnode->prev = q;
            newnode->next = q->next;
            q->next =newnode;
            newnode ->next->prev =newnode;
        }
        }
        else{
            cout<<"position does not exist"<<endl;
        }
    }
    }
    
}

/* FUNCTION FOR DELETION OF NODE IN LINKED LIST*/
void delete_node_SLL(node **Head, int pos)
{
    node *p,*q;
    int k=1,c;
    c  = count1(&Head);
    if(c==0 || !Head)
    {
        cout<<"List is empty"<<endl;
    }
    else{
    p = *Head;
    if(pos==1)
    {   if (c==1){
            free(p);
            p =NULL; 
            (*Head) = NULL;
            cout<<"Node is deleted successfully "<<endl;
        }
        else{
            *Head = (*Head)->next;
            (*Head)->prev = NULL;
            free(p);
            p =NULL;
            cout<<"Node is deleted successfully "<<endl;
        }
    }
    else
    {
        while(p && k<pos)
        {
            k++;
            q=p;
            p = p->next;
        }

        if(p==NULL)
        {
            cout<<"Position does not exist"<<endl;
        }
        else
        { 
            if(pos ==c){
            p ->prev->next= NULL;
            free(p);
            p = NULL;
            cout<<"Node is deleted successfully "<<endl;
            }
            else{
            p->prev->next = p ->next;
            p ->next->prev = p->prev;
            free(p);
            p = NULL;
            cout<<"Node is deleted successfully "<<endl;
            }
        }
    }
    }
   
}
/* FUNCTION FOR DISPLAY THE ELEMENTS WHICH STORED IN LINKED LIST*/
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

/*node* Create_node(int data)
{
    node *newnnode;
    newnnode =(node*)malloc(sizeof(node));
    newnnode->data = data;
    newnnode->prev =NULL;
    newnnode ->next = NULL;
}
 */

int main() {
    int position, data ,i;

    cout<<"\n\t LINKED LIST OPERATIONS";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.INSERTION\n\t 2.DELETITION\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;

    node *newnode;
    node *Head;
    do
    {
        cout<<"Enter the operation : ";
        cin>>i;
        switch(i){
            case 1:
                cout<<"Enter the position in which you want to insert a node : ";
                cin>>position;
                newnode = (node*)malloc(sizeof(node));
                cout<<"Enter the data : ";
                cin>>data;
                newnode->data = data;
                newnode->prev = NULL;
                newnode->next = NULL;
                insert_node_DLL(&Head, newnode,position);
                break;

            case 2:
                cout<<"Enter the position in which you want to delete a node : ";
                cin>>position;
                delete_node_SLL(&Head,position);
                break;

            case 3:int  y;
                    y= display(&Head);
                    cout<<"Total node : "<<y;
                    cout<<endl;
                    break;
            case 4:
                    cout<<"EXIT POINT";
                    break;
            default:
                   cout<<"\n\t Please Enter a Valid Choice(1/2/3/4)"<<endl;
                    break;
        }
    } while (i!=4);

    
   return 0;
}