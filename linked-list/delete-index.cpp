/* AUTHOR -- code_blooded */

/**
*
*	This program aims at deleting the mth-indexed(0-based) node of linked list.
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

node* delNode(node* head, int m){
    node* temp = head;
    if(m==0){                            //deleting the head
        temp = head->next;
        delete head;
        return temp;
    }
    for(int i=0;i<m-1;i++){
        temp = temp->next;
    }
    node* temp1 = temp;                  // previous
    node* temp2 = temp->next;            // node to be deleted
    node* temp3 = temp->next->next;      // next node
    delete temp2;
    temp1->next = temp3;
    return head;
}

void garbage(node* head){
    while(head){
        node* temp=head->next;
        delete head;
        head = temp;
    }
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
    
    cout<<"Before deleting the linked list is\n";
    temp = head;
    for(int i=0;i<n;i++){
        cout<<temp->val<<"-->";
        temp = temp->next;
    }
    cout<<"|||\n";
    
    int m;
    cout<<"Enter the index(0-based) of the node to be deleted: \n";
    cin>>m;
    head = delNode(head,m);
    
    cout<<"After deleting the linked list is\n";
    temp = head;
    for(int i=0;i<n-1;i++){
        cout<<temp->val<<"-->";
        temp = temp->next;
    }
    cout<<"|||\n";
    
    garbage(head);
    
    return 0;
}
