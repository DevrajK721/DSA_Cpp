#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

class Stack {
public:
    // Constructor
    Stack() {}

    // Push a value onto the stack
    void push(int value) {
        stack.push_back(value);
    }

    // Pop and return the top value from the stack (if not empty)
    int pop() {
        if (!is_empty()) {
            int top = stack.back();
            stack.pop_back();  // Remove the top element
            return top;
        } else {
            std::cout << "Stack is empty!" << std::endl;
            return -1;  // Return an invalid value if stack is empty
        }
    }

    // Peek at the top value without removing it
    int peek() const {
        if (!is_empty()) {
            return stack.back();
        } else {
            std::cout << "Stack is empty!" << std::endl;
            return -1;  // Return an invalid value if stack is empty
        }
    }

    // Check if the stack is empty
    bool is_empty() const {
        return stack.empty();
    }

    // Get the size of the stack
    int size() const {
        return stack.size();
    }

    // Print the stack (from top to bottom)
    void print() const {
        std::cout << "Stack: ";
        for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> stack;  // Use vector to represent the stack
};

#endif //STACK_H
