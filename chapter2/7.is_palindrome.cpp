#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
ListNode* create_list(int* a, int k) {
    ListNode* head;
    ListNode* p;
    for(int i = 0; i < k; i++) {
        if(i == 0) {
            p = new ListNode(a[i]);
            head = p;
        } else {
            ListNode* cur = new ListNode(a[i]);
            p->next = cur;
            p = cur;
        }
    }
    p->next = NULL;
    return head;
}

ListNode* reverse(ListNode* head) {
    ListNode* previous = NULL;
    ListNode* cur = head;
    while(cur) {
        ListNode* next = cur->next;
        cur->next = previous;
        previous = cur;
        cur = next;
    }
    return previous;
}

bool is_palindrome(ListNode* lshead) {
    ListNode* head = lshead;
    if(!head || !head->next) {
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) {
        slow = slow->next;
    }
    ListNode* head2 = reverse(slow);
    ListNode* save_head2 = head2;
    while(head2) {
        if(head->val != head2->val) {
            reverse(head2);
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    reverse(save_head2);
    return true;
}

void print(ListNode* lh) {
    ListNode* head = lh;
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int even[8] = {1, 2, 3, 4, 4, 3, 2, 1};
    int odd[7] = {1, 2, 3, 4, 3, 2, 1};
    ListNode* l1 = create_list(even, 8);
    ListNode* l2 = create_list(odd, 7);
    cout << "1st is_palindrome check is " << is_palindrome(l1) << endl;
    cout << "2nd is_palindrome check is " << is_palindrome(l2) << endl;
    l1->val = 5;
    cout << "3rd is_palindrome check is " << is_palindrome(l1) << endl;
    ListNode* l3 = create_list(even, 2);
    cout << "4th is_palindrome check is " << is_palindrome(l3) << endl;
    return 0;
}
