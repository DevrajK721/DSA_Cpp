//
// Created by Devra on 10/13/2024.
//

#include "AH.h"

// Example usage
int main() {
    MyDict myDict;
    myDict.assign(10, 100);
    myDict.assign(20, 200);
    myDict.assign(10, 300);  // Overwrite the value of key 10
    myDict.print();
    std::cout << "Value for key 10: " << myDict.get(10) << std::endl;
    myDict.remove(10);
    myDict.print();
    return 0;
}