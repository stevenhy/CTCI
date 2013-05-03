#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int pv):val(pv), left(NULL), right(NULL){}
};

/* create a tree like following
   6
 3   9
1 4 1 11
*/
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
    TreeNode* t6 = new TreeNode(1);
    TreeNode* t7 = new TreeNode(11);
    t3->left = t6;
    t3->right = t7;
    return t1;
}

bool match(TreeNode* p, TreeNode* q) {
    if(!p && !q) {
        return true;
    }
    if(!p || !q) {
        return false;
    }
    if(p->val != q->val) {
        return false;
    }
    return match(p->left, q->left) && match(p->right, q->right);
}

// finds if there exists a node in p such that the subtree of the node is identical to q
// (p contains q)
// the key idea is each time a node in p matachs the root of q, call match() to compare 
bool is_subtree(TreeNode* p, TreeNode* q) {
    if(!q) {
        return true;
    }
    if(!p) {
        return false;
    }
    if(p->val == q->val) {
        if(match(p, q)) {
            return true;
        }
    }
    return is_subtree(p->left, q) || is_subtree(p->right, q);
}

int main(){
    TreeNode* root = createTree();
    TreeNode* root2 = createTree();
    cout << is_subtree(root, root2) << endl;
    root2->val = -9;
    cout << is_subtree(root, root2) << endl;
    return 0;
}
