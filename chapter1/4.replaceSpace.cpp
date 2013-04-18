#include <iostream>
#include <string.h>

using namespace std; 

void replaceSpace(string &s, int length) {
    int newLength = 0;
    int spaceCount = 0;
    for(int i = 0; i < length; i++) {
        if(s[i] == ' ') {
            spaceCount++;
        }
    }
    newLength = length + 2*spaceCount;
    s[newLength--] = '\0';
    for(int i = length - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            s[newLength--] = '0';
            s[newLength--] = '2';
            s[newLength--] = '%';
        } else {
            s[newLength--] = s[i];
        }
    }
}

int main() {
    string s1 = "hello world GitHub123456";
    cout << s1 << endl;
    replaceSpace(s1, 18);
    cout << s1 << endl;
}
