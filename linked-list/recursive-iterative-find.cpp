/* AUTHOR -- code_blooded */

/**
*
*	This program aims at returning the nth indexed node in a linked list both using iteration and recursion.
*
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
};

node* newNode(int val){
    node* temp = new node;
    temp->next = NULL;
    temp->val = val;
    return temp;
}

void garbage(node* head){
    while(head){
        node* temp=head->next;
        delete head;
        head = temp;
    }
}

node* find_iterative(node* head,int x){
    while(x--){
        head = head->next;
    }
    return head;
}

node* find_recursive(node* head,int x){
    if(x==0)
        return head;
    find_recursive(head->next,x-1);
}

int main(){
    
    node* head=NULL;
    node* temp=NULL;
    int value,n;
    
    cout<<"Enter the no of numbers: \n";
    cin>>n;
    cout<<"Enter the numbers\n";
    for(int i=0;i<n;i++){
        cin>>value;
        if(temp==NULL){
            head = temp = newNode(value);
        }
        else{
            temp->next = newNode(value);
            temp = temp->next;
        }
    }
    
    cout<<"Printing the linked list: \n";
    temp = head;
    for(int i=0;i<n;i++){
        cout<<temp->val<<"-->";
        temp = temp->next;
    }
    cout<<"|||\n";
    
    int x;
    cout<<"Enter the index of the required element: (using iterative) \n";
    cin>>x;
    node* element1 = find_iterative(head,x);
    cout<<element1->val<<"\n";
    cout<<"Enter the index of the required element: (using iterative) \n";
    cin>>x;
    node* element2 = find_recursive(head,x);
    cout<<element2->val<<"\n";
    
    garbage(head);
    
    return 0;
}