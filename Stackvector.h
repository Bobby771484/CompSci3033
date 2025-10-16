#ifndef STACKVECTOR_H
#define STACKVECTOR_H

#include <vector>
#include <numeric>
#include <stdexcept>

class IntStack {
private:
    std::vector<int> data;

public:
    bool empty() const;
    void push(int value);
    void pop();
    int top() const;
    double average() const;
    std::size_t size() const;
};

#endif
