#include <iostream>

using namespace std;

int swap(int x) {
    // bit are indexed 31, ..., 0
    // get the odd bits and right shift 1
    // get the even bits and left shift 1
    return ((x & 0xAAAAAAAA) >> 1 ) | ((x & 0x55555555) << 1);
}

int main() {
    int x = 10;
    cout << swap(x) << endl;
    return 0;
}
