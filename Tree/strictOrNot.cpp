
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

int strict_BT(BTNode *t)
{
    int L,R;

    if(t==NULL)
    {
        return 0;
    }
    else if(t->LC ==NULL && t->RC ==NULL)
    {
        return 1;
    }
    else
    {
        L = strict_BT(t->LC);
        R = strict_BT(t->RC);
        return(L*R);
    }
}


int main()
{
    BTNode *root;
    int k;
    root = Create_newnode(1);
    root->LC = Create_newnode(2);
    root->RC = Create_newnode(3);
    root->LC->LC = Create_newnode(4);
    root->LC->RC = Create_newnode(5);
    root->RC->LC = Create_newnode(6);
    root->RC->RC = Create_newnode(7);
    cout<<"Preorder is : ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder is : ";
    Postorder(root);
    cout<<endl;
    cout<<"Inorder is : ";
    Inorder(root);
    cout<<endl;
    k =strict_BT(root);
    if(k == 1)
    {
        cout<<"Tree is strict binary tree. ";
    }
    else
    {
        cout<<"Tree is not strict binary tree. ";
    }

    return 0;
}