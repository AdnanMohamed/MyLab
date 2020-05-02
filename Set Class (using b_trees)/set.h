// FILE: set.h (part of the namespace set_adnan)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
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
//     to the set and the return value is true. This is slightly different than
//     the C++ Standard Library set (see Appendix H).
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

#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H
#include <cstdlib>   // Provides size_t
#include<algorithm>
#include<iomanip>
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
        static const std::size_t MINIMUM = 2; // change it to 2 after debugging.
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

        void transfer_child(size_t i, bool right)
            // Postcondition: if right is true, the child of subset[i+1] is given to subset[i]
            // else, the child of subset[i-1] is given to subset[i]
        {
            if (!right)
            {
                // take the last child of subset[i-1] and give it to subset[i]
                if (subset[i - 1]->child_count != 0)
                {
                    shift_right3(subset[i]->subset, MAXIMUM + 2, 0);
                    subset[i]->subset[0] = subset[i - 1]->subset[subset[i - 1]->child_count - 1];
                    subset[i]->child_count++;
                    shift_left3(subset[i - 1]->subset, subset[i - 1]->child_count, subset[i - 1]->child_count - 1);
                }
            }
            else
            {
                // take the last child of subset[i+1] and give it to subset[i]
                if (subset[i + 1]->child_count != 0)
                {
                    
                    subset[i]->subset[MINIMUM] = subset[i + 1]->subset[0];
                    subset[i]->child_count++;
                    shift_left3(subset[i + 1]->subset, subset[i + 1]->child_count, 0);
                }
            }
        }

        size_t get_index(const Item& target)
            // Postcondition: the index returned suffices the following:
            // target <= data[i]
        {
            size_t i = 0;
            while ( i < data_count && data[i] < target)
                ++i;
            return i;
        }
        bool found(size_t i, const Item& target)
            // Postcondition: returns true if target is in the root.
            // else false.
        {
            if (i < data_count && !(target < data[i]))
                return true;
            else
                return false;
        }

        void shift_right2(Item a[], size_t size, size_t index);
        void shift_right3(set<Item>* a[], size_t size, size_t index)
        {
            for (auto i = size - 1; i > index; --i)
                a[i] = a[i - 1];
        }

        void shift_left2(Item a[], size_t& size, size_t index);
        void shift_left3(set<Item>* a[], size_t& size, size_t index)
        {
            for (auto i = index; i < size + 1; ++i)
                a[i] = a[i + 1];
            --size;
        }

        void combine(size_t i, bool right)
            // Precondition: subset[i] elements are less than MIN.
            // Postcondition: if right == true, then subset[i] is combined to subset[i+1]
            // else subset[i] is combined to subset[i-1]
        {
            if (right)
            {
                //shift_right2(subset[i + 1]->data, MINIMUM, 0);
                //subset[i + 1]->data[0] = data[i];
                //shift_left2(data, data_count, i);
                subset[i]->data[MINIMUM-1] = data[i];
                shift_left2(data, data_count, i);
                Item* temp_data = new Item[MAXIMUM];
                std::copy(subset[i]->data, subset[i]->data + MINIMUM, temp_data);
                std::copy(subset[i + 1]->data, subset[i+1]->data + MINIMUM, temp_data + MINIMUM);
                std::copy(temp_data, temp_data + MAXIMUM, subset[i + 1]->data);
                delete []temp_data;
                subset[i + 1]->data_count = MAXIMUM;

                if (subset[i]->child_count > 0)
                {
                    set<Item>** temp_subset = new set<Item> * [MAXIMUM + 2];
                    std::copy(subset[i]->subset, subset[i]->subset + subset[i]->child_count, temp_subset);
                    std::copy(subset[i + 1]->subset, subset[i + 1]->subset + subset[i + 1]->child_count, temp_subset + MINIMUM);
                    std::copy(temp_subset, temp_subset + MAXIMUM + 2, subset[i + 1]->subset);
                    delete temp_subset;
                    subset[i + 1]->child_count += subset[i]->child_count;
                }

            }
            else
            {
                //subset[i]->data[MINIMUM] = data[i];
                //shift_left2(data, data_count, i);
                shift_right2(subset[i]->data, MINIMUM, 0);
                subset[i]->data[0] = data[i-1];
                shift_left2(data, data_count, i-1);
                std::copy(subset[i]->data, subset[i]->data + MINIMUM, subset[i - 1]->data + subset[i - 1]->data_count);
                std::copy(subset[i]->subset, subset[i]->subset + subset[i]->child_count, subset[i - 1]->subset + subset[i - 1]->child_count);
                subset[i - 1]->data_count = MAXIMUM;               
                subset[i - 1]->child_count += subset[i]->child_count;
            }

            // deleting the previous pointer
            shift_left3(subset, child_count, i);

        }

    };

    template<class Item>
    void set<Item>::shift_right2(Item a[], size_t size, size_t index)
        // Precondition: size is the size of the array, index is a valid index
        // Postcondition: all elements from index and after it are shifted one spot
        // to the right to make index a valid place to insert an element in.
    {
        for (auto i = size - 1; i > index; --i)
            a[i] = a[i - 1];
    }

    template<class Item>
    void set<Item>::transfer_element(std::size_t i, bool right)
        // Precondition: subset[i] has elements less than MIN.
// Postcondition: if 'right' is true, then ith element of the root is transfered to
// the 0th element of subset[i] and subset[i-1] last element is 
// given to the root in place of the taken element.
// The last child of subset[i-1] is now belongs to subset[i] children.
    {
        if (right)
        {
            subset[i]->data[subset[i]->data_count] = data[i];
            subset[i]->data_count++;
            data[i] = subset[i+1]->data[0];
            shift_left2(subset[i+1]->data, subset[i+1]->data_count, 0);
        }
        else
        {
            // making the 0th index available in the data of subset[i]
            shift_right2(subset[i]->data, MAXIMUM, 0);
            subset[i]->data[0] = data[i - 1];
            data[i - 1] = subset[i - 1]->data[subset[i - 1]->data_count - 1];
            subset[i]->data_count++;
            shift_left2(subset[i-1]->data, subset[i-1]->data_count, subset[i-1]->data[subset[i-1]->data_count - 1]);
        }
    }

    template<class Item>
    void set<Item>::shift_left2(Item a[], size_t& size, size_t index)
    {
        for (auto i = index; i < size + 1; ++i)
            a[i] = a[i + 1];
        --size;
    }

    template<class Item>
    void set<Item>::remove_biggest(Item& removed_entry)
    {
        if (child_count == 0)
        {
            removed_entry = data[data_count - 1];
            shift_left2(data, data_count, data_count - 1);
        }
        // removing the biggest element in the subset
        else
            subset[child_count - 1]->remove_biggest(removed_entry);

        if (child_count > 0 && subset[child_count - 1]->data_count < MINIMUM)
            fix_shortage(child_count - 1);
    }

    template<class Item>
    bool set<Item>::loose_erase(const Item& target)
    {
        auto i = get_index(target);
        if (!found(i, target) && child_count == 0)  // target not in root and root has no child.
            return false;
        else if (found(i, target) && child_count == 0) // target is found and the root has no children
        {
            // removing the element
            shift_left2(data, data_count, i);
            return true;
        }
        else if (child_count != 0 && !found(i, target)) // target is not in the root but maybe in its children
        {
            bool is_erased = subset[i]->loose_erase(target); // this may cause the root to have shortage in elements
            if (subset[i]->data_count < MINIMUM)  // to check if shortage happend.
                fix_shortage(i);
            return is_erased;
        }
        else if(child_count != 0 && found(i, target))  // target in root and root has no children
        {
            subset[i]->remove_biggest(data[i]);
            if (subset[i]->data_count < MINIMUM)
                fix_shortage(i);
            return true;
        }
    }

    template<class Item>
    void set<Item>::fix_shortage(std::size_t i)
    {
        if (i > 0 && subset[i - 1]->data_count > MINIMUM)
        {
            transfer_element(i, false);  // handles the transfer from root to subset[i] and from subset[i-1] to root.
            transfer_child(i, false);
        }
        else if (i < child_count - 1 && subset[i + 1]->data_count > MINIMUM)
        {
            transfer_element(i, true);
            transfer_child(i, true);
        }
        else if (i > 0)
        {
            // combine subset[i] with subset[i-1]
            combine(i, false);
        }
        else
            combine(i, true);
    }

    template<class Item>
    std::size_t set<Item>::erase(const Item& target)
    {
        if (!loose_erase(target))
            return 0;
        if (data_count == 0 && child_count != 0)
        {
            set<Item>* temp_set = new set<Item>(*(subset[0]));
            clear();
            std::copy(temp_set->data, temp_set->data + temp_set->data_count, data);
            std::copy(temp_set->subset, temp_set->subset + temp_set->child_count, subset);
            data_count = temp_set->data_count;
            child_count = temp_set->child_count;
            //delete temp_set;
        }
        return 1;
    }
}
#include "set.template" // Include the implementation.

#endif
