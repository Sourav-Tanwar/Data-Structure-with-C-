
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
        cout<<t->data<<" ";
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
        cout<<t->data<<" ";
    }
}

void Inorder(BTNode *t)
{
    if(t !=NULL)
    {
        Inorder(t->LC);
        cout<<t->data<<" ";
        Inorder(t->RC);
    }
}

BTNode* create_BST(BTNode *t, int key)
{
    if(t== NULL)
    {
        t = (BTNode*)malloc(sizeof(BTNode));       
        if(!t)
        {
            exit(1);
        }
        else
        {
            t->data = key;
            t->LC =NULL;
            t->RC =NULL; 
        }
        return(t);
    }
    else
    {
        if(key < t->data)
        {
            t->LC = create_BST(t->LC,key);
        }
        else if(key > t->data)
        {
            t->RC = create_BST(t->RC,key);
        }
        else
        {
            cout<<"duplicate key" ; 
        }
        return(t);
    }
}

BTNode* min_value_node(BTNode *t)
{
    while(t->LC)
    {
        t= t->LC;
    }
    return(t);
}
BTNode* deleteNode(BTNode *t, int key)
{
    if(!t)
    {
        return(t);
    }
    if(key < t->data)
    {
        t->LC =deleteNode(t->LC,key);
    }
    else if(key > t->data)
    {
        t->RC =deleteNode(t->RC, key);
    }
    else
    {
        if(!t->LC)
        {
            BTNode *temp = t->RC;
            free(t);
            return(temp);
        }
        else if(!t ->RC)
        {
            BTNode *temp = t->LC;
            free(t);
            return(temp);
        }
        BTNode *temp = min_value_node(t->RC);
        t->data = temp ->data;
        t->RC = deleteNode(t->RC,t->data);
    }
    return(t);
}

int min_value_Itrative(BTNode *t)
{
    while(t->LC)
    {
        t= t->LC;
    }
    return(t->data);
}

int min_value_Recursive(BTNode *t)
{
    if(t)
    {
        if(!t->LC)
        {
            return (t->data);
        }
        else
        {
            min_value_Recursive(t->LC);
        }
    }
    else
    {
        cout<<"Element is not present in BST";
        return 0;
    }
}

BTNode* search(BTNode *t, int key)
{
    if(!t | t->data==key)
    {
        return t;
    }
    if(t->data < key)
    {
        return(search(t->RC,key));
    }
    else
    {
        return(search(t->LC,key));
    }
    return NULL;

}  
BTNode* search1(BTNode *t, int key)
{   
    while(t)
    {
        if(key > t->data)
        {
            t = t->RC;
        }
        else if(key <t->data)
            {
        t =t->LC;
        }
        else
        {
            return t;    
        }
    }
    return NULL;
}

/*int main()
{
    BTNode *root,*p,*q;
    root = NULL;
    int key ,n,i,j;
    cout<<"How many elements you want to insert : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter the key : ";
        cin>>key;
        if(i ==1)
        {
        root = create_BST(root,key);
        }
        else
        {
            create_BST(root,key);
        }
    }
    cout<<endl;
    cout<<"Preorder is : ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder is : ";
    Postorder(root);
    cout<<endl;
    cout<<"Inorder is : ";
    Inorder(root);
    cout<<endl;
    cout<<min_value_Itrative(root);
    cout<<endl;
    cout<<min_value_Recursive(root);
    cout<<endl;
    cout<<"enter the key you want to search : ";
    cin>>i;
    p = search(root,i);
    if(p)
    {
        cout<<"Key is present in BST"<<endl;
        cout<<p->data;
    }
    else
    {
        cout<<"Key is not present in BST";
    }
    

    return 0;
}*/
int main() {
    
    BTNode *root,*p,*q;
    root = NULL;
    int key ,n,i,j,f;
    f=1;
    cout<<"\n\t BINARY SEARCH TREE OPERATIONS";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.INSERTION\n\t 2.DELETITION\n\t 3.INORDER\n\t 4.PREORDER\n\t 5.POSTORDER\n\t 6.MINIMUM VALUE ITRATIVE\n\t 7.MINIMUM VALUE RECURSIVE\n\t 8.SEARCHING ITRATIVE\n\t 9.SEARCHING RECURSIVE\n\t 10.EXIT"<<endl;

    do
    {
        cout<<"Enter the operation : ";
        cin>>i;
        switch(i){
            case 1:
                    cout<<"Enter the key : ";
                    cin>>key;
                    if(f==1)
                    {
                        root = create_BST(root,key);
                        f++;
                    }
                    else
                    {
                        create_BST(root,key);
                    }
                break;

            case 2:
                    cout<<"enter the key you want to delete : ";
                    cin>>key;
                    deleteNode(root,key);
                    break; 

            case 3 :   
                    cout<<"Inorder is : ";
                    Inorder(root);
                    cout<<endl;
                    break;

            case 4:
                    cout<<"Preorder is : ";
                    Preorder(root);
                    cout<<endl;
                    break; 
            case 5:
                    cout<<"Postorder is : ";
                    Postorder(root);
                    cout<<endl;
                    break;
            case 6: 
                    cout<<min_value_Itrative(root);
                    cout<<endl;
                    break; 
            case 7:
                    cout<<min_value_Recursive(root);
                    cout<<endl;
                    break; 
            case 8:
                    cout<<"enter the key you want to search : ";
                    cin>>i;
                    p = search1(root,i);
                    if(p)
                    {
                        cout<<"Key is present in BST"<<endl;
                        cout<<p->data<<endl;
                    }
                    else
                    {
                        cout<<"Key is not present in BST"<<endl;
                    }
                    break; 
            case 9:
                    cout<<"enter the key you want to search : ";
                    cin>>i;
                    p = search(root,i);
                    if(p)
                    {
                        cout<<"Key is present in BST"<<endl;
                        cout<<p->data<<endl;
                    }
                    else
                    {
                        cout<<"Key is not present in BST"<<endl;
                    }
                    break;            
            case 10:
                    cout<<"EXIT POINT";
                    break;
            default:
                   cout<<"\n\t Please Enter a Valid Choice(1/2/3/4)"<<endl;
                    break;
        }
    } while (i!=10);
   return 0;
} 