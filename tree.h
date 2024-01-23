#ifndef TREE_H
#define TREE_H
#include<bits/stdc++.h>
using namespace std;
template <class T>
class TreeNode{
public:
    TreeNode* right;
    TreeNode* left;
    TreeNode* parent;
    int key;
    int height;
    T data;
    TreeNode(){
    right = left = parent = NULL;
    }


};
template <class T>
class Tree
{
    public:
        TreeNode root;
        Tree(){root=NULL}
        bool isEmpty(){
            if(root == NULL){
                return true;
            }
            else{
                return false;
            }
        }




};

#endif // TREE_H
