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

void print(vector<int> myv) {
    for(int i = 0; i < myv.size(); i++) {
        cout << myv[i] << " ";
    }
    cout << endl;
}

// the key is to memorize the value along the path as the DFS goes down in the tree
void path_sum(TreeNode* root, int sum, vector<int>& path, vector< vector<int> >& result) {
    if(!root) {
        return;
    }
    int v = 0;
    path.push_back(root->val);
    for(int i = path.size() - 1; i >= 0; i--) {
        v += path[i];
        if(v == sum) {
            // copy the partial path and push it to result
            vector<int> tmp (path.end() - path.size() + i, path.end());
            result.push_back(tmp);
        }
    }
    if(root->left) {
        path_sum(root->left, sum, path, result);
    }
    if(root->right) {
        path_sum(root->right, sum, path, result);
    }
    path.pop_back();

}

int main(){
    TreeNode* root = createTree();
    int sum = 10;
    vector<vector<int> > result;
    vector<int> path;
    path_sum(root, sum, path, result);
    for(int i = 0; i < result.size(); i++) {
        print(result[i]);
    }
    return 0;
}
