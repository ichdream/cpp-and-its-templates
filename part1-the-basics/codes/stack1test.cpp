#include "stack1.hpp"
#include <iostream>
#include <string>

int main()
{
    Stack<int> intStack;
    Stack<std::string> stringStack;

    // manipulate int stack
    intStack.push(7);
    std::cout << "intStack.top():   " << intStack.top() << "\n";

    // manipulate string stack
    stringStack.push("Hello, string stack.");
    std::cout << "stringStack.top():    " << stringStack.top() << std::endl;
    stringStack.pop();
}