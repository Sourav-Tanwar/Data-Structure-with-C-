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

int BTH(BTNode *t)
{
    if(t==NULL){
        return -1;
    }
    else
    {
        int L= BTH(t->LC);
        int R= BTH(t->RC);
        if(L>R)
        {
            return(L+1);
        }
        else
        {
            return(R+1);
        }
    }

}

int main()
{
    BTNode *root;
    int k;
    root = Create_newnode(1);
    root->LC = Create_newnode(2);
    root->RC = Create_newnode(3);
    root->LC->RC = Create_newnode(4);
    root->LC->RC->LC = Create_newnode(5);
    root->RC->LC = Create_newnode(6);
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    k = BTH(root);
    cout<<k;
    return 0;
}