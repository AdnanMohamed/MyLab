// FILE: table3.h (part of the namespace table3_adnan)
// TEMPLATE CLASS PROVIDED: table<class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator.
//
//-------- Copyright © ---------
//  @Author: Adnan Hashem Mohamed
//-------------------------------
//
// CONSTRUCTOR for the table<RecordType, TABLE_SIZE, hashekey(const RecordType&)> template class:
//   table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the table<RecordType, TABLE_SIZE, hashekey(const RecordType&)> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the Table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the table<RecordType, TABLE_SIZE, hashekey(const RecordType&)> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//   size_t size( ) const
//     Postcondition: Return value is the total number of records in the
//     Table.
//
// VALUE SEMANTICS for the table<RecordType, TABLE_SIZE, hashekey(const RecordType&)> template class:
//   Assignments and the copy constructor may be used with Table objects.
//
// DYNAMIC MEMORY USAGE by the table<RecordType, TABLE_SIZE, hashekey(const RecordType&)> template class:
//   If there is insufficient dynamic memory, then the following functions
//   can call new_handler: the copy constructor, insert, the assignment
//   operator.

#ifndef TABLE3_H
#define TABLE3_H
#include <cstdlib>    // Provides size_t
#include <vector>
//#include<algorithm>

namespace table3_adnan
{
    template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
    class table
    {
    public:
        // CONSTRUCTORS (no destructor needed, uses automatic copy constructor) 
        table() :total_records(0) {}
        // MODIFICATION MEMBER FUNCTIONS 
        void insert(const RecordType& entry);
        void remove(int key);
        // CONSTANT MEMBER FUNCTIONS 
        void find(int key, bool& found, RecordType& result) const;
        bool is_present(int key) const; 
        std::size_t size() const { return total_records; }
    private:
        std::vector<RecordType> data[TABLE_SIZE];
        std::size_t total_records;
        // HELPER MEMBER FUNCTION 
        std::size_t hash(int key) const { return key % TABLE_SIZE; }
        std::size_t get_index(int key)const;
    };

    template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
    void table<RecordType, TABLE_SIZE, hashkey>::insert(const RecordType& entry)
    {
        // check if the entry was already in the table.
        int key = hashkey(entry);
        size_t i = get_index(key);
        if (i == -1)
        {
            data[hash(key)].push_back(entry);
            ++total_records;
        }
        else
            data[hash(key)][i] = entry;
    }

    template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
    void table<RecordType, TABLE_SIZE, hashkey>::remove(int key)
    {
        auto index = get_index(key);
        if (index != -1)
        {
            data[hash(key)].erase(data[hash(key)].begin() + index);
            --total_records;
        }
    }

    template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
    bool table<RecordType, TABLE_SIZE, hashkey>::is_present(int key) const
    {
        return get_index(key) != -1;
        //for (auto record : data[hash(key)])
        //{
        //    if (hashkey(record) == key)
        //        return true;
        //}
        //return false;

    }

    template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
    void table<RecordType, TABLE_SIZE, hashkey>::find(int key, bool& found, RecordType& result) const
    {
        auto index = get_index(key); // get the possible location of the entry.
        if (index == -1)  // not present.
            found = false;
        else  // present
        {
            found = true;
            result = data[hash(key)][index]; // set the result to a copy of the target entry.
        }
    }

    template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&)>
    std::size_t table<RecordType, TABLE_SIZE, hashkey>::get_index(int key)const
        // Precondition: key >= 0
        // Postcondition: returns the index where the record is located in.
        // If the record is not in the table, -1 is returned. (which is a special number in size_t)
    {
        int index = hash(key);
        for (size_t i = 0; i < data[index].size(); i++)
        {
            if (hashkey(data[index][i]) == key)
                return i;
        }
        return -1;
    }

}

#include "table3.template" // Include the implementation

#endif

