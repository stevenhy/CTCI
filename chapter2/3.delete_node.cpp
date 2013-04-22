#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
void print_list(ListNode* head) {
    ListNode* node = head;
    cout << "print the list" << endl;
    while(node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void delete_node(ListNode* middle){
    if(!middle || !middle->next) {
       middle = NULL; 
    }
    ListNode** p = &middle;
    while((*p)->next) {
        (*p)->val = (*p)->next->val;
        p = &((*p)->next);
    }
    *p = NULL;
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
    delete_node(head->next->next);
    print_list(head);
}
