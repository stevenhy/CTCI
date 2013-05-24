// CC150 asks for permutations of a string
// this code implements permutations of an int array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int depth, vector<int>& solution, vector<int>& num, vector<vector<int> >& result, 
         vector<int>& canUse) {
    if(depth == num.size()) {
        result.push_back(solution);
        return;
    }
    for(int i = 0; i < num.size(); i++) {
        if(canUse[i] == 0) {
            if(i> 0 && num[i - 1] == num[i] && canUse[i-1] == 0) {
                continue;
            } else {
                canUse[i] = 1;
                solution.push_back(num[i]);
                dfs(depth+1, solution, num, result, canUse);
                solution.pop_back();
                canUse[i] = 0;
            }
        }
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > result;
     if(num.size() == 0 || num.size() == 1) {
        result.push_back(num);
        return result;
    }
    sort(num.begin(), num.end());
    vector<int> solution;
    vector<int> canUse(num.size(), 0);
    dfs(0, solution, num, result, canUse);
    return result;
}

int main() {
    vector<int> n(4, 1);
    permuteUnique(n);
    return 0;
}
