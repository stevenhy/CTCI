#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue{
private: 
    stack<T> s1, s2;

public:
    void push(T val) {
        s1.push(val);
    }

    void pop() {
        if(!s2.empty()) {
            s2.pop();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    T back() {
        if(!s1.empty()) {
           return s1.top(); 
        } else {
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            return s1.top();
        }
    }

    T front() {
        if(!s2.empty()) {
            return s2.top();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};

int main() {
    MyQueue<int> myq;
    for(int i = 1; i < 9; i++) {
        myq.push(i);
    }
    cout << "front is " << myq.front() << endl;
    cout << "back is " << myq.back() << endl;
    myq.pop();
    myq.push(9);
    cout << "now front is " << myq.front() << endl;
    cout << "now back is " << myq.back() << endl;
    return 0;
}

