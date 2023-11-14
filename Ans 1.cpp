#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    void push(int value) {
        queue1.push(value);
    }

    int pop() {
        if (empty())
            throw std::runtime_error("Stack is empty");

        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int popped = queue1.front();
        queue1.pop();

        std::swap(queue1, queue2); // Swap queue names for future operations

        return popped;
    }

    int top() {
        if (empty())
            throw std::runtime_error("Stack is empty");

        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int top_element = queue1.front();
        queue2.push(top_element);
        queue1.pop();

        std::swap(queue1, queue2); // Swap queue names back

        return top_element;
    }

    bool empty() {
        return queue1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    return 0;
}
