/* AUTHOR -- code_blooded */

/**
*
*	This program aims at finding the length of a linked list using both iterative method and recursive method.
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

int iterative(node* head){
    int len=0;
    while(head!=NULL){
        head = head->next;
        len++;
    }
    return len;
}

int recursive(node* head){
    if(head==NULL)							//base case
        return 0;
    return recursive(head->next)+1;
}

int main(){
    
    node* head=NULL;
    node* temp=NULL;
    int value,n;
    
    cout<<"Enter the no of numbers: ";
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
    
    cout<<"Printing the linked list: ";
    temp = head;
    for(int i=0;i<n;i++){
        cout<<temp->val<<"-->";
        temp = temp->next;
    }
    cout<<"|||\n";
    
    cout<<"Length of the linked list using iterative method: "<<iterative(head)<<"\n";
    
    cout<<"Length of the linked list using recursive method: "<<recursive(head)<<"\n";
    
    garbage(head);
    
    return 0;
}