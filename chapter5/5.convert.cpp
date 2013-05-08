#include <iostream>

using namespace std;

int convert(int a, int b) {
    int c = a ^ b; 
    int count = 0;
    while(c != 0) {
        count++;
        // clear the least significant 1 in c
        c = c &(c - 1);
    }
    return count;
}

int main() {
    int a = 14;
    int b = 1;
    cout << convert(a, b) << endl;
    return 0;
}
