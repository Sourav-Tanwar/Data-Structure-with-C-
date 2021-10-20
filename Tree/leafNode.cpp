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

int NOL1(BTNode *t)
{
    int count= 0;
    if(t)
    {
        if(t->LC==NULL && t->RC==NULL)
        {
            count =1;
        }
        else
        {
            count =count +NOL1(t->LC) +NOL1(t->RC);
        }
    }
    return(count);
}

int NOL2(BTNode *t)
{
    if(!t) return 0;
    if(t->LC==NULL && t->RC== NULL)
    {
        return 1;
    }
    else
    {
        return(NOL2(t->LC) + NOL2(t->RC));
    }
}

int main()
{
    BTNode *root;
    int k, j;
    root = Create_newnode(1);
    root->LC = Create_newnode(2);
    root->RC = Create_newnode(3);
    root->LC->LC = Create_newnode(4);
    root->RC->RC = Create_newnode(5);
    root->RC->RC->LC = Create_newnode(6);
    
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    k = NOL1(root);
    cout<<"no of leaf node is "<<k<<endl;
    j = NOL2(root);
    cout<<"no of leaf node is "<<j;
    return 0;
}