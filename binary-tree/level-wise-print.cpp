/* AUTHOR -- code_blooded */

/**
*
*	This program prints the nodes of a binary tree level-wise.
*
*/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

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
    queue<pair<node*,int>> q;
    q.push(mp(root,1));
    int prev = 1;
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        if(temp.second!=prev){
            prev = temp.second;
            cout<<"\n";
        }
        cout<<temp.first->val<<" ";
        if(temp.first->left!=NULL)       q.push(mp(temp.first->left,temp.second+1));
        if(temp.first->right!=NULL)      q.push(mp(temp.first->right,temp.second+1));
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
    //     \   / \
    //      4 5   6

    node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    
    cout<<"LevelOrder Traversal\n";
    levelorder(root);
    cout<<"\n";
    
    garbage(root);
    
    return 0;
}