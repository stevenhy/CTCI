#include <iostream>
#include <string.h>
using namespace std;

bool isUnique(string s) {
    int a[8];
    memset(a, 0, 8*sizeof(int));
    for(int i = 0; i < s.size(); i++) {
        int v = (int)s[i];
        int offset = v/32;
        if(a[offset] & (1 << v%32)) {
        return false;
        } else {
            a[offset] |= 1 << v%32;
        }
    }
    return true;
}


int main () {
    string s1 = "hello there is repeat";
    string s2 = "world0614";
    cout << isUnique(s1) << endl;
    cout << isUnique(s2) << endl;
    return 0;
}
