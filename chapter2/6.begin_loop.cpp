#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
ListNode* begin_loop(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            break;
        }
    }
    if(!fast || !fast->next) {
        return NULL;
    }
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    p->next= head->next->next;
    //p->next= NULL;
    ListNode* begin = begin_loop(head);
    cout << "begin loop value is " << begin->val << endl;
}
