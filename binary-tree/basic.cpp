/* AUTHOR -- code_blooded */

/**
*
*	This program aims at creating, traversing and deleting a binary tree.
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

void inorder(node* root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL)  return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
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
    
    cout<<"PreOrder Traversal\n";
    preorder(root);
    cout<<"\n";
    
    cout<<"InOrder Traversal\n";
    inorder(root);
    cout<<"\n";
    
    cout<<"PostOrder Traversal\n";
    postorder(root);
    cout<<"\n";
    
    garbage(root);
    
    return 0;
}
