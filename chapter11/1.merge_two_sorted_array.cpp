#include <iostream>

using namespace std;

// assume A has enough space to hold elements in B
void merge(int A[], int m, int B[], int n) {
    int last = m + n -1;
    int lastA = m - 1;
    int lastB = n - 1;
    while(lastA >= 0 && lastB >=0) {
        if(A[lastA] > B[lastB]) {
            A[last] = A[lastA];
            last--;
            lastA--;
        } else {
            A[last] = B[lastB];
            last--;
            lastB--;
        }
    }
    while(lastB >= 0) {
        A[last] = B[lastB];
        last--;
        lastB--;
    }
    for(int i = 0; i < m+n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[20] = {1, 5 , 99, 100};
    int B[] = {11, 12, 13, 14};
    merge(A, 4, B, 4);
    return 0;
}
