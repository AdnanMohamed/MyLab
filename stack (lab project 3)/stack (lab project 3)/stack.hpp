#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    10/2019
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>
////////////////////////////////////////////////////////////////////////////
//           
template<typename Item>
class Node {
public:
    // TYPEDEF
    typedef Item value_type;
    // CONSTRUCTOR
    Node(const Item& data = Item(), Node* link = NULL)
    {
        data_field = data; link_field = link;
    }
    // MODIFICATION MEMBER FUNCTIONS
    Item data() { return data_field; }
    Node* link() { return link_field; }
    void set_data(const Item& new_data) { data_field = new_data; }
    void set_link(Node* new_link) { link_field = new_link; }
    // CONST MEMBER FUNCTIONS
    const Item& data() const { return data_field; }
    const Node* link() const { return link_field; }
private:
    Item data_field;
    Node* link_field;
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename Item>
class stack {
public:
    stack() { tos = NULL; }
    stack(const stack<Item>&);
    ~stack() { list_clear(tos); }
    void      swap(stack<Item>&);
    stack<Item>& operator= (stack<Item>);
    bool      empty() const { return list_length(tos) == 0; }
    bool      full() const;
    Item         top() const;
    Item         pop();
    void      push(const Item&);

private:
    Node<Item>* tos;
};

// FUNCTIONS to manipulate a linked list:

template<class Item>
std::size_t list_length(const Node<Item>* head_ptr)
{
    size_t count = 0;
    const Node<Item>* cursor = head_ptr;
    while (cursor != NULL)
    {
        count++;
        cursor = cursor->link();
    }

    return count;
}

template <class Item>
void list_head_insert(Node<Item>*& head_ptr, const Item& entry)
{
    head_ptr = new Node<Item>(entry, head_ptr);
}

template <class Item>
void list_head_remove(Node<Item>*& head_ptr)
{
    assert(head_ptr != NULL);

    Node<Item>* temp = new Node<Item>;
    temp = head_ptr;
    head_ptr = head_ptr->link();
    delete temp;
}

template <class Item>
void list_clear(Node<Item>*& head_ptr)
{
    while (head_ptr != NULL)
    {
        list_head_remove(head_ptr);
    }
}

template <class Item>
void list_copy
(const Node<Item>* source_ptr, Node<Item>*& head_ptr)
{
    for (const Node<Item>* cursor = source_ptr; cursor != NULL; cursor = cursor->link())
        list_tail_attach(head_ptr, cursor->data());
}

template <class Item>
void list_tail_attach(Node<Item>*& head_ptr, const Item& entry)
{
    if (head_ptr == NULL) // If the list is empty this will be the first node
    {
        list_head_insert(head_ptr, entry);
        return;
    }
    Node<Item>* new_node = new Node<Item>(entry, NULL); // creates the new node to be attached
    Node<Item>* cursor = head_ptr;
    while (cursor->link() != NULL)  // moves the cursor to the tail of the list
    {
        cursor = cursor->link();
    }
    cursor->set_link(new_node);
}

template<class Item>
stack<Item>::stack(const stack<Item>& source)
{
    tos = NULL;
    list_copy(source.tos, tos);
}

template<class Item>
void stack<Item>::push(const Item& entry)
{
    list_head_insert(tos, entry);
}

template<class Item>
Item stack<Item>::pop()
{
    Item element = top();
    list_head_remove(tos);
    return element;
}

template<class Item>
stack<Item>& stack<Item>::operator =(stack<Item> source)
{
    if (this != &source)
    {
        list_clear(tos);
        list_copy(source.tos, tos);
    }
    return *this;
}

template<class Item>
Item stack<Item>::top() const
{
    return tos->data();
}

template<class Item>
void stack<Item>::swap(stack& s)
{
    Node<Item>* temp = tos;
    tos = s.tos;
    s.tos = temp;
}

#endif


