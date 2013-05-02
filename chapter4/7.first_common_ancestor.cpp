#include <iostream>
#include <stdlib.h>

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

bool check(TreeNode* root, TreeNode* node) {
    if(!root){
        return false;
    }
    if(root == node) {
        return true;
    }
    return check(root->left, node) || check(root->right, node);
}

// first check if the two nodes are in the tree
// then check if one node is the ancestor of the other
// then check first common ancestor
TreeNode* common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!check(root, p) || !check(root, q)) {
        return NULL;
    }    
    if(check(p, q)) {
        return p;
    }
    if(check(q, p)) {
        return q;
    }
    TreeNode* check_left = common_ancestor(root->left, p, q);
    if(check_left != NULL && check_left != p && check_left != q) {
        return check_left;
    }
    TreeNode* check_right = common_ancestor(root->right, p, q);
    if(check_right != NULL && check_right != p && check_right != q) {
        return check_right;
    }
    return root;
}

int main() {
    TreeNode* root = createTree();
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* result = common_ancestor(root, p, q);
    cout << result->val << endl;
    return 0;
}
