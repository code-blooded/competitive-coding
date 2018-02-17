/* AUTHOR -- code_blooded */

/**
*
*	This program aims at finding the height of a binary tree recursively.
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

int height(node* root){
    if(root==NULL)  return NULL;
    return max(height(root->left),height(root->right))+1;
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
    //       /
    //      7

    node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    
    cout<<"Height of the binary tree: ";
    cout<<height(root);
    cout<<"\n";
    
    garbage(root);
    
    return 0;
}