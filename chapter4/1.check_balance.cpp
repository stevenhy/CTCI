#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int pv):val(pv), left(NULL), right(NULL){}
};

// returns -1 if the tree which starts at root is an unbalanced tree
// otherwise returns the height of this tree
int check(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int lv = check(root->left);
    if(lv == -1) {
        return -1;
    }
    int rv = check(root->right);
    if(rv == -1 || abs(lv -rv)) {
        return -1;
    }
    return lv > rv? lv + 1: rv + 1;
}

bool is_balanced(TreeNode* root){
    int v = check(root); 
    return v != -1;
} 

int main(){
    TreeNode* t1 = new TreeNode(0);
    TreeNode* t2 = new TreeNode(0);
    TreeNode* t3 = new TreeNode(0);
    t1->left = t2;
    t1->right = t3;
    cout << "check result is " << is_balanced(t1) << endl;
    TreeNode* t4 = new TreeNode(0);
    t1->left = NULL;
    t1->right->left = t4;
    cout << "check result is " << is_balanced(t1) << endl;
    return 0;
}
