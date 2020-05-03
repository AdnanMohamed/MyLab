// FILE: set.h (part of the namespace set_adnan)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
//
//-------- Copyright © ---------
//  @Author: Adnan Hashem Mohamed
//-------------------------------
//
// TYPEDEFS for the set<Item> class:
//   set<Item>::value_type
//     set<Item>::value_type is the data type of the items in the set. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   void clear( )
//     Postcondition: The set is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the set, the set is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the set and the return value is true.
//
//   size_t erase(const Item& target)
//     Postcondition: If target was in the set, then it has been removed from
//     the set and the return value is 1. Otherwise the set is unchanged and the
//     return value is zero.
//
// CONSTANT MEMBER FUNCTIONS for the Set<Item> class:
//   size_t count(const Item& target) const
//     Postcondition: Returns the number of items equal to the target
//     (either 0 or 1 for a set).
//
//  bool empty( ) const 
//     Postcondition: Returns true if the set is empty; otherwise returns false.
//
//	std::size_t size()const
//	   Postcondition: Returns the number of elements in the set.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: 
//   The constructors, insert, and the assignment operator.

#ifndef SET_ADNAN_H
#define SET_ADNAN_H
#include <cstdlib>   // Provides size_t
#include<algorithm>  // Provides copy
#include<iomanip>  // Provides setw
#include<iostream>

namespace set_adnan
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        set();
        set(const set& source);
        ~set() { clear(); }
        // MODIFICATION MEMBER FUNCTIONS
        set<Item>& operator =(const set& source);
        void clear();
        bool insert(const Item& entry);
        std::size_t erase(const Item& target);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const;
        bool empty() const { return (data_count == 0); }
        std::size_t size()const;
        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent) const
        {

            const int EXTRA_INDENTATION = 4;    size_t i;
            std::cout << std::setw(indent) << "";
            // Print the indentation.
            // Print the data from the root. 
            for (i = 0; i < data_count; ++i)
                std::cout << data[i] << " "; std::cout << std::endl;
            // Print the subtrees. 
            for (i = 0; i < child_count; ++i)
                subset[i]->print(indent + EXTRA_INDENTATION);
        }

    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 3;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM + 1];
        std::size_t child_count;
        set* subset[MAXIMUM + 2];
        // HELPER MEMBER FUNCTIONS
        bool is_leaf() const { return (child_count == 0); }
        bool loose_insert(const Item& entry);
        bool loose_erase(const Item& target);
        void remove_biggest(Item& removed_entry);
        void fix_excess(std::size_t i);
        void fix_shortage(std::size_t i);

        // MORE HELPER FUNCTIONS FOR THE HELPING FUNCTIONS :)
        void transfer_element(std::size_t i, bool right);
        void transfer_child(std::size_t i, bool right);

        std::size_t get_index(const Item& target);
        bool found(std::size_t i, const Item& target);

        void shift_right_data(size_t index);
        void shift_right_subsets(size_t index);

        void shift_left_data(size_t index = -1);
        void shift_left_subsets(size_t index = -1);

        void combine(std::size_t i, bool right);

    };

}
#include "set.template" // Include the implementation.

#endif
