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

ListNode* partition(ListNode* head, int x) {
  ListNode* before_head = new ListNode();
  before_head->val = 0;
  before_head->next = NULL;
  ListNode* before = before_head;
  ListNode* after_head = new ListNode();
  after_head->val = 0;
  after_head->next = NULL;
  ListNode* after = after_head;

  while (head != NULL) {
    if (head->val < x) {
      before->next = head;
      before = before->next;
    }
    else {
      after->next = head;
      after = after->next;
    }
    head = head->next;
  }

  after->next = NULL;
  before->next = after_head->next;

  return before_head->next;
}

int main() {
  ListNode* head = new ListNode();
  int x = 3;

  head->val = 1;
  head->next = NULL;

  head = push(head, 4);
  head = push(head, 3);
  head = push(head, 2);
  head = push(head, 5);
  head = push(head, 2);

  // printList(head);
  printList(partition(head, x));


  return 0;
}