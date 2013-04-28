#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int pv):val(pv), left(NULL), right(NULL){}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(NULL){}
};

vector<ListNode*> BST_to_lists(TreeNode* root) {
    vector<ListNode*> result;
    if(!root) {
        return result;
    }
    vector<TreeNode*> vec;
    vec.push_back(root);
    int cur = 0;
    int last = 1;
    while(cur < vec.size()){
        last = vec.size();
        ListNode* first; 
        ListNode* previous;
        int start = cur;
        while(cur < last){
            ListNode* ln = new ListNode(vec[cur]->val);
            if(cur == start) {
                first = ln;
                previous = ln; 
            } else {
                previous->next = ln;
                previous = ln;
            }
            if(vec[cur]->left) {
                vec.push_back(vec[cur]->left);
            }
            if(vec[cur]->right) {
                vec.push_back(vec[cur]->right);
            }
            cur++;
        }
        result.push_back(first);
    }
    return result;
}

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

void print(ListNode* ln) {
    while(ln){
        cout << ln->val << " ";
        ln = ln->next;
    }
    cout << endl;
}

int main(){
    TreeNode* root = createTree();
    vector<ListNode*> result = BST_to_lists(root);
    int i = 0;
    while(i < result.size()) {
        print(result[i]);
        i++;
    }
    return 0;
}
