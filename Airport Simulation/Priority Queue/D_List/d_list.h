// File: d_list.h
// This is the interface for node, and the toolkit for a doubly liked list.
// The class node<Item> and the helping functions are within namespace template_dlist_adnan
// This file also defines a template class: node_iterator<Item>.
// The node_iterator is a forward iterators with two constructors:
// (1) A constructor (with a node<Item>* parameter) that attaches the iterator
// to the specified node in a linked list, and (2) a default constructor that
// creates a special iterator that marks the position that is beyond the end of a
// linked list. There is also a const_node_iterator for use with
// const node<Item>* .
//
// ------- COPY RIGHTS ---------
// @Author: Adnan Hashem Mohamed
// Some of the code taken from (Main and Walter Savitch)
//------------------------------
// TYPEDEFS:
//  1- template_dlist_adnan::value_type is the type of elements stored in each node.
//
// CONSTRUCTOR:
//  node(
//  const value_type& init_data = value_type(),
//  node* front_link = NULL
//  node* rear_link = NULL
//      )
//  Postcondition: The data is set to given argument. The front link is set to the
//  given front_link as well as the rear link is set to the given rear_link
//  DEFAULT: data will be set to the value returned by the void constructor of the type
//  of that value (e.g. if the type is 'int' the data will be 0 because int() returns 0)
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*). 
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//   
//   void set_front_link(node* new_link)
//     Postcondition: The node now contains the specified new front link.
//
//   void set_rear_link(node* new_link)
//     Postcondition: The node now contains the specified new_link
//     points to the previous node.
//
//   Item data( ) const
//     Postcondition: The return value is the data from this node.
//
//   const node* front_link( ) const <----- const version
//   node* front_link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link pointing to the next node.
//
//   const node* back_link( ) const <----- const version
//   node* back_link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node pointing to the previous node
//
//   MODIFICATION MEMBER FUNCTION
//    Item& data()
//     Postcondition: A reference for the stored data will be returned.
//
// FUNCTIONS in the linked list toolkit:
//   template <class Item>
//   void list_clear(node<Item>*& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   template <class Item>
//   void list_copy
//   (const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr) ----> with tail_ptr
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//
//   template <class Item>
//   void list_copy
//   (const node<Item>* source_ptr, node<Item>*& head_ptr)  ------------------------> without tail_ptr
//     Precondition: source_ptr is a pointer pointing to the head of the original list.
//     Postcondition: head_ptr is a pointer pointing to the head of a new list which contains
//     the same values of the nodes in the original list.
//
//   template <class Item>
//   void list_head_insert(node<Item>*& head_ptr, const Item& entry) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   template <class Item>
//   void list_head_remove(node<Item>*& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   template <class Item>
//   void list_insert(node<Item>* previous_ptr, const Item& entry) 
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   template <class Item>
//   size_t list_length(const node<Item>* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list.
//
//   template <class NodePtr, class SizeType>
//   NodePtr list_locate(NodePtr head_ptr, SizeType position)
//   The NodePtr may be either node<Item>* or const node<Item>*
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The return value is a pointer that points to the node at
//     the specified position in the list. (The head node is position 1, the
//     next node is position 2, and so on). If there is no such position, then
//     the null pointer is returned.
//
//   template <class Item>
//   void list_remove(node<Item>* previous_ptr) 
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   template <class NodePtr, class Item>
//   NodePtr list_search
//   (NodePtr head_ptr, const Item& target) 
//   The NodePtr may be either node<Item>* or const node<Item>*
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The return value is a pointer that points to the first
//     node containing the specified target in its data member. If there is no
//     such node, the null pointer is returned.
//
//   template <class Item>
//   void list_tail_attach(NodePtr& head_ptr, const Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the tail of the linked list; if this happens to be the first node of
//     the linked list, then head_ptr now points to this node (otherwise
//     head_ptr is unchanged).
//
//   template <class Item>
//   void list_piece(const node<Item>* start_ptr, const node<Item>* end_ptr,
//    node<Item>*& head_ptr, node<Item>*& tail_ptr)
//     Precondition: start_ptr and end_ptr are pointers to nodes on the same
//     linked list, with the start_ptr node at or before the end_ptr node
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for a
//     new list that contains the items from start_ptr up to but not including 
//     end_ptr.  The end_ptr may also be NULL, in which case the new list 
//     contains elements from start_ptr to the end of the list.
//
//   template <class Item>
//   std::size_t list_occurrences(const node<Item>* head_ptr, const Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The return value is the count of the number of times
//     target appears as the data portion of a node on the linked list.
//     The linked list itself is unchanged.
//
//   template <class Item>
//   void list_tail_remove(node<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The tail node has been removed and returned to the heap;
//     if the list is now empty, then head_ptr is null; otherwise head_ptr
//     is unchanged.
//
//   template <class Item, class size_type>
//   node<Item>* list_copy_front(const node<Item>* source_ptr, size_type n)
//     Precondition: source_ptr is the pointer to the head of a linked list.
//     'n' is not negative and not greater than the length of the linked list
//     pointed to by source_ptr
//     Postcondition: returns the head pointer to the new doubly linked list
//     which contains the first 'n' elements from the list pointed to by source_ptr
//  
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy.

#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstdlib> // Provides size_t and NULL

namespace template_dlist_adnan
{
    template<class Item>
    class node
    {
    public:
        // TYPEDEF
        typedef Item value_type;
        // CONSTRUCTOR
        node(
            const Item& init_data = Item(),
            node* front_link = NULL,
            node* rear_link = NULL
        )
        {
            data_field = init_data; front = front_link;
            rear = rear_link;
        }

        // Member functions to set the data and link fields:
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_front_link(node* new_link) { front = new_link; }
        void set_rear_link(node* new_link) { rear = new_link; }

        // Constant member function to retrieve the current data:
        Item data() const { return data_field; }

        // MODIFICATION MEMBER FUNCTION
        Item& data() { return data_field; }

        // Two slightly different member functions to retreive
        // the current link:
        const node* front_link() const { return front; }
        node<Item>*& front_link() { return front; }
        const node* rear_link() const { return rear; }
        node*& rear_link() { return rear; }

    private:
        Item data_field;
        node* front;
        node* rear;
    };

    template <class Item>
    class node_iterator
        : public std::iterator<std::forward_iterator_tag, Item>
    {
    public:
        node_iterator(node<Item>* initial = NULL)
        {
            current = initial;
        }
        Item& operator *() const
        {
            return current->data();
        }

        Item& operator *()
        {
            return current->data();
        }

        node<Item>*& operator ->()
        {
            return current;
        }

        node_iterator& operator ++() // Prefix ++
        {
            current = current->front_link();
            return *this;
        }
        node_iterator operator ++(int) // Postfix ++
        {
            node_iterator original(current);
            current = current->front_link();
            return original;
        }
        node_iterator& operator --() // Prefix --
        {
            current = current->rear_link();
            return *this;
        }
        node_iterator operator --(int) // Postfix --
        {
            node_iterator original(current);
            current = current->rear_link();
            return original;
        }
        bool operator ==(const node_iterator other) const
        {
            return current == other.current;
        }
        bool operator !=(const node_iterator other) const
        {
            return current != other.current;
        }
    private:
        node<Item>* current;
    };

    template <class Item>
    class const_node_iterator
        : public std::iterator<std::forward_iterator_tag, const Item>
    {
    public:
        const_node_iterator(const node<Item>* initial = NULL)
        {
            current = initial;
        }
        const Item& operator *() const
        {
            return current->data();
        }
        const node<Item>*& operator ->()const
        {
            return current;
        }
        const_node_iterator& operator ++() // Prefix ++
        {
            current = current->front_link();
            return *this;
        }
        const_node_iterator operator ++(int) // Postfix ++
        {
            const_node_iterator original(current);
            current = current->front_link();
            return original;
        }
        const_node_iterator& operator --() // Prefix --
        {
            current = current->rear_link();
            return *this;
        }
        const_node_iterator operator --(int) // Postfix --
        {
            const_node_iterator original(current);
            current = current->rear_link();
            return original;
        }
        bool operator ==(const const_node_iterator other) const
        {
            return current == other.current;
        }
        bool operator !=(const const_node_iterator other) const
        {
            return current != other.current;
        }
    private:
        const node<Item>* current;
    };

    // FUNCTIONS to manipulate a linked list:
    template <class Item>
    void list_clear(node<Item>*& head_ptr);

    template <class Item>
    void list_copy
    (const node<Item>* source_ptr, node<Item>*& head_ptr);

    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry);

    template <class Item>
    void list_head_remove(node<Item>*& head_ptr);

    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry);

    template <class Item>
    void list_tail_attach(node<Item>*& head_ptr, const Item& entry);

    template <class Item>
    std::size_t list_length(const node<Item>* head_ptr);

    template <class NodePtr, class SizeType>
    NodePtr list_locate(NodePtr head_ptr, SizeType position);

    template <class Item>
    void list_remove(node<Item>* previous_ptr);

    template <class NodePtr, class Item>
    NodePtr list_search(NodePtr head_ptr, NodePtr back_ptr, const Item& target);

    template <class Item>
    void list_piece(const node<Item>* start_ptr, const node<Item>* end_ptr,
        node<Item>*& head_ptr, node<Item>*& tail_ptr);

    template <class Item>
    std::size_t list_occurrences(const node<Item>* head_ptr, const Item& target);

    template <class Item>
    void list_tail_remove(node<Item>*& head_ptr);

    template <class Item, class size_type>
    node<Item>* list_copy_front(const node<Item>* source_ptr, size_type n);

} // end of namespace

#include"d_list.template"

#endif