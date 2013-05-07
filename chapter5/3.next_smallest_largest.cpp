#include <iostream>

using namespace std;

int get_next(int n) {
    if(n == 0) {
        return -1;
    }
    int num = n;
    int count0 = 0;
    int count1 = 0;
    while((num & 1) == 0) {
       count0++; 
       num >>= 1;
    }
    while((num & 1) == 1) {
        count1++;
        num >>= 1;
    }
    if(count0 + count1 == 32) {
        return -1;
    }
    // the number of ones become count1 - 1
    int result = n + (1 << count0) + (1 << (count1 - 1)) - 1;
    return result;
}

int main() {
    // the next largest of 1110(16) is 10011 (19)
    cout << get_next(14) << endl; 
    return 0;
}
