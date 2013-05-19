#include <iostream>
#include <vector>

using namespace std;

int magic_index(vector<int> vec, int start, int end) {
    if(start > end || start < 0 || end >= vec.size()){
        return -1;
    }
    int mid_i = (start + end)/2;
    int mid_v = vec[mid_i];
    if(mid_i == mid_v) {
        return mid_i;
    }
    int left_i = min(mid_i - 1, mid_v);
    int left = magic_index(vec, start, left_i);
    if(left >= 0) {
        return left;
    }
    int right_i = max(mid_i + 1, mid_v);
    int right= magic_index(vec, right_i, end);
    return right;
}

int main () {
    int a[7] = {1, 2, 3, 5, 6, 6, 6};
    vector<int> vec(a, a + sizeof(a)/sizeof(int));
    cout << magic_index(vec, 0, vec.size() - 1) << endl;
    return 0;
}
