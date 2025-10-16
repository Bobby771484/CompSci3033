#include "Single_Linked_List.h"

// Constructor that sets up the empty list itself
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List()
    : head(nullptr), tail(nullptr), num_items(0) {}

// Deletes each and evrey node afterwards that way freeing up space for later
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
// adds a new node at the front updating the tail if its the first node thats being added
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (num_items == 0)
        tail = head;
    ++num_items;
}

template <typename Item_Type> // adds a new node to the back of a list if said list is empty then the added node becomes both the tail and head
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

template <typename Item_Type> //removes the first node in the list if due to the removal of it the list becomes empty then the tail is set to null
void Single_Linked_List<Item_Type>::pop_front() {
    if (!head) return;
    Node* old = head;
    head = head->next;
    delete old;
    --num_items;
    if (num_items == 0) tail = nullptr;
}

template <typename Item_Type>// removes the last node in the list and if theirs only one node left it just clears the whole list
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

template <typename Item_Type> //returns what is stored at the front of the list 
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!head) throw std::out_of_range("front() on empty list");
    return head->data;
}

template <typename Item_Type> //returns the data stored at the back of the list
Item_Type Single_Linked_List<Item_Type>::back() const { // if the lis empty throws an execption
    if (!tail) throw std::out_of_range("back() on empty list");
    return tail->data;
}

template <typename Item_Type> //Inserts a new node at a specficic spot 
// if the index is 0 pushed to the front and if its beyond size it just pushes it to the back.
void Single_Linked_List<Item_Type>::insert(std::size_t index, const Item_Type& item) {
    if (index == 0) { push_front(item); return; }
    if (index >= num_items) { push_back(item); return; }

    Node* cur = head;
    for (std::size_t i = 0; i < index - 1; ++i)
        cur = cur->next;
    cur->next = new Node(item, cur->next);
    ++num_items;
}

template <typename Item_Type>// Removes a node at a given index
//If it works returns true and if not it means the index isnt in bounds
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

template <typename Item_Type> // Finds a specific item in a list and then returns its position
// if the item isn't found it then returns the size of the list.
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
