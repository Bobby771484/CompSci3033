#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
        explicit Node(const Item_Type& d, Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* head;
    Node* tail;
    std::size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    // Disable copy for simplicity
    Single_Linked_List(const Single_Linked_List&) = delete;
    Single_Linked_List& operator=(const Single_Linked_List&) = delete;

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const { return num_items == 0; }

    void insert(std::size_t index, const Item_Type& item);
    bool remove(std::size_t index);
    std::size_t find(const Item_Type& item) const;
    std::size_t size() const { return num_items; }
};

#endif
