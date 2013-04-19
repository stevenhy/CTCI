#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void remove(ListNode* head) {
    if(!head || !head->next) {
        return;
    }
    ListNode** phead = &head;
    unordered_map<int, int> mymap;
    while(*phead) {
       unordered_map<int, int>::iterator got = mymap.find((*phead)->val); 
       if(got == mymap.end()) {
            mymap[(*phead)->val] = 1; 
            phead = &((*phead)->next);
       } else {
            *phead = (*phead)->next;
       }
    }
}

int main() {
    int a[8] = {1, 2, 3, 4, 2, 4, 1, 0};
    ListNode* head;
    ListNode* p;
    for(int i = 0; i <8; i++) {
        if(i == 0) {
            p = new ListNode(a[i]);
            head = p;
        } else {
            ListNode* cur = new ListNode(a[i]);
            p->next = cur;
            p = cur;
        }
    }
    p->next= NULL;
    ListNode* node = head;
    while(node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    remove(head); 
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
}
