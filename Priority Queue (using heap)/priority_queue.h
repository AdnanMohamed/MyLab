// This is the interface file for the priority_queue template class.
// The class is within namespace: p_queue_adnan
// 
// Priority Queue data structure stores elements of any type that has
// the less than operator. Elements with greater value have greater priority.
// Greater values are determined by the '<' operator of the datatype of the stored element.
/*
-------- Copyright © ---------
  @Author: Adnan Hashem Mohamed

-------------------------------
*/
//
//  *** DOCUMENTATION  ***
//
// CONSTRUCTOR:
//  template<class Item>
//  priority_queue<Item>::priority_queue()
//   Postcondition: an empty priority queue is declared.
//
// MODIFICATION MEMBERS:
//  Item pop( )
//   Preconditon: the queue is not empty.
//   Postcondition: The top element in the queue is poped and returned.

#include<cassert> // provides assert(), move this include to .template file
#include<iostream>
namespace p_queue_adnan
{
    template <class Item>
    class priority_queue
    {
    public:
        // TYPEDEFS and MEMBER CONSTANT 
        typedef Item value_type;
        typedef std::size_t size_type;
        // CONSTRUCTOR 
        priority_queue( );
        priority_queue(const priority_queue& source);
        ~priority_queue() { delete[] data; delete []order; }
        // MODIFICATION MEMBER FUNCTIONS 
        Item pop( );
        void push(const Item& entry);

        // CONSTANT MEMBER FUNCTIONS
        bool empty() const { return size() == 0; }
        size_type size() const { return used; }
        Item top() const;
        // ASSIGNMENT OPERATOR
        priority_queue& operator=(const priority_queue& source);
    private:
        
        static const int START_SIZE = 5;

        Item* data;
        size_type* order;
        size_type used;
        size_type current_size;
        void double_size();
    };

    template<class Item>
    void priority_queue<Item>::double_size();

    template<class Item>
    void priority_queue<Item>::push(const Item& entry);

    template<class Item>
    Item priority_queue<Item>::pop();

    template<class Item>
    Item priority_queue<Item>::top() const;

} // end of namespace

#include"priority_queue.template"

