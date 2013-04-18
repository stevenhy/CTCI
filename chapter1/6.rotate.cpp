#include <iostream>

using namespace std;

void rotate(int (&a)[3][3], int size){
    if(size == 0 || size == 1) {
        return;
    }
    // rotate line is diagonal 
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    // rotate line is column == size/2
    for(int j = 0; j < size/2; j++) {
        for(int i = 0; i < size; i++) {
            int temp = a[i][j];
            a[i][j] = a[i][size - 1 - j];
            a[i][size - 1 - j] = temp;
        }
    }
}

void print(int (&a)[3][3], int size){
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[3][3] = {{1, 2 , 3}, {4, 5, 6}, {7, 8, 9}};
    int size = 3;
    print(a, size);
    rotate(a, size);
    print(a, size);
}
