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

int getLengthOfList(ListNode* head) {
  int length = 0;
  while (head != NULL) {
    head = head->next;
    length++;
  }

  return length;
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
// index(req) = length - n + 1 = 4
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* ptr = head;
  ListNode* qtr = NULL;
  int index = 1;
  int length = getLengthOfList(head);
  if (length == 1 && n == 1) {
    return NULL;
  }
  if(length - n == 0) {
    head = head->next;
    return head;
  }
  while (index != length - n) {
    ptr = ptr->next;
    index++;
  }

  qtr = ptr->next;
  ptr->next = qtr->next;

  free(qtr);
  return head;
}

int main() {
  ListNode* head = new ListNode();
  head->val = 1;
  head->next = NULL;
  head = push(head, 2);
  // head = push(head, 3);
  // head = push(head, 4);
  // head = push(head, 5);

  printList(head);
  head = removeNthFromEnd(head, 2);
  printList(head);
  return 0;
}
