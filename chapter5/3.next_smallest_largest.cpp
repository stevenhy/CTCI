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
        if(count1 + count0 >= 32) {
            return -1;
        }
        num >>= 1;
    }
    // the number of ones become count1 - 1
    int result = n + (1 << count0) + (1 << (count1 - 1)) - 1;
    return result;
}

int get_previous(int n) {
   if(n == 0 || n == -1) {
       return -1;
   }
   int num = n;
   int count0 = 0;
   int count1 = 0;
   while((num & 1) == 1) {
       count1++;
       num >>= 1;
   }
   if(num == 0) {
       return -1;
   }
   while((num & 1) == 0 && (num != 0)){
       count0++;
       num >>= 1;
   }
   int result = n - (1 << count1) - (1 << (count0 - 1)) + 1;
   return result;
}

int main() {
    cout << "Testing get_next ... " << endl; 
    // the next largest of 1110(16) is 10011 (19)
    cout << get_next(14) << endl; 
    // the next largest of 1....1 or 0 ... 0 should return error (-1)
    cout << get_next(-1) << endl; 
    cout << get_next(0) << endl; 
    cout << get_next(-1 ^ 3) << endl; 
    cout << "Testing get_previous ... " << endl; 
    // the next smallest of 10011(19) is 1110(16)
    cout << get_previous(19) << endl; 
    // the next smallest of 0...01...1 should return error (-1)
    cout << get_previous(3) << endl; 
    return 0;
}
