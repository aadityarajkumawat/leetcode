/**
* Practice Everyday
*/
#include <iostream>

class ListNode {
public:
  int val;
  ListNode* next;
};

void printList(ListNode* head) {
  while (head != NULL) {
    if (head->next == NULL) {
      std::cout << head->val << " ";
    }
    else {
      std::cout << head->val << "->";
    }

    head = head->next;
  }
  std::cout << std::endl;
}

ListNode* push(ListNode* head, int val) {
  ListNode* newNode = new ListNode();
  ListNode* ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  newNode->val = val;
  newNode->next = NULL;
  ptr->next = newNode;

  return head;
}

ListNode* swapNodes(ListNode* head) {
  ListNode* ptr = head;
  while (ptr->next != NULL) {
    int temp = ptr->val;
    ptr->val = ptr->next->val;
    ptr->next->val = temp;
    ptr = ptr->next;
    if (ptr->next != NULL) {
      ptr = ptr->next;
    }
  }

  return head;
}
// 1->2->3->4->NULL
int main() {
  ListNode* head = new ListNode();
  head->val = 1;
  head->next = NULL;
  head = push(head, 2);
  head = push(head, 3);
  // head = push(head, 4);

  head = swapNodes(head);
  printList(head);

  return 0;
}
