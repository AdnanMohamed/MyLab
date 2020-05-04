// FILE: table1.h (part of the namespace table1_adnan)
// TEMPLATE CLASS PROVIDED: table<RecordType> (a table of records with keys).
//    This class is a container template class for a table of records.
//    The template parameter, RecordType, is the data type of the records in the
//    table. It may be any of the bulit-in C++ types (int, char, etc.), or a
//    class with a default constructor, an assignment operator, and a public integer
//    member variable called key.
//
//	------ - Copyright © -------- -
//	@Author: Main, and Walter Savitch
//	@co-author: Adnan Hashem Mohamed
//	------------------------------ 
// 
// MEMBER CONSTANT for the table<RecordType> class:
//   static const size_type CAPACITY = ________
//     table<RecordType>::CAPACITY is the maximum number of records held by a table.
//
// CONSTRUCTOR for the table<RecordType> template class:
//   table( )
//     Postcondition: The table has been initialized as an empty table.
//
// MODIFICATION MEMBER FUNCTIONS for the table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the table.
//
//   void remove(int key)
//     Postcondition: If a record was in the table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//    size_type size( ) const
//      Postcondition: Return value is the total number of records in the
//      table.
//
//    bool is_full()const
//      Postcondition: Returns true if the table has no more space to add an entry, else false.
//
//  VALUE SEMANTICS for the table<RecordType> template class:
//    Assignments and the copy constructor may be used with table objects.

#ifndef TABLE1_H
#define TABLE1_H
#include <cstdlib>    // Provides size_t
#include<cassert>     // Provides assert

namespace table1_adnan
{
    template <class RecordType>
    class table
    {
    public:
        // MEMBER CONSTANT -- See Appendix E if this fails to compile.
        static const std::size_t CAPACITY = 811;
        // CONSTRUCTOR
        table();
        // MODIFICATION MEMBER FUNCTIONS
        void insert(const RecordType& entry);
        void remove(int key);
        // CONSTANT MEMBER FUNCTIONS
        bool is_present(int key) const;
        void find(int key, bool& found, RecordType& result) const;
        std::size_t size() const { return used; }
        bool is_full()const { return used == CAPACITY; }
    private:
        // MEMBER CONSTANTS -- These are used in the key field of special records.
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        // MEMBER VARIABLES
        RecordType data[CAPACITY];
        std::size_t used;
        // HELPER FUNCTIONS
        std::size_t hash1(int key) const;
        std::size_t hash2(int key) const;
        std::size_t next_index(std::size_t index, int key) const;
        void find_index(int key, bool& found, std::size_t& index) const;
        bool never_used(std::size_t index) const;
        bool is_vacant(std::size_t index) const;
    };

    template<class RecordType>
    void table<RecordType>::insert(const RecordType& entry)
    {
        assert(!is_full());
        std::size_t index;
        bool exists;
        find_index(entry.key, exists, index); // check if there is already an entry with the same key.
        if (!exists)
        {
            index = hash1(entry.key);
            // get the nearest available location [open address technique]
            while (!is_vacant(index) && (data[index].key != entry.key))  
                index = next_index(index, entry.key);
            ++used;
        }
        data[index] = entry;
    }

    template<class RecordType>
    void table<RecordType>::remove(int key)
    {
        bool found = false;
        size_t index = 0;
        find_index(key, found, index);
        if (found)
        {
            // removing the element with specified key from the table
            data[index].key = PREVIOUSLY_USED;
            --used;
        }
    }

    template<class RecordType>
    bool table<RecordType>::is_present(int key) const
    {
        bool present;
        std::size_t index;
        find_index(key, present, index);
        return present;
    }

    template<class RecordType>
    void table<RecordType>::find(int key, bool& found, RecordType& result) const
    {
        std::size_t index;
        find_index(key, found, index);
        if (found)
        {
            result = data[index];
        }
    }

    // HELPER FUNCITONS
    template<class RecordType>   
    std::size_t table<RecordType>::next_index(std::size_t index, int key) const
        // Postcondition: returns index + 1 EXCEPT when index equals
        // the last index in the array, than it returns 0
    {
        return (index + hash2(key)) % CAPACITY;
    }
    template<class RecordType>
    void table<RecordType>::find_index(int key, bool& found, std::size_t& index) const
        // Precondition: 'key' is non-negative.
        // Postcondition: If there exists an element in the table with the given key, then
        // found is set to true and index is the location of the element such that data[index].key == key
        // Otherwise, found is set to false and index is unchanged.
    {
        auto i = hash1(key); // get the hash
        auto first_index = i;
        do
        {
            if (never_used(i))
            {
                // no such entry exists; if the entry once entered
                // in the table then it'll occupy this location.
                break;
            }
            else if (data[i].key == key)
            {
                // This is the target we are looking for!!
                index = i;
                found = true;
                return;
            }
            i = next_index(i, key);
        } while (i != first_index);

        found = false;
    }
    template<class RecordType>
    inline bool table<RecordType>::never_used(std::size_t index) const
    {
        return data[index].key == NEVER_USED;
    }
    template<class RecordType>
    inline bool table<RecordType>::is_vacant(std::size_t index) const
    {
        return data[index].key < 0;
    }
    template<class RecordType>
    inline std::size_t table<RecordType>::hash1(int key) const
    {
        return key % CAPACITY;
    }
    template<class RecordType>
    inline std::size_t table<RecordType>::hash2(int key) const
    {
        return 1 + (key % (CAPACITY-2));
    }
}
#include "table1.template" // Include the implementation.
#endif

