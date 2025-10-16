#include "Single_Linked_List.h"
#include "StackVector.h"
#include <iostream>

int main() {
    // ===== Test Linked List =====
    Single_Linked_List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(1, 15);

    std::cout << "List front: " << list.front() << "\n";
    std::cout << "List back: " << list.back() << "\n";
    std::cout << "Find(20): " << list.find(20) << "\n";

    list.remove(1);
    std::cout << "After remove index 1, size: " << list.size() << "\n\n";

    // ===== Test Stack =====
    IntStack s;
    std::cout << std::boolalpha << "Stack empty? " << s.empty() << "\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top: " << s.top() << "\n";
    std::cout << "Average: " << s.average() << "\n";

    s.pop();
    std::cout << "After pop, size: " << s.size() << "\n";
}
