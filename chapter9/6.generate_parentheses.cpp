#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(string &s, int n, int l, int r, vector<string> &result) {
    if(l == n && r == n) {
        result.push_back(s);
        return;
    } else if (l == n && r < n) {
        s.push_back(')');
        dfs(s, n, l, r + 1, result);
        s.erase(s.end()-1);
    } else if (l < n && r < n) {
        s.push_back('(');
        dfs(s, n, l + 1, r, result);
        s.erase(s.end()-1);
        if(l > r) {
            s.push_back(')');
            dfs(s, n, l, r + 1, result);
            s.erase(s.end()-1);
        }
    }
}

// given n, the number of pairs, generate all possible valid parentheses 
vector<string> generateParenthesis(int n) {
    vector<string> result;
    if(n == 0) {
        return result;
    } 
    string s;
    dfs(s, n, 0, 0, result);
    return result;
}

int main() {
    vector<string> result = generateParenthesis(4);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
