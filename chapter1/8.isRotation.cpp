#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2) {
    return (s2.find(s1) != string::npos);
}

bool isRotation(string s1, string s2) {
    if(s1.size() != s2.size()) {
        return false;
    }
    string s3 = s1 + s1;
    return isSubstring(s2, s3); 
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << isRotation(s1, s2) << endl;
    return 0;
}
