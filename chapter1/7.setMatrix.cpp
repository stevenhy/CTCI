#include <iostream>
#include <vector>

using namespace std;

void set_zero(vector< vector<int> > &matrix) {
    int rows = matrix.size();
    if(rows == 0) {
        return;
    }
    int cols = matrix[0].size();
    if(cols == 0) {
        return;
    }
    bool set_row = false;
    bool set_col = false;
    // check if the first column/row should be set to zeros
    for(int i = 0; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            set_col = true;
        }
    }
    for(int j = 0; j < matrix[0].size(); j++) {
        if(matrix[0][j] == 0) {
            set_row = true;
        }
    }
    // if one element is zero set the corresponding elements in first row and first column to zero
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // set the matrix
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[0].size(); j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // set the first column and row to zeros if needed
    if(set_row) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
    }
    if(set_col) {
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
}

void print(vector< vector<int> > &matrix){
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector< vector<int> > matrix;
    int a[4] = {1, 1, 1, 1};
    int b[4] = {1, 0, 0, 1};
    vector<int> s1, s2;
    s1.assign(a, a+4);
    s2.assign(b, b+4);
    matrix.push_back(s1);
    matrix.push_back(s2);
    matrix.push_back(s1);
    matrix.push_back(s1);
    matrix.push_back(s2);
    cout << "before setting" << endl;
    print(matrix);
    set_zero(matrix);
    cout << "after setting" << endl;
    print(matrix);
    return 0;
}
