#include <iostream>

using namespace std;

int count_recursion(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return count_recursion(n-1) + count_recursion(n-2) + count_recursion(n-3);
    }
}

int count_DP(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } 
    int s1 = 0, s2 = 1, s3 = 1;
    for(int i = 2; i <= n; i++) {
        int v = s1 + s2 + s3;
        s1 = s2;
        s2 = s3; 
        s3 = v;    
    }
    return s3;
}

int main() {
    cout << "Calculating clibing 11 step staircase" << endl;
    cout << count_recursion(11) << endl;
    cout << count_DP(11) << endl;
    return 0;
}
