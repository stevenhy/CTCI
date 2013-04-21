#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
void find_k(ListNode* head, int k) {
    ListNode* slow = head;
    ListNode* fast = head;
    for(int i = 0; i < k - 1; i++) {
        if(fast == NULL) {
            cout << "out of index" << endl;
            return;
        }
        fast = fast->next;
    }
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    cout << "kth node to the last is " << slow->val << endl;
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
    cout << "print the list" << endl;
    while(node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    find_k(head, 4);
}
