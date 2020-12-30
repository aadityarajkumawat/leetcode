/**
* Practice Everyday
*/
#include <iostream>

class Node {
public:
  int data;
  Node* next;
};

void traverseLinkedList(Node* head) {
  while (head != NULL) {
    if (head->next == NULL) {
      std::cout << head->data << "";
    }
    else {
      std::cout << head->data << "->";
    }
    head = head->next;
  }
  std::cout << std::endl;
}

Node* mergeTwoLists(Node* l1, Node* l2) {
  

  return l1;
}

int main() {
  Node* l1 = new Node();
  Node* ll1 = new Node();
  Node* ll2 = new Node();

  l1->data = 1;
  l1->next = ll1;
  ll1->data = 2;
  ll1->next = ll2;
  ll2->data = 4;
  ll2->next = NULL;

  Node* l2 = new Node();
  Node* ll3 = new Node();
  Node* ll4 = new Node();

  l2->data = 1;
  l2->next = ll3;
  ll3->data = 3;
  ll3->next = ll4;
  ll4->data = 4;
  ll4->next = NULL;

  mergeTwoLists(l1, l2);
  traverseLinkedList(l1);
  return 0;
}
