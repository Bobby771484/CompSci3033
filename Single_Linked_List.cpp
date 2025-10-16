#include "Single_Linked_List.h"

// Constructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List()
    : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    num_items = 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (num_items == 0)
        tail = head;
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* n = new Node(item);
    if (!head) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (!head) return;
    Node* old = head;
    head = head->next;
    delete old;
    --num_items;
    if (num_items == 0) tail = nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        num_items = 0;
        return;
    }
    Node* cur = head;
    while (cur->next != tail)
        cur = cur->next;
    delete tail;
    tail = cur;
    tail->next = nullptr;
    --num_items;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!head) throw std::out_of_range("front() on empty list");
    return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!tail) throw std::out_of_range("back() on empty list");
    return tail->data;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(std::size_t index, const Item_Type& item) {
    if (index == 0) { push_front(item); return; }
    if (index >= num_items) { push_back(item); return; }

    Node* cur = head;
    for (std::size_t i = 0; i < index - 1; ++i)
        cur = cur->next;
    cur->next = new Node(item, cur->next);
    ++num_items;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(std::size_t index) {
    if (index >= num_items) return false;
    if (index == 0) { pop_front(); return true; }

    Node* cur = head;
    for (std::size_t i = 0; i < index - 1; ++i)
        cur = cur->next;
    Node* target = cur->next;
    cur->next = target->next;
    if (target == tail) tail = cur;
    delete target;
    --num_items;
    return true;
}

template <typename Item_Type>
std::size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* cur = head;
    std::size_t idx = 0;
    while (cur) {
        if (cur->data == item)
            return idx;
        cur = cur->next;
        ++idx;
    }
    return num_items;
}

// Explicit template instantiation for int
template class Single_Linked_List<int>;
