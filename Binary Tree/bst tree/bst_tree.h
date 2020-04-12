// This is the interface for the template class bst (stands for: binary search tree)
// A binary search tree is a binary tree such that elements of the tree are ordered 
// so smaller or equal elements are on the left whereas greater elements are on the right.
// The class is within namespace (bst_adnan)
//
//	------ - Copyright © -------- -
//	@Author: Adnan Hashem Mohamd
//	------------------------------ 
//
// TYPEDEF for the bst<Item> template class:
//   Each node of the tree contains a piece of data and pointers to its
//   children. The type of the data (bst<Item>::value_type) is
//   the Item type from the template parameter. The type may be any of the C++
//   built-in types (int, char, etc.), or a class with a default constructor,
//   and an assignment operator and < operator.
//
//   bst<Item>::size_type
//     bst<Item>::size_type is the data type of any variable that keeps track
//     of how many items are in a bst.
//
// CONSTRUCTOR for the bst<Item> class:
//   bst( )
//     Postcondition: The bst is empty.
//
//  binary_tree_adnan::binary_tree_node<Item>* get_root_ptr()const
//    Postcondtion: returns the root_ptr which has the whole tree.
//
// MODIFICATION MEMBER FUNCTIONS for the bst<Item> class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the bst. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the bst, then one copy of target has been
//     removed from the bst; otherwise the bst is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bst.
//
//   void operator +=(const bst& addend)
//     Postcondition: Each item in addend has been added to this bst.
//
// CONSTANT MEMBER FUNCTIONS for the bst<Item> class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bst.
//
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bst.
//
//   bool is_present(const Item& entry)const
//     Postcondition: returns true if the entry is in the bst, else false.
//
// NONMEMBER FUNCTIONS for the bst class:
//   bst operator +(const bst& b1, const bst& b2)
//     Postcondition: The bst returned is the union of b1 and b2.
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
//	template<class Item>
//	void bst_linked_list(const binary_tree_node<Item>* root_ptr)
//	 Precondition: root_ptr is the pointer to the root of a binary search tree.
//	 Postcondition: a pointer to the head of a linked list is returned. The linked list
//	 contains the elements of the bst such that the smallest entries are at the front of the list.
//   
//
// VALUE SEMANTICS for the bst class:
//   Assignments and the copy constructor may be used with bst objects.
//
// DYNAMIC MEMORY USAGE by the bst: 
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc: The constructors, insert, operator +=, operator +, and
//   the assignment operator.

#ifndef BST_H
#define BST_H
#include"binary_tree.h"
#include"Linked List/template_node.h"

namespace bst_adnan {
    template <class Item>
    class bst
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
      
        // CONSTRUCTORS and DESTRUCTOR
        bst();
        bst(const bst& source);
        ~bst();
        // MODIFICATION functions
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator +=(const bst& addend);
        bst& operator =(const bst& source);

        // CONSTANT functions
        size_type size() const { return tree_size(root_ptr); }
        size_type count(const Item& target) const;
        bool is_present(const Item& entry)const { return count(entry) != 0; }
        binary_tree_adnan::binary_tree_node<Item>* get_root_ptr()const { return root_ptr; }
        // FRIENDS

        template <class Item>
        friend void join
        (
            bst<Item>& top,
            bst<Item>& left,
            bst<Item>& right
        );

        template<class Item>
        friend template_node_adnan::node<Item>* to_linked_list(bst<Item> bs_tree);

        void print_tree()const { print(root_ptr, 0); }

    private:
        binary_tree_adnan::binary_tree_node<Item>* root_ptr; // Root pointer of binary search tree
        void insert_all(binary_tree_adnan::binary_tree_node<Item>* addroot_ptr);
    };

    // NONMEMBER functions for the bst<Item> template class
    template <class Item>
    bst<Item> operator +(const bst<Item>& b1, const bst<Item>& b2);

} // end of namespace

#include "bst.template"

#endif // !BST_H

