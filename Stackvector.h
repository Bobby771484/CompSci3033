#ifndef STACKVECTOR_H
#define STACKVECTOR_H

#include <vector>
#include <numeric>
#include <stdexcept>

class IntStack { // a simple vector class using first in first out to store values 
private:
    std::vector<int> data; // vector that actually stores the data itself

public:
    bool empty() const; // checks to see if the vector is empty returning true if it is and false if it isn't
    void push(int value); // adds or pushing a new integer to the top of the vector 
    void pop(); //Removes the value at the top of the vector
    int top() const; // displays what number is at the top 
    double average() const; // takes the average of all the values in the vector added up and then divided
    std::size_t size() const; // Returns the size of the vector itself feasfaseffe
};

#endif
