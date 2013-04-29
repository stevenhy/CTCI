#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int pv):val(pv), left(NULL), right(NULL){}
};


TreeNode* createTree() {
    TreeNode* t1 = new TreeNode(6);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(9);
    t1->left = t2;
    t1->right = t3;
    TreeNode* t4 = new TreeNode(1);
    TreeNode* t5 = new TreeNode(4);
    t2->left = t4;
    t2->right = t5;
    TreeNode* t6 = new TreeNode(7);
    TreeNode* t7 = new TreeNode(11);
    t3->left = t6;
    t3->right = t7;
    return t1;
}

// there are two ways to validate the BST:
// 1. give min and max for every node, as the recursion goes down in the tree, 
// the bounds become tighter. If node->val <= min or >= max, return false.
//
// 2. do a in-order traversal of the tree. Keep track of the last visited value. 
// If the current value is smaller than or equal to the previous value, return 
// false.
bool helper1(TreeNode* root, int min, int max) {
    if(!root) {
        return true;
    }
    if(root->val <= min || root->val >= max) {
        return false;
    }
    bool f1 = helper1(root->left, min, root->val);
    if(!f1) {
        return false;
    }
    bool f2 = helper1(root->right, root->val, max);
    if(!f2) {
        return false;
    }
    return true;
}

bool check_BST1(TreeNode* root){
    return helper1(root, INT_MIN, INT_MAX);
}

bool helper2(TreeNode* root, int &last) {
    if(!root) {
        return true;
    }
    if(root->left) {
        bool f1 = helper2(root->left, last);
        if(!f1) {
            return false;
        }
    }
    if(root->val <= last) {
        return false;
    }
    last = root->val;
    if(root->right) {
        bool f2 = helper2(root->right, last);
        if(!f2) {
            return false;
        }
    }
    return true;
}

bool check_BST2(TreeNode* root) {
    int last = INT_MIN;
    return helper2(root, last);
}

int main(){
    TreeNode* root = createTree();
    cout << check_BST2(root) << endl;
    return 0;
}
