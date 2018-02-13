/* AUTHOR -- code_blooded */

/**
*
*	This program aims at swapping two nodes in a linked list.
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
    if(x<0){
        return NULL;
    }
    while(x--){
        head = head->next;
    }
    return head;
}

node* swap(node* head, int u, int v){
    
    if(u==v)    return head;               //both are same no swap required
    
    if(v==0){   
        int temp = v;
        v = u;
        u = temp;
    }
    
    if(u==0){                              //if u node is the head
    
        node* prior_v = find_iterative(head,v-1);      //the node before v
        node* at_v = prior_v->next;                    //the node at v
        node* post_v = at_v->next;                     //the node after v
        node* at_u = head;
        
        at_v->next = at_u->next;
        prior_v->next = at_u;
        at_u->next = post_v;
        
        return at_v;                                   //return new head i.e v
        
    }
    
    node* prior_u = find_iterative(head,u-1);      //the node before u
    node* prior_v = find_iterative(head,v-1);      //the node before v
    node* at_u = prior_u->next;                    //the node at u
    node* at_v = prior_v->next;                    //the node at v
    node* post_v = at_v->next;                     //the node after v
    
    prior_u->next = at_v;
    prior_v->next = at_u;
    at_v->next = at_u->next;
    at_u->next = post_v;
    
    return head;
}

void print(node* head){
    cout<<"Printing the linked list: \n";
    while(head){
        cout<<head->val<<"-->";
        head = head->next;
    }
    cout<<"|||\n";
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
    
    print(head);                                    //print prior swap
    
    int u,v;
    cout<<"Enter the index of the nodes to be swapped: \n";
    cin>>u;
    cin>>v;
    head = swap(head,u,v);
    
    print(head);                                    //print post swap
    
    garbage(head);
    
    return 0;
}