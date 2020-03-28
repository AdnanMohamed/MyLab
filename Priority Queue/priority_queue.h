// This is the interface for the template class: priority_queue<Item>
// The class is within namespace: priority_queue_adnan
//
/*--------- Copyrights© ----------
  @Author: Adnan Hashem Mohamed
  Note: Some of documentation written by:-
  Main, and Walter Savitch.
  --------------------------------
*/
//   *** DOCUMENTATION FOR priority_queue<Item> ***
// TYPES:
//  1- Item/ priority_queue<Item>::value_type
//      - The type of data stored in the priority_queue.
//  2- priority_queue<Item>::size_type
//      - For any counting-related variable
//  3- priority_queue<Item>::iterator
//      - Provides an iterator for the priority_queue to iterate through elements
//  4- priority_queue<Item>::const_iterator
//      - Provides an iterator for the priority_queue to iterate through elements
//   
//
//  **NOTE: Item could be any type (char, int, double..) which has the following operator:
//      ( <, <=, >, >=, ==, !=, = )
//   DEFAULT PRIORITY: for the following elements: e1, e2, e3.
//   if e1 <= e2 <= e3, e1 will be first in the priority_queue and e3 will be last.
//
// CONSTRUCTOR for the priority_queue<Item> template class:
//   priority_queue( )
//     Postcondition: The priority_queue has been initialized as an empty priority_queue.
//
//   bool priority_smallest()const
//     Postcondition: returns true if the priority is the smallest element
//     ('<' determines smallest)
//  
// MODIFICATION MEMBER FUNCTIONS for the priority_queue<Item> template class:
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The front item of the priority_queue has been removed.
//
//   void push(const Item& entry)
//     Postcondition: A new copy of entry has been inserted at the position
//     depending on priority. ( highest priority: 1, 2, 3, ...)
//
//   void reverse()
//     Postcondition: The order of elements is reversed. (first is last and vise versa)
//     So if the elements where from least to greatest they will be from greatest to least.
//     priority_smallest() not is reversed (if it was returning true, now false and vise versa)
//
// CONSTANT MEMBER FUNCTIONS for the priority_queue<Item> template class:
//   bool empty( ) const
//     Postcondition: The return value is true if the priority_queue is empty.
//
//   Item front( ) const
//     Precondition: The priority_queue is not empty
//     Postcondition: The return value is the first element in the priority_queue (highest priority)
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the priority_queue.
//
//   Item back()const
//     Precondition: The priority_queue is not empty
//     Postcondition: The return value is the rear element in the priority_queue (least priority)
//
//  ITERATOR_RELATED:
//   iterator begin()
//   const_iterator begin()const
//     Postcondition: Returns an iterator/const_iterator to the first element.
//   iterator end()
//   const_iterator end()
//     Postcondition: Returns an iterator/const_iterator identifying going beyond
//     last element in the priority_queue.
//
//  NON-MEMBER FUNCITONS:
//   template<class Item>
//   bool operator ==(const priority_queue<Item>& p_queue1, const priority_queue<Item>& p_queue2)
//    Postcondition: returns true if and only if, p_queue1 has the same number of elements in p_queue2 AND
//    for all 0 ≤ i < p_queue1.size(), p_queue1[i] == p_queue[i].
//    Else returns false.
//   template<class Item>
//   bool operator !=(const priority_queue<Item>& p_queue1, const priority_queue<Item>& p_queue2);
//    Postcondition: returns true if and only if, the size of the two queues are NOT equal OR
//    there exists an i where 0 ≤ i < p_queue1.size(), p_queue1[i] != p_queue[i]
//
//   template<class Item>
//   priority_queue<Item> merge(const priority_queue<Item>& p_queue1, const priority_queue<Item>& p_queue2)
//    Postcondition: returns a new priority queue which contains both elements from p_queue1 AND p_queue2
//    NOTE: Priority is RESERVED.
//
// VALUE SEMANTICS for the priority_queue<Item> template class:
//   Assignments and the copy constructor may be used with priority_queue<Item> objects.


#ifndef PRIORITY_Q_H
#define PRIORITY_Q_H

#include<cstdlib> // Provides std::size_t
#include "D_List/d_list.h" // node template class

namespace priority_queue_adnan {

    template<class Item>
    class priority_queue {
    public:
        typedef std::size_t size_type;
        typedef Item value_type;
        typedef template_dlist_adnan::node_iterator<Item> iterator;
        typedef template_dlist_adnan::const_node_iterator<Item> const_iterator;

        // CONSTRUCTORS and DESTRUCTOR
        priority_queue()
        {
            first_ptr = NULL; last_ptr = NULL;
            count = 0; priority_smallest_ = true;
        }
        priority_queue(const priority_queue& source);
        ~priority_queue(){ list_clear(first_ptr); }
        
        // MODIFICATION MEMBER FUNCTIONS
        void pop();
        void push(const Item& entry);
        void reverse();
        Item& front();
        Item& back();

        // CONSTANT MEMBER FUNCTIONS
        bool empty() const { return (count == 0); }
        Item front() const;
        size_type size() const { return count; }
        Item back()const;
        bool priority_smallest()const { return priority_smallest_; }
        
        // ASSIGNMENT OPERATOR
        priority_queue& operator =(const priority_queue& source);

        // ITERATOR RELATED
        iterator begin() { return iterator(first_ptr); }
        const_iterator begin()const { return const_iterator(first_ptr); }
        iterator end() { return iterator(); }
        const_iterator end() const{ return const_iterator(); }
        
        // EQUALITY
        template<class Item>
        friend bool operator ==(const priority_queue<Item>& p_queue1, const priority_queue<Item>& p_queue2);
        template<class Item>
        friend bool operator !=(const priority_queue<Item>& p_queue1, const priority_queue<Item>& p_queue2);
    
    private:
        template_dlist_adnan::node<Item>* first_ptr;
        template_dlist_adnan::node<Item>* last_ptr;
        size_type count;
        bool priority_smallest_;
    };

    template<class Item>
    priority_queue<Item> merge(const priority_queue<Item>& p_queue1, const priority_queue<Item>& p_queue2);

    template<class Item>
    void swap(Item& e1, Item& e2);

} // end of namespace (priority_queue_adnan)

#include"priority_queue.template"

#endif // !PRIORITY_Q_H
