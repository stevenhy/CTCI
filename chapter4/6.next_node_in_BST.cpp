#include <iostream>
#include <stdlib.h>
#include <climits>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int pv):val(pv), left(NULL), right(NULL), parent(NULL){}
};

/* create a tree like following
   6
 3   9
1 4 7 11
*/
TreeNode* createTree() {
    TreeNode* t1 = new TreeNode(6);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(9);
    t1->left = t2;
    t1->right = t3;
    t2->parent = t1;
    t3->parent = t1;
    TreeNode* t4 = new TreeNode(1);
    TreeNode* t5 = new TreeNode(4);
    t2->left = t4;
    t2->right = t5;
    t4->parent = t2;
    t5->parent = t2;
    TreeNode* t6 = new TreeNode(7);
    TreeNode* t7 = new TreeNode(11);
    t3->left = t6;
    t3->right = t7;
    t6->parent = t3;
    t7->parent = t3;
    return t1;
}

TreeNode* left_most_child(TreeNode* root) {
    if(!root) {
        return root;
    }
    TreeNode* cur = root;
    while(cur->left) {
        cur = cur->left;
    }
    return cur;
}

TreeNode* next_node(TreeNode* root) {
    if(!root) {
        return NULL;
    }
    if(root->right) {
        return left_most_child(root->right);
    } else {
        TreeNode* p = root->parent;
        TreeNode* cur = root;
        while(p && (cur != p->left)) {
            cur = p;
            p = cur->parent;
        }
       return p; 
    }
}

int main(){
    TreeNode* root = createTree();
    assert(next_node(root->right->right) == NULL);
    cout << next_node(root->left->right)->val << endl;
    return 0;
}
