#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

node* head  =NULL;
void insert(int new_data){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data =new_data;
    new_node->next =head;
    head = new_node;

}
void display() { 
   node* ptr;   
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<" ";
      ptr = ptr->next; 
   } 
} 
int main() { 
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The linked list is: ";
   display(); 
   return 0; 
} 