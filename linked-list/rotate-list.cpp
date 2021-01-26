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

ListNode* rotateOne(ListNode* head) {
  ListNode* h = head;
  ListNode* ptr = NULL;
  ListNode* qtr = NULL;

  while (h != NULL) {
    ptr = h;
    h = h->next;
  }

  h = head;

  while (h->next != NULL) {
    qtr = h;
    h = h->next;
  }

  ptr->next = head;
  qtr->next = NULL;

  return ptr;
}

ListNode* rotateRight(ListNode* head, int k) {
  int len = 0;
  ListNode* ptr = head;
  while (ptr != NULL) {
    len++;
    ptr = ptr->next;
  }
  if (len == 0) {
    return head;
  }
  for (int i = 0;i < (k % len);i++) {
    head = rotateOne(head);
  }

  return head;
}

int main() {
  ListNode* head = new ListNode();

  head->next = NULL;
  head->val = 1;

  head = push(head, 2);
  head = push(head, 3);
  // head = push(head, 4);
  // head = push(head, 5);

  printList(head);

  head = rotateRight(head, 2000000000);

  printList(head);

  return 0;
}
