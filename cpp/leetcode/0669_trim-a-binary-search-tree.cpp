#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode *trimBST(TreeNode *root, int low, int high) {
    if(!root) return nullptr;
    if(root->val<low){
        return trimBST(root->right,low,high);
    }
    if(root->val>high){
        return trimBST(root->left,low,high);
    }
    root->left = trimBST(root->left,low,high);
    root->right = trimBST(root->right,low,high);

    return root;
}