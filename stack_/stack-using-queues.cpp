#include <iostream>
#include <queue>

class MyStack {
    std::queue<int> q;
    std::queue<int> holder;
    public:
    MyStack() {
    }

    void push(int x) {
	q.push(x);
    }

    int pop() {
	if(q.size() == 0) {
	    return -1;
	} else if(q.size() == 1) {
	    int removedElement = q.front();
	    q.pop();
	    return removedElement;
	}

	for(int i = 0;i < q.size();i++) {
	    holder.push(q.front());
	    q.pop();
	}

	int elementToBeRemoved = q.front();
	q.pop();

	// hopefully q is empty here
	for(int i = 0;i < holder.size() + 1;i++) {
	    q.push(holder.front());
	    holder.pop();
	}

	return elementToBeRemoved;
    }

    int top() {
	return q.back();
    }

    bool empty() {
	return q.empty();
    }
};

int main() {
    MyStack* stack = new MyStack();
    stack->push(2);
    stack->push(6);
    stack->push(12);

    std::cout << stack->top() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->top() << std::endl;
    std::cout << stack->pop() << std::endl;

    if(stack->empty()) {
	std::cout << "Stack is empty!!" << std::endl;
    }

    return 0;
}

