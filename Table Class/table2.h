// FILE: table2.h (part of the namespace table2_adnan)
// TEMPLATE CLASS PROVIDED: Table<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.
//
// CONSTRUCTOR for the Table<RecordType> template class:
//   Table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
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
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
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
// VALUE SEMANTICS for the Table<RecordType> template class:
//   Assignments and the copy constructor may be used with Table objects.
//
// DYNAMIC MEMORY USAGE by the Table<RecordType> template class:
//   If there is insufficient dynamic memory, then the following functions
//   can call new_handler: the copy constructor, insert, the assignment
//   operator.

#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>    // Provides size_t
#include "Linked List/template_node.h" // Provides the node type.

namespace table2_adnan
{
    template <class RecordType>
    class table
    {
    public:
        // MEMBER CONSTANT
        static const std::size_t TABLE_SIZE = 811;
        // CONSTRUCTORS AND DESTRUCTOR
        table();
        table(const table& source);
        ~table();
        // MODIFICATION MEMBER FUNCTIONS
        void insert(const RecordType& entry);
        void remove(int key);
        table& operator =(const table& source);
        // CONSTANT MEMBER FUNCTIONS
        void find(int key, bool& found, RecordType& result) const;
        bool is_present(int key) const;
        std::size_t size() const { return total_records; }
    private:
        template_node_adnan::node<RecordType>* data[TABLE_SIZE];
        std::size_t total_records;
        // HELPER MEMBER FUNCTION
        std::size_t hash(int key) const;
        template_node_adnan::node<RecordType>* find_ptr(int key)const;
    };

    template<class RecordType>
    table<RecordType>::table()
    {
        for (size_t i = 0; i < TABLE_SIZE; i++)
        {
            data[i] = NULL;
        }
        total_records = 0;
    }

    template<class RecordType>
    table<RecordType>::table(const table& source)
    {
        total_records = source.total_records;
        for (std::size_t i = 0; i < total_records; ++i)
            template_node_adnan::list_copy(source.data[i], data[i]);
    }

    template<class RecordType>
    table<RecordType>::~table()
    {
        for (size_t i = 0; i < TABLE_SIZE; i++)
        {
            template_node_adnan::list_clear(data[i]);
        }
    }
    
    template<class RecordType>
    table<RecordType>& table<RecordType>::operator =(const table<RecordType>& source)
    {
        if (this != &source)
        {
            table::~table();
            total_records = source.total_records;
            for (std::size_t i = 0; i < total_records; ++i)
                template_node_adnan::list_copy(source.data[i], data[i]);
        }
        return *this;
    }
    
    template<class RecordType>
    void table<RecordType>::insert(const RecordType& entry)
    {
        auto target = find_ptr(entry.key); // checking if there is already an entry with the same key.
        if (target != NULL)         
            target->set_data(entry); // overwrite the old entry.
        else
        {
            template_node_adnan::list_head_insert(data[hash(entry.key)], entry); // insert a new entry.
            ++total_records;
        }

    }

    template<class RecordType>
    bool table<RecordType>::is_present(int key) const
    {
        auto target = find_ptr(key);
        return target != NULL;
    }

    template<class RecordType>
    void table<RecordType>::remove(int key)
    {
        auto index = hash(key);
        for (auto cursor = data[index]; cursor!= NULL; cursor = cursor->link())
        {
            if (cursor->data().key == key)
            {
                // copy the data in the head of the linked list to the 
                // node to be removed.
                cursor->set_data(data[index]->data());
                // remove the head since we copied it to the other node.
                template_node_adnan::list_head_remove(data[index]);
                --total_records;
                break;
            }
        }

    }
    
    template<class RecordType>
    void table<RecordType>::find(int key, bool& found, RecordType& result) const
    {
        auto index = hash(key);
        auto target = find_ptr(key);
        if (target == NULL)
        {
            found = false;
            return;
        }
        result = target->data();
        found = true;
        return;
    }

    template<class RecordType>
    inline std::size_t table<RecordType>::hash(int key) const
    {
        return key % TABLE_SIZE;
    }

    template<class RecordType>
    template_node_adnan::node<RecordType>* table<RecordType>::find_ptr(int key)const
        // Precondition: key >= 0
        // Postcondition: returns a pointer to the node containing such key,
        // or returns NULL if not found.
    {
        for (auto cursor = data[hash(key)]; cursor != NULL; cursor = cursor->link())
        {
            if (cursor->data().key == key)
                return cursor;
        }
        return NULL;
    }

}

#include "table2.template" // Include the implementation

#endif

