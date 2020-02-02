// FILE: dynamic_sequence.h
// CLASS PROVIDED: sequence (part of the namespace dynamic_sequence_adnan)
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//
// CONSTRUCTOR for the sequence class:
//   sequence()
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item() returns true
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
//   void operator+=(const sequence& addend)
//     Postcondition: addend is appended to the existing sequence
//     The current element is the last element.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
//   value_type operator[](const size_type& index)const
//     Precondition: 0<= index < size()
//     Postcondition: returns the ith element in the sequence
//
// NON-MEMBER FUNCTIONS:
//   sequence operator+(const sequence& s1, const sequence& s2)
//     Postcondition: Returns the sum of both sequences.
//     The new sequence will consist of s1 elements then s2 elements
//
//   std::ostream& operator <<(std::ostream& outs, const sequence& s)
//     Postcodition: Prints out the elements of the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the List
//   If there is insufficient dynamic memory, then the following functions
//   throw a BAD_ALLOC exception: The constructors, insert, attach. 

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include"linked_list.h" // Provides node::value_type

namespace dynamic_sequence_adnan
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef node_adnan::node::value_type value_type;
        typedef std::size_t size_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence();
        sequence(const sequence& source);
        ~sequence();
        // MODIFICATION MEMBER FUNCTIONS
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void operator =(const sequence& source);
        void operator+=(const sequence& addend);
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return many_nodes_; }
        bool is_item() const;
        value_type current() const;
        value_type operator[](const size_type& index)const;
        // FRIENDS:
        friend sequence operator+(const sequence& s1, const sequence& s2);
        friend std::ostream& operator <<(std::ostream& outs, const sequence& s);
    private:
        node_adnan::node* head_ptr_;
        node_adnan::node* tail_ptr_;
        node_adnan::node* cursor_;
        node_adnan::node* precursor_;
        size_type many_nodes_;
    };

    
}

#endif

