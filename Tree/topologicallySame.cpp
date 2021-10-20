
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

int same_topology_BT(BTNode *t1, BTNode *t2)
{
    if(t1 == NULL && t2 == NULL)
    {
        return 1;
    }
    else if(t1 !=NULL && t2 !=NULL)
    {
        return(same_topology_BT(t1->LC, t2->LC) && same_topology_BT(t1 ->RC,t2->RC));
    }
    else
    {
        return 0;
    }
}

int main()
{
    BTNode *root1 ,*root2;
    int k;
    root1 = Create_newnode(1);
    root1->LC = Create_newnode(2);
    root1->RC = Create_newnode(3);
    root1->LC->LC = Create_newnode(4);
    root1->LC->RC = Create_newnode(5);
    root1->RC->LC = Create_newnode(6);
    root1->RC->RC = Create_newnode(7);

    root2 = Create_newnode(1);
    root2->LC = Create_newnode(2);
    root2->RC = Create_newnode(3);
    root2->LC->LC = Create_newnode(4);
    root2->LC->RC = Create_newnode(5);
    root2->RC->LC = Create_newnode(6);
    root2->RC->RC = Create_newnode(7);
    /*cout<<"Preorder is : ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder is : ";
    Postorder(root);
    cout<<endl;
    cout<<"Inorder is : ";
    Inorder(root);*/
    k = same_topology_BT(root1,root2);
    if(k == 1)
    {
        cout<<"Tree is topologically same. ";
    }
    else
    {
        cout<<"Tree is  not topologically same. ";
    }
    return 0;
}