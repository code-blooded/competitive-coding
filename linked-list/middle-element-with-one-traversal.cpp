/* AUTHOR -- code_blooded */

/**
*
*   This program aims at finding the middle element with one traversal of the linked list using slow and fast pointers.
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

void print(node* head){
    while(head!=NULL){
        cout<<head->val<<" --> ";
        head = head->next;
    }
    cout<<"|||\n";
}

void garbage(node* head){
    while(head){
        node* temp = head->next;
        delete head;
        head = temp;
    }
}

node* middle(node* head){
    if(head==NULL)  return NULL;
    node* slow = head;
    node* fast = head;
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
    }
    return slow;
}

/*
Sample Input 1
5
0 11 -2 6 8
*/

int main(){
    
    node* head = NULL;
    node* temp = NULL;
    int value,n;
    
    // scanning input
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
    
    cout<<"Printing the linked list\n";
    print(head);
    
    cout<<"Middle element is ";
    cout<<middle(head)->val;
    cout<<"\n";
    
    // freeing the allocated memory
    garbage(head);
    
    return 0;
}