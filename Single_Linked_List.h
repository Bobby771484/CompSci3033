#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>
//Singly linked list class template 
// stores items in nodes that point to the next node
// each node has a pointer and a  data value with the pointer pointing to the next one
// Supporting basic list operations like adding, removing
// inserting and finding elements by index or value.
template <typename Item_Type>
class Single_Linked_List {
private: // Node structure used in the list
 // each node has a piece of data and pointer to the next node
    struct Node {
        Item_Type data;
        Node* next;
        explicit Node(const Item_Type& d, Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* head; // points to the first node
    Node* tail; // points to the last node
    std::size_t num_items; // says how many elements are in the list

public:
    Single_Linked_List(); // makes an empty list
    ~Single_Linked_List(); // deletes all nodes

    // Disable copy for simplicity
    Single_Linked_List(const Single_Linked_List&) = delete;
    Single_Linked_List& operator=(const Single_Linked_List&) = delete;

    // core operations

    void push_front(const Item_Type& item); //add a element to the front
    void push_back(const Item_Type& item); // add a element to the end
    void pop_front(); // remove the first element
    void pop_back(); // remove the last element
    Item_Type front() const; // return the value at the head
    Item_Type back() const; // return the value at the tail
    bool empty() const { return num_items == 0; }
    // inserts or removes elements at a specific position
    void insert(std::size_t index, const Item_Type& item);
    bool remove(std::size_t index);
    std::size_t find(const Item_Type& item) const;
   // returns how many elements are in the list. 
    std::size_t size() const { return num_items; }
};

#endif
