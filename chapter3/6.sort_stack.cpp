#include <iostream>
#include <stack>

using namespace std;

stack<int> sort_stack(stack<int> s) {
    stack<int> helper;
    while(!s.empty()) {
       int tmp = s.top(); 
       s.pop();
       while(!helper.empty() && helper.top() > tmp) {
            s.push(helper.top());
            helper.pop();
       }
       helper.push(tmp);
    }
    return helper;
}

int main() {
    stack<int> mys;
    int a[8] = {9, 7, 6, 13, 2, 3, 100, 1};
    cout << "original stack is: " << endl;
    for(int i = 0; i < 8; i++) {
        mys.push(a[i]);
        cout << " " << a[7-i];
    }
    cout << endl;
    stack<int> s = sort_stack(mys);
    cout << "sorted stack is: " << endl;
    while(!s.empty()){
        int v = s.top();
        cout << " " << v;
        s.pop();
    }
        cout << endl;
    return 0;
}

