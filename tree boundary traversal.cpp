#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *left;
    int data;
    Node *right;
    
};

    //travese in left subtree excluding leaf nodes
    void traverse_left(Node *root,vector<int> &ans){
        //base case
        if(root==NULL || root->left==NULL && root->right==NULL){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            traverse_left(root->left,ans);
        }
        else{
             traverse_left(root->right,ans);
        }
    }
    
        //traversing leaf nodes
    void traverse_leaf(Node *root,vector<int> &ans){
        //base case
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverse_leaf(root->left,ans);
        traverse_leaf(root->right,ans);
    }
       
        //traversing right subtree in reverese order
    void traverse_right(Node *root,vector<int> &ans){
         //base case
        if(root==NULL || root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right){
            traverse_right(root->right,ans);
            
        }
        else{
            traverse_right(root->left,ans);
        }
        //here reverse me print karna h so return hote time print karwaya h last me
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //travese in left subtree excluding leaf nodes
        traverse_left(root->left,ans);
        //traversing left subtree leaf nodes
        traverse_leaf(root->left,ans);
        //traversing right subtree leaf nodes
        traverse_leaf(root->right,ans);
        //traversing right subtree in reverese order
        traverse_right(root->right,ans);
        return ans;
    }
