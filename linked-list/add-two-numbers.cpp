/**
* Practice Everyday
*/
#include <iostream>

class Node {
public:
  int data;
  Node* next;
};

void printList(Node* head) {
  while (head != NULL) {
    if (head->next == NULL) {
      std::cout << head->data << " ";
    }
    else {
      std::cout << head->data << "->";
    }

    head = head->next;
  }
  std::cout << std::endl;
}

Node* push(Node* head, int val) {
  Node* newNode = new Node();
  Node* ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  newNode->data = val;
  newNode->next = NULL;
  ptr->next = newNode;

  return head;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
  Node* sumNode = new Node();
  int carry = 0;
  while (l1 != NULL || l2 != NULL) {
    if (l1 == NULL) {
      sumNode = push(sumNode, (l2->data + carry) % 10);
      carry = (l2->data + carry) / 10;
      if (l2->next == NULL && carry > 0) {
        sumNode = push(sumNode, carry);
      }
      l2 = l2->next;
    }
    else if (l2 == NULL) {
      sumNode = push(sumNode, (l1->data + carry) % 10);
      carry = (l1->data + carry) / 10;
      if (l1->next == NULL && carry > 0) {
        sumNode = push(sumNode, carry);
      }
      l1 = l1->next;
    }
    else {
      int s = l1->data + l2->data + carry;
      carry = s / 10;
      sumNode = push(sumNode, s % 10);
      if (l1->next == NULL && l2->next == NULL) {
        sumNode = push(sumNode, carry);
      }
      l1 = l1->next;
      l2 = l2->next;
    }
  }

  return sumNode->next;
}

int main() {
  Node* l1 = new Node();
  Node* l2 = new Node();

  l1->data = 5;
  l1->next = NULL;

  l2->data = 5;
  l2->next = NULL;

  printList(l1);
  printList(l2);

  Node* d = addTwoNumbers(l1, l2);
  printList(d);

  return 0;
}