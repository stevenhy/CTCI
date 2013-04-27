#include <iostream>
#include <stack>

using namespace std;

struct op{
    int begin, end;
    char src, mid, des;
    op() {}
    op(int pb, int pe, int ps, int pm, int pd): 
        begin(pb), end(pe), src(ps), mid(pm), des(pd){
        }
};

void hanoi_recursive(int n, char src, char mid, char des) {
    if(n == 0) {
        return;
    } else if(n == 1) {
        cout << "move disk " << n << " from " << src << " to " << des << endl;
    } else {
        hanoi_recursive(n-1, src, des, mid);
        cout << "move disk " << n << " from " << src << " to " << des << endl;
        hanoi_recursive(n-1, mid, src, des);
    }
    
}

void hanoi_stack(int n) {
    if(n <= 0) {
        return;
    }
    stack<op> s;
    op tmp;
    s.push(op(1, n, 'a', 'b', 'c'));
    while(!s.empty()) {
        tmp = s.top();
        s.pop();
        if(tmp.begin == tmp.end) { 
            cout << "move disk " << tmp.end << " from " << tmp.src << " to " << tmp.des << endl;
        } else {
            s.push(op(tmp.begin, tmp.end-1, tmp.mid, tmp.src, tmp.des));
            s.push(op(tmp.end, tmp.end, tmp.src, tmp.mid, tmp.des));
            s.push(op(tmp.begin, tmp.end-1, tmp.src, tmp.des, tmp.mid));
        }
    }
}

int main() {
    int n  = 3;
    hanoi_recursive(n, 'a', 'b', 'c'); 
    cout << "below is non-recursive result" << endl;
    hanoi_stack(n); 
}
