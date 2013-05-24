#include <iostream>

using namespace std;

int helper(int A[], int start, int end, int target) {
    if(start > end) {
        return -1;
    } else if(start == end) {
        return target == A[start]? start : -1;
    } 
    int mid = (start + end)/2;
    if(target == A[mid]) {
        return mid;
    }
    if(A[start] < A[mid]) {
        if(target >= A[start] && target <= A[mid]) {
            return helper(A, start, mid - 1, target);
        } else {
            return helper(A, mid+1, end, target);
        }
    } else if(A[start] > A[mid]){
        if(target >= A[mid] && target <= A[end]) {
            return helper(A, mid+1, end, target);
        } else {
            return helper(A, start, mid - 1, target);
        }
    } else {
        if(A[mid] != A[end]) {
            return helper(A, mid+1, end, target);
        } else {
            int result = helper(A, start, mid - 1, target);
            if(result != -1) {
                return result;
            } else {
                return helper(A, mid+1, end, target);
            }
        }
    }
}

// search in a rotated array, there might be duplicates
int search(int A[], int n, int target) {
    return helper(A, 0, n - 1, target);
}

int main() {
    int A[] = {5, 5, 5, 7, 8, 9, 1, 2, 3, 4, 5};
    cout << search(A, 11, 5) << endl;
    cout << search(A, 11, 2) << endl;
    return 0;
}
