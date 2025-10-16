#include "StackVector.h"
#include <iostream>

bool IntStack::empty() const { return data.empty(); }

void IntStack::push(int value) { data.push_back(value); }

void IntStack::pop() {
    if (data.empty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    data.pop_back();
}

int IntStack::top() const {
    if (data.empty())
        throw std::runtime_error("top() on empty stack");
    return data.back();
}

double IntStack::average() const {
    if (data.empty()) return 0.0;
    long long sum = std::accumulate(data.begin(), data.end(), 0LL);
    return static_cast<double>(sum) / static_cast<double>(data.size());
}

std::size_t IntStack::size() const { return data.size(); }
