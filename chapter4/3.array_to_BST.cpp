#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int pv):val(pv), left(NULL), right(NULL){}
};

TreeNode* helper(int* a, int start, int end) {
    if(start > end) {
        return NULL;
    }
    int mid = (start + end)/2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = helper(a, start, mid - 1);
    root->right = helper(a, mid + 1, end);
    return root;
}

TreeNode* create_BST(int* a, int length) {
    return helper(a, 0, length - 1);
}

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode* root = create_BST(a, 10);
    return 0;
}
