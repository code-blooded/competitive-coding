/* AUTHOR -- code_blooded */

/**
*
*   This program aims at merging two sorted linked lists into a single sorted linked list.
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
        cout<<head->val<<"-->";
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

node* merge(node* left, node* right){
    if(left==NULL)          return right;
    if(right==NULL)         return left;
    node* head = NULL;
    node* temp = NULL;
    if(left->val < right->val){
        head = temp = left;
        left = left->next;
    }else{
        head = temp = right;
        right = right->next;
    }
    while(left!=NULL && right!=NULL){
        if(left->val < right->val){
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }else{
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
    }
    while(left!=NULL){
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while(right!=NULL){
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    return head;
}

/*
Sample Input
5
0 1 2 6 8
8
-2 0 4 5 7 9 10 25
*/

int main(){
    
    node* head1 = NULL;
    node* head2 = NULL;
    node* temp = NULL;
    int value,n;
    
    // scanning input
    cout<<"Enter the no of numbers for list 1: \n";
    cin>>n;
    cout<<"Enter the numbers in sorted order\n";
    for(int i=0;i<n;i++){
        cin>>value;
        if(temp==NULL){
            head1 = temp = newNode(value);
        }
        else{
            temp->next = newNode(value);
            temp = temp->next;
        }
    }
    temp = NULL;
    cout<<"Enter the no of numbers for list 2: \n";
    cin>>n;
    cout<<"Enter the numbers in sorted order\n";
    for(int i=0;i<n;i++){
        cin>>value;
        if(temp==NULL){
            head2 = temp = newNode(value);
        }
        else{
            temp->next = newNode(value);
            temp = temp->next;
        }
    }
    
    cout<<"Printing the linked list before merging\n";
    print(head1);
    print(head2);
    
    node* head = merge(head1,head2);
    
    cout<<"Printing the linked list after merging\n";
    print(head);
    
    // freeing the allocated memory
    garbage(head);
    
    return 0;
}