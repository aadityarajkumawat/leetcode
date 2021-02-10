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

int getVal(ListNode* head, int i) {
  int j = 1;
  int n = 0;
  while (j <= i) {
    if (j == i) {
      n = head->val;
    }
    j++;
    head = head->next;
  }

  return n;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode* p = head;
  int len = 0;
  while (p != NULL) {
    len++;
    p = p->next;
  }

  ListNode* m_node = head;
  ListNode* n_node = head;
  ListNode* ptr = head;

  int i = 1;
  while (i <= len) {
    if (i == m) {
      m_node = ptr;
    }
    else if (i == n) {
      n_node = ptr;
    }
    ptr = ptr->next;
    i++;
  }

  // int low = 

  return head;
}

int main() {
  ListNode* head = new ListNode();
  head->val = 1;
  head->next = NULL;
  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);

  printList(head);
  // head = reverseBetween(head, 2, 4);

  int s = getVal(head, 3);
  std::cout << s << std::endl;

  return 0;
}
