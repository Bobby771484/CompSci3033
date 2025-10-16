#include "StackVector.h"
#include <iostream>

bool IntStack::empty() const { return data.empty(); } //If the stack is empty it returns a boolean value

void IntStack::push(int value) { data.push_back(value); } // Pushes a new value to the top of the stack

void IntStack::pop() { //takes out the topmost value returns a warning/error message if taking out the topmost value would result in null
    if (data.empty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    data.pop_back();
}

int IntStack::top() const { // returns what value is at the top of the stack returns an error if their is no such item
    if (data.empty())
        throw std::runtime_error("top() on empty stack");
    return data.back();
}

double IntStack::average() const { // returns the average of all of the values in the vector 
    if (data.empty()) return 0.0;
    long long sum = std::accumulate(data.begin(), data.end(), 0LL);
    return static_cast<double>(sum) / static_cast<double>(data.size());
}

std::size_t IntStack::size() const { return data.size(); } // Returns how big the actual vector it is in terms of size
