// FILE: bt_class.h
// For Project 4 in Chapter 10 of "Data Structures and Other Objects Using C++"
// TEMPLATE CLASS PROVIDED: binary_tree<Item> (a binary tree where each node has
//   an item) The template parameter, Item, is the data type of the items in the
//   tree's nodes. It may be any of the C++ built-in types (int, char, etc.),
//   or a class with a default constructor, a copy constructor and an assignment
//   operator.
// The class is within namespace: binary_tree2_adnan
//
//  --------Copyright �-------- -
//  @Author: Main, and Walter Savitch (documentation + prototypes)
//  @ co-author: Adnan Hashem Mohamed (inline implementation)
// ------------------------------ -
//
// NOTE: Each non-empty tree always has a "current node."  The location of
// the current node is controlled by three member functions: shift_up,
// shift_to_root, shift_left, and shift_right.
//
// CONSTRUCTOR for the binary_tree<Item> template class:
//   binary_tree( )  
//     Postcondition: The binary tree has been initialized as an empty tree
//     (with no nodes).
//
// MODIFICATION MEMBER FUNCTIONS for the binary_tree<Item> template class:
//   void create_first_node(const Item& entry)
//     Precondition: size( ) is zero.
//     Postcondition: The tree now has one node (a root node), containing the
//     specified entry. This new root node is the "current node."
//
//   void shift_to_root( )
//     Precondition: size( ) > 0.
//     Postcondition: The "current node" is now the root of the tree.
//
//   void shift_up( )
//     Precondition: has_parent( ) returns true.
//     Postcondition: The "current node" has been shifted up to the parent of
//     the old current node.
//
//   void shift_left( )
//     Precondition: has_left_child( ) returns true.
//     Postcondition: The "current node" been shifted down to the left child
//     of the original current node.
//
//   void shift_right( )
//     Precondition: has_right_child( ) returns true.
//     Postcondition: The "current node" been shifted down to the right child
//     of the original current node.
//
//   void change(const Item& new_entry)
//     Precondition: size( ) > 0.
//     Postcondition: The data at the "current node" has been changed to the
//     new entry.
//
//   void add_left(const Item& entry)
//     Precondition: size( ) > 0, and has_left_child( ) returns false.
//     Postcondition: A left child has been added to the "current node,"
//     with the given entry. The "current node" is still pointing to the 
//     old node.
//
//   void add_right(const Item& entry)
//     Precondition: size( ) > 0, and has_right_child( ) returns false.
//     Postcondition: A right child has been added to the "current node,"
//     with the given entry.The "current node" is still pointing to the 
//     old node.
//
//   void clear_tree()
//    Postcondition: The tree allocates no memory. The tree is empty.
//
//
// CONSTANT MEMBER FUNCTIONS for the binary_tree<Item> template class:
//   size_t size( ) const
//     Postcondition: The return value is the number of nodes in the tree.
//
//   Item retrieve( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the data from the "current node."
//
//   bool has_parent( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a parent.
//
//   bool has_left_child( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a left child.
//
//   bool has_right_child( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a right child.
//
//   bool has_child()const
//     Postcondition: Returns true if the "current node" has right child or left child 
//  
//   bool empty_tree()const
//     Postcondition: Returns true if the size of the tree is zero, else returns false.
//
// VALUE SEMANTICS for the binary_tree<Item> template class:
//   Assignments and the copy constructor may be used with binary_tree objects.
//
// DYNAMIC MEMORY USAGE by the binary_tree<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   create_first_node, add_left, add_right, the copy constructor, and the 
//   assignment operator.

#ifndef BINARY_T2_CLASS_H
#define BINARY_T2_CLASS_H
#include <cstdlib>    // Provides size_t

namespace binary_tree2_adnan
{
    template <class Item>
    class binary_tree
    {
    public:

        // CONSTRUCTORS and DESTRUCTOR
        binary_tree() {}
        binary_tree(const binary_tree& source);
        ~binary_tree() { clear_tree(); }
        // MODIFICATION MEMBER FUNCTIONS
        void create_first_node(const Item& entry);
        void shift_to_root();
        void shift_up();
        void shift_left();
        void shift_right();
        void change(const Item& new_entry);
        void add_left(const Item& entry);
        void add_right(const Item& entry);
        void remove();
        void clear_tree();

        // CONSTANT MEMBER FUNCTIONS
        std::size_t size() const { return count; }
        Item retrieve() const;
        bool has_parent() const;
        bool has_left_child() const;
        bool has_right_child() const;
        bool has_child()const { return has_left_child() || has_right_child(); }
        bool empty_tree()const { return size() == 0; }

        // ASSIGNMENT OPTOR
        binary_tree& operator=(const binary_tree& source);

    private:
        Item* nodes;
        bool* is_present;
        std::size_t current_index;
        std::size_t count;
        std::size_t capacity;
    };

}

#include "binary_tree.template"
#endif 
