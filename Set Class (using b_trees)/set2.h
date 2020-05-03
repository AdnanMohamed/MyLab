// FILE: set2.h (part of the namespace set2_adnan)
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
// OPERATORS
//   void operator+=(const set<Item>& b)
//     Postcondition: let a be the current set, then a+= b will make a be
//     the union of a and b.
//
//   void operator-=(const set<Item>& b)
//     Postcondition: any common element in b and the calling set are not
//     a member of the calling set anymore.
//     In math terms, let s be the calling set, s = s - (s intersection b)
//
//   set<Item> intersect(const set<Item>& b)
//     Postcondition: returns the intersection of the sets.
//
//   bool operator==(const set<Item>& b)
//     Postcondition: returns true if every element in b is in the calling set and vise versa
//     else false is returned.
//
//   bool operator!=(const set<Item>& b)
//     Postcondition: returns true if there exists an element is one of the sets
//     that does not belong to the other, else false is returned.
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
// NON-MEMBER FUNCTIONS:
//   template<class Item>
//   set<Item> operator+(const set<Item>& a, const set<Item>& b)
//     Postcondition: returns the union of a and b.
//
//   template<class Item>
//   set<Item> operator-(const set<Item>& a, const set<Item>& b)
//     Postcondition: returns the difference between set a and set b.
//     In otherwords, returns a set which contains elements that are in a but not in b.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: 
//   The constructors, insert, and the assignment operator.

#ifndef SET2_H
#define SET2_H

#include <cstdlib>   // Provides size_t
#include<vector>
#include<iomanip>  // Provides setw
#include<iostream>

namespace set2_adnan {
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

        // OPERATORS
        void operator+=(const set<Item>& b);
        void operator-=(const set<Item>& b);
        bool operator==(const set<Item>& b);
        bool operator!=(const set<Item>& b);
        set<Item> intersect(const set<Item>& b);

        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const;
        bool empty() const { return (data.size() == 0); }
        std::size_t size()const;
        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent) const
        {

            const int EXTRA_INDENTATION = 4;    size_t i;
            std::cout << std::setw(indent) << "";
            // Print the indentation.
            // Print the data from the root. 
            for (i = 0; i < data.size(); ++i)
                std::cout << data[i] << " "; std::cout << std::endl;
            // Print the subtrees. 
            for (i = 0; i < subset.size(); ++i)
                subset[i]->print(indent + EXTRA_INDENTATION);
        }

    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 2;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::vector<Item> data;
        std::vector<set*> subset;
        // HELPER MEMBER FUNCTIONS
        bool is_leaf() const { return (subset.size() == 0); }
        bool loose_insert(const Item& entry);
        bool loose_erase(const Item& target);
        void remove_biggest(Item& removed_entry);
        void fix_excess(std::size_t i);
        void fix_shortage(std::size_t i);

        // MORE HELPER FUNCTIONS FOR THE HELPING FUNCTIONS :)
        void transfer_element(std::size_t i, bool right);
        void transfer_child(std::size_t i, bool right);
        std::size_t get_index(const Item& target)const;
        bool found(std::size_t i, const Item& target)const;
        void combine(std::size_t i, bool right);

    };


} // end of namespace

#include"set2.template"

#endif
