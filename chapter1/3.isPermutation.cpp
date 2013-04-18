#include <iostream>
#include <string.h>

using namespace std; 

bool isPermutation(string s1, string s2){
    if(s1.size() != s2.size()) {
        return false;
    }
    int* check = new int[256];
    memset(check, 0, 256*sizeof(int));
    for(int i = 0; i < s1. size(); i++) {
        check[(int)s1[i]]++;
    }
    for(int j = 0; j < s2.size(); j++) {
        check[(int)s2[j]]--;
        if(check[(int)s2[j]] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "hello";
    string s2 = "elloh";
    string s3 = "elloe";
    cout << isPermutation(s1, s2) << endl;
    cout << isPermutation(s1, s3) << endl;
}
