/* PROGRAM FOR INSERTION, DELETION AND DISPLAY IN DOUBLY LINKED LIST*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/* STRUCTURE OF NODE */
struct BTNode {
    struct BTNode *LC;
    int data;
    struct BTNode *RC;

};
typedef struct BTNode BTNode;



BTNode* Create_newnode(int data)
{
    BTNode *t;
    t = (BTNode*)malloc(sizeof(BTNode));
    t->data =data;
    t->LC = NULL;
    t->RC = NULL;
    return(t);
}
void Preorder(BTNode *t)
{
    if(t !=NULL)
    {
        cout<<t->data;
        Preorder(t->LC);
        Preorder(t->RC);
    }
}

void Postorder(BTNode *t)
{
    if(t !=NULL)
    {
        Postorder(t->LC);
        Postorder(t->RC);
        cout<<t->data;
    }
}

void Inorder(BTNode *t)
{
    if(t !=NULL)
    {
        Inorder(t->LC);
        cout<<t->data;
        Inorder(t->RC);
    }
}

BTNode* LMnode1(BTNode *t)
{
    if(t)
    {
        if(t->LC==NULL)
        {
            return(t);
        }    
        else
        {
            return(LMnode1(t->LC));
        }
    }
    return NULL;
}


BTNode* LMnode2(BTNode *t)
{
    if(!t)
    {
        return NULL;
    }
    while(t->LC)
    {
        t= t->LC;
    }
    return(t);
    
}


int main()
{
    BTNode *root,*k,*j;
    
    root = Create_newnode(1);
    root->LC = Create_newnode(2);
    root->RC = Create_newnode(3);
    root->LC->LC = Create_newnode(4);
    root->RC->RC = Create_newnode(5);
    root->RC->RC->LC = Create_newnode(6);
    cout<<"Preorder is : ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder is : ";
    Postorder(root);
    cout<<endl;
    cout<<"Inorder is : ";
    Inorder(root);
    cout<<endl;
    k =LMnode1(root);
    cout<<"address of leftmost node : "<<k;
    cout<<endl;
    j =LMnode2(root);
    cout<<"address of leftmost node : "<<j;

    return 0;
}