/* AUTHOR -- code_blooded */

/**
*
*	This program prints the level order traversal of a binary tree in O(n).
*
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

node* newNode(int val){
    node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->val = val;
    return temp;
}

void levelorder(node* root){
    if(root==NULL)  return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* first = q.front();
        cout<<first->val<<" ";
        if(first->left!=NULL)       q.push(first->left);
        if(first->right!=NULL)      q.push(first->right);
        q.pop();
    }
}

void garbage(node* root){
    if(root==NULL)  return;
    garbage(root->left);
    garbage(root->right);
    delete root;
}

int main(){

    // The tree created is shown below
    //       0
    //      / \
    //    1     2
    //   / \   / \
    //  3   4 5   6

    node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    
    cout<<"LevelOrder Traversal\n";
    levelorder(root);
    cout<<"\n";
    
    garbage(root);
    
    return 0;
}