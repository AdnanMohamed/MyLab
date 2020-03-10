// @ Main Authors: Savitch and Main.
// @ Co-Author: Adnan Hashem Mohamed
//
// FILE: stack2.h (part of the namespace stack_adnan)
// TEMPLATE CLASS PROVIDED: stack<Item> (a stack of items)
//   The template parameter, Item, is the data type of the items in the stack,
//   also defined as stack<Item>::value_type.
//   It may be any of the C++ built-in types (int, char, etc.), or a class
//   with a default constructor, a copy constructor, and an assignment
//   operator. The definition stack<Item>::size_type is the data type of
//   any variable that keeps track of how many items are in a stack.
//
//  ITERATORS:
//   stack<Item>::iterator 
//   stack<Item>::const_iterator 
//
// CONSTRUCTOR for the stack<Item> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   Item pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
//   Item& top()
//     Precondition: size() > 0.
//     Postcondition: returns a reference to the top element of the stack.
//     Could be used to change the top or just to access the top element.
//
//   void swap(stack&)
//     Postcondition: elements of the parameter becomes the elements of the calling stack and vise versa
//
//   void flip()
//     Postcondition: x activates flip, x should contain the same items, 
//     but the order of those items has been reversed.
//
// CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   Item seek(size_type n = 1)const; 
//     Precondition: n < size( ). 
//     Postcondition: The return value is the item that is n from the top 
//     (with the top at n = 0, the next at n = 1, and so on). The stack is not changed.
//
//   const Item& top( ) const
//     Precondition:  size() > 0.
//     Postcondition: returns a constant reference to the top element.
//     Cannot change the top element of the stack.
//
//   void top_down(std::ostream&)const
//     Postcondition: prints the stack elements from top to down to the outstream
//
//   void down_top(std::ostream&)const
//     Postcondition: prints the stack elements from down to top to the outstream
//
// ITERATOR TOOLKIT:
//   iterator begin()
//     Postcondition: returns an iterator to the top element of the stack
//   iterator end()
//     Postcondition: returns an iterator indicating the position past the last element.
//  
//   const_iterator begin() const   ---) CONST VERSIONS of begin() and end()
//   const_iterator end() const     ---) Same functionality but ACCESS ONLY.
//
//  NON-MEMBER FUNCTIONS:
//   template<class Item>
//   bool operator ==(const stack<Item>&, const stack<Item>&)
//     Postcondition: returns true if the compared stacks are identical.
//     identical means: top element of 1st stack == top of 2nd stack,
//     2nd element of 1st stack == 2nd element of 2nd stack and so on.
//
//   template<class Item>
//   bool operator !=(const stack<Item>&, const stack<Item>&)
//     Postcondition: returns true if the nth element in stack1 differs
//     with the nth element in stack2
//
// VALUE SEMANTICS for the stack<Item> class:
//   Assignments and the copy constructor may be used with stack<Item>
//   objects.
//
// DYNAMIC MEMORY USAGE by the stack<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   the copy constructor, push, and the assignment operator.

#ifndef MAIN_SAVITCH_STACK2_H
#define MAIN_SAVITCH_STACK2_H
#include <cstdlib>   // Provides NULL and size_t
#include "node/template_node.h"
namespace stack_adnan
{
    template <class Item>
    class stack
    {
    public:
        // TYPEDEFS 
        typedef std::size_t size_type;
        typedef Item value_type;
        typedef template_node_adnan::node_iterator<Item> iterator;
        typedef template_node_adnan::const_node_iterator<Item> const_iterator;
        // CONSTRUCTORS and DESTRUCTOR
        stack() { top_ptr = NULL; }
        stack(const stack& source);
        ~stack() { list_clear(top_ptr); }
        // MODIFICATION MEMBER FUNCTIONS
        void push(const Item& entry);
        void pop();
        void operator =(const stack& source);
        Item& top();
        void swap(stack&);
        void flip();
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const
        {
            return template_node_adnan::list_length(top_ptr);
        }
        bool empty() const { return (top_ptr == NULL); }
        const Item& top() const;
        Item seek(size_type n = 1) const;
        void top_down(std::ostream&)const;
        void down_top(std::ostream&)const;
        
        // NON-MEMBER FUNCTIONS
        template<class Item>
        friend bool operator ==(const stack<Item>&, const stack<Item>&);

        template<class Item>
        friend bool operator !=(const stack<Item>&, const stack<Item>&);
        // Iterator toolkit

        iterator begin() { return top_ptr; }
        iterator end() { return NULL; }
        const_iterator begin() const{ return top_ptr; }
        const_iterator end() const { return NULL; }

    private:
        template_node_adnan::node<Item>* top_ptr;  // Points to top of stack
    };
}

#include "stack.template" // Include the implementation 
#endif

