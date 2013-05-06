#include <iostream>

using namespace std;

int insert(int N, int M, int i, int j) {
    int v = M << i;
    int ones = ~0;    
    int left = ones << (j+1);
    int right = (ones << i) - 1;
    int mask = left | right;
    int m = N & mask;
    return v | m;
}

int main() {
    int N = 1 << 10;
    int M = 19;
    int i = 2;
    int j = 6;
    int result = insert(N, M, i, j);
    cout << hex << N << endl; 
    cout << hex << M << endl; 
    cout << hex << result << endl; 
    return 0;
}
