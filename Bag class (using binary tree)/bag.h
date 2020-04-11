// FILE: bag.h (part of the namespace binary_tree_adnan)
// TEMPLATE CLASS PROVIDED: bag<Item>
//     (a container template class for a collection of items)
//
//  --------Copyright ©-------- -
//  @Authors: Main, and Walter Savitch (documentation + prototypes)
//  @Co-Author: Adnan Hashem Mohamed (inline definitions)
// ------------------------------ -
//
// TYPEDEFS for the bag<Item> class:
//   bag<Item>::value_type
//     bag<Item>::value_type is the data type of the items in the bag. It may
//     be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
//   bag<Item>::size_type
//     bag<Item>::size_type is the data type of any variable that keeps track
//     of how many items are in a bag.
//
// CONSTRUCTOR for the bag<Item> class:
//   bag( )
//     Postcondition: The bag is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the bag<Item> class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the bag. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the bag, then one copy of target has been
//     removed from the bag; otherwise the bag is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void operator +=(const bag& addend)
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag<Item> class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bag.
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//     Postcondition: The bag returned is the union of b1 and b2.
//
//  void join
//  (
//    bst<Item>& top,
//    bst<Item>& left,
//    bst<Item>& right
//  )
//   Precondition: top has just one item, elements of left is less than or equal to the item in top,
//   and everything in right is greater than the item in top. 
//   Postcondition: top now contains everything from left and right,
//   and left and right are now both empty.
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag: 
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc: The constructors, insert, operator +=, operator +, and
//   the assignment operator.

#ifndef BAG6_H 
#define BAG6_H
#include <cstdlib>     // Provides NULL and size_t
#include "Binary Tree/binary_tree.h"

namespace binary_tree_adnan
{
    template <class Item>
    class bag
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        bag();
        bag(const bag& source);
        ~bag();
        // MODIFICATION functions
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator +=(const bag& addend);
        bag& operator =(const bag& source);
        // CONSTANT functions
        size_type size() const { return tree_size(root_ptr); }
        size_type count(const Item& target) const;

        template <class Item>
        friend void join
        (
            bag<Item>& top,
            bag<Item>& left,
            bag<Item>& right
        );

        void print_tree()const {
            print(root_ptr, 0);
            std::cout << "----------------\n";
        }

    private:
        binary_tree_node<Item>* root_ptr; // Root pointer of binary search tree
        void insert_all(binary_tree_node<Item>* addroot_ptr);
    };

    // NONMEMBER functions for the bag<Item> template class
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);
}

#include "bag.template" // Include the implementation.
#endif

