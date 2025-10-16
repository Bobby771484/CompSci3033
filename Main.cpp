#include "Single_Linked_List.h"
#include "StackVector.h"
#include <iostream>

int main() {
    std::cout << "  Single linked list  \n";

    Single_Linked_List<int> list;

    // 1) pushing  a value to the front and to the back
    std::cout << "\n Pushing 10 to the front then 20 to the back and finally five to the front.\n";
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    std::cout << "Front: " << list.front() << "  Back: " << list.back()
              << "  Size: " << list.size() << "\n";

    // 2) inserts a specified item at a specified index
    list.insert(1, 15);
    std::cout << "Front: " << list.front() << "  Back: " << list.back()
              << "  Size: " << list.size() << "\n";

    // 3) finding the location of a value in the linked list
    std::cout << "\n> find(20)\n";
    std::size_t pos = list.find(20);
    std::cout << "find(20) returned index: " << pos << " \n";

    // 4) remove at a specified point in the index.
    std::cout << "\n remove(1)\n";
    bool removed = list.remove(1);
    std::cout << "remove(1) " << std::boolalpha << removed
              << "  Size: " << list.size() << "\n";

    // 5) removes the item either at the front or the back
    std::cout << "\n> pop_front, and pop_back\n";
    list.pop_front();
    list.pop_back();
    std::cout << "After pops, Size: " << list.size()
              << "  empty()? " << list.empty() << "\n";

    // If not empty, show current front/back accessors
    if (!list.empty()) {
        std::cout << "Front: " << list.front() << "  Back: " << list.back() << "\n";
    }

    std::cout << "\n  testing the int stack (vectors) \n";

    // Q2 requirements
    IntStack s;

    // 1) create a stack object 
    // 2) check empty
    std::cout << "\n> empty()? " << std::boolalpha << s.empty() << "\n";

    // 3) push some values
    std::cout << "> push(10), push(20), push(30)\n";
    s.push(10); s.push(20); s.push(30);

    // 4) pop an element
    std::cout << "> pop\n";
    s.pop();
    std::cout << "After pop, size(): " << s.size() << "\n";

    // 5) top of the stack
    std::cout << "Top: " << s.top() << "\n";

    // 6) average of elements
    std::cout << "Average: " << s.average() << "\n";

    std::cout << "\n Program Done \n";
    return 0;
}
