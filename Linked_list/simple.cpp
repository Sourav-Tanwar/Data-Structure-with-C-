// A simple C++ program for traversal of a linked list 
#include <bits/stdc++.h> 
using namespace std; 

class Node { 
public: 
	int data; 
	Node* next; 
}; 

// This function prints contents of linked list 
// starting from the given node 
void printList(Node* n) 
{ 
	while (n != NULL) { 
		cout << n->data << " "; 
		n = n->next; 
	} 
} 

// Driver code 
int main() 
{ 
	Node* head = NULL; 
	Node* second = NULL; 
	Node* third = NULL; 

	// allocate 3 nodes in the heap 
	head = new Node(); 
	second = new Node(); 
	third = new Node(); 

	head->data = 5; // assign data in first node 
	head->next = second; // Link first node with second 

	second->data = 6; // assign data to second node 
	second->next = third; 
	third->data = 7; // assign data to third node 
	third->next = NULL; 

	printList(head); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
