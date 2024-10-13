#include "stack.h"

// Example usage
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();            // Output: Stack: 30 20 10
    std::cout << s.peek() << std::endl;  // Output: 30
    std::cout << s.pop() << std::endl;   // Output: 30
    s.print();            // Output: Stack: 20 10
    std::cout << std::boolalpha << s.is_empty() << std::endl;  // Output: false
    return 0;
}