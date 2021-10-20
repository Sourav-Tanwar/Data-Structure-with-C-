#include<iostream>
#include <bits/stdc++.h> 

using namespace std;
char S[20];
int top =-1;
 
void push(char x){
    S[++top] = x;
}
char pop(){
    if (top  == -1){
        return -1;
    }
    else{
        return  S[top --];
    }
}

int priority(char x)
{
    if(x == '('){
        return 0;}
    if(x == '+' || x == '-'){
        return 1;}
    if (x ==  '*' || x== '/'){
        return 2;}   
}
int main(){
     char exp[20];
     char *e, x;
     cout<<"Enter the expression :: ";
     cin>>exp;
    e =exp;
    while(*e != '\0')
    {

        if(isalnum(*e))
            cout<<*e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                cout<<x;
        } 
        else
        {
            while(priority(S[top]) >= priority(*e))
                cout<<pop();
            push(*e);
        }
        e++;
         
    }
    while(top != -1)
    {
        cout<<pop();
    }
 }