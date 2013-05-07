#include <iostream>
#include <string>

using namespace std;

string binary(double num) {
    if(num <= 0 || num >= 1) {
        return "ERROR";
    }
    double base = 0.5;
    string result;
    result.push_back('.');
    int count = 0;
    while(num > 0){
       if(count > 32) {
            return "ERROR";
       }
       if(num >= base) {
           result.push_back('1');
           num -= base;
       } else {
           result.push_back('0');
       } 
       base = base/2;
       count++;
    }
    return result;
}

int main() {
    cout << binary(1) << endl; 
    cout << binary(0.72) << endl; 
    cout << binary(0.625) << endl; 
    return 0;
}
