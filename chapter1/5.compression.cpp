#include <iostream>
#include <string>
#include <sstream>

using namespace std; 

int check_size(string s) {
    if(s.size() == 0) {
        return 0;
    }
    char last = s[0];
    int count = 1;
    int size = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == last) {
            count++;
        } else {
            stringstream ss;
            ss << count;
            size += 1 + ss.str().size();
            last = s[i];
            count = 1;
        }
    }
    stringstream ss;
    ss << count;
    size += 1 + ss.str().size();
    return size;
}

string compression(string s) {
    int size = check_size(s);
    if(size >= s.size()) {
        return s;
    }
    string s2;
    int count = 1;
    char last = s[0];
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == last) {
            count++;
        } else {
            s2.push_back(last);
            stringstream ss;
            ss << count;
            s2 += ss.str();
            last = s[i];
            count = 1;
        }
    }
    s2.push_back(last);
    stringstream ss;
    ss << count;
    s2 += ss.str();
    return s2;
}

int main() {
    // perform compression
    string s1 = "aaaabbbcccdd";
    cout << s1 << endl;
    string s2 = compression(s1);
    cout << s2 << endl;
    // does not perform
    string s3 = "aaabbc";
    cout << s3 << endl;
    string s4 = compression(s3);
    cout << s4 << endl;
}
