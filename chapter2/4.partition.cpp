#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
ListNode* partition(ListNode* head, int k) {
    if(!head || !head->next) {
        return head;
    }
    ListNode** fp = &head;
    ListNode** sp = NULL;
    ListNode* first = NULL;
    ListNode* second = NULL;
    while(*fp){
        int num = (*fp)->val;
        if(num < k) {
            if(!first) {
                first = *fp;
            }
            fp = &((*fp)->next);
        } else {
            if(!second) {
                second = *fp;
                sp = &second;
            } else { 
                (*sp)->next = *fp;
                sp = &((*sp)->next);
            }
            *fp = (*fp)->next;
            (*sp)->next = NULL;
        }
    }
    if(!first) {
        return second;
    } else {
        *fp = second;
        return first;
    }
}

void print_list(ListNode* head) {
    ListNode* node = head;
    cout << "print the list" << endl;
    while(node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
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
    print_list(head);
    ListNode* new_head = partition(head, 3);
    print_list(new_head);
}
