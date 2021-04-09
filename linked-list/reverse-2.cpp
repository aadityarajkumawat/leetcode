#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    int i = 1;
    ListNode* curr = head;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        if (i < left || i > right) {
            if (i < left) {
                curr = curr->next;
                i++;
            }
            else {
                
            }
        }
        else {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
    }
}

int main() {
    struct ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    return 0;
}
