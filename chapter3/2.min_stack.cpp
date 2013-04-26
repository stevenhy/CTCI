#include <iostream>
#include <stack>
#include <climits>

using namespace std;

template <typename T>
class my_stack {
private:
    stack<T> s;
    stack<T> min_s;
public:
    T min() {
        if(min_s.empty()) {
            return INT_MAX;
        } else {
            return min_s.top();
        }
    }

    void push(T v) {
        if(v <= min()) {
            min_s.push(v);
        }
        s.push(v);
    }

    T top(){
      return s.top();  
    }

    void pop() {
        T v = s.top();
        if(v == min()) {
            min_s.pop();
        }
        s.pop();
    }
};

int main() {
    my_stack<int> ms;    
    ms.push(2);
    ms.push(4);
    ms.push(1);
    cout << "min is " << ms.min() << endl;
    ms.pop();
    cout << "now min is " << ms.min() << endl;
}
