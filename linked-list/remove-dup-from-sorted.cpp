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

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* sentinel = new ListNode();
  sentinel->val = 0;
  sentinel->next = head;

  ListNode* pred = sentinel;

  while (head != NULL) {
    if (head->next != NULL && head->val == head->next->val) {
      while (head->next != NULL && head->val == head->next->val) {
        head = head->next;
      }

      pred->next = head->next;
    }
    else {
      pred = pred->next;
    }

    head = head->next;
  }

  return sentinel->next;
}

int main() {
  ListNode* head = new ListNode();

  head->val = 1;
  head->next = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 4);
  head = push(head, 5);

  // printList(head);

  printList(deleteDuplicates(head));

  return 0;
}
