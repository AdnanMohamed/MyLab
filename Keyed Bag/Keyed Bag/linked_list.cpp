// This is the implementation file for the class node
// and some other functions used in general with linked lists
// The class node is in the header file: linked_list.h
//
// @Author: Adnan Mohamed

#include<iostream>
#include"linked_list.h"
#include<cassert>
#include<string>

namespace keyed_bag_adnan {

    size_t list_length(const node* head_ptr)
    {
        size_t count = 0;
        const node* cursor = head_ptr;
        while (cursor != NULL)
        {
            count++;
            cursor = cursor->link();
        }

        return count;
    }

    void list_head_insert(Node_Ptr& head_ptr, const node::value_type& entry)
    {
        Node_Ptr new_node = new node(entry, head_ptr);
        head_ptr = new_node;
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
        Node_Ptr new_node = new node(entry, previous_ptr->link());
        previous_ptr->set_link(new_node);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    {
        while (head_ptr != NULL)
        {
            if (head_ptr->data() == target)
                return head_ptr;
            head_ptr = head_ptr->link();
        }
        return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    {
        while (head_ptr != NULL)
        {
            if (head_ptr->data() == target)
                return head_ptr;
            head_ptr = head_ptr->link();
        }
        return head_ptr;
    }

    node* list_locate(node* head_ptr, std::size_t position)
    {
        if (head_ptr == NULL || position < 1)
            return NULL;
        while (position > 1)
        {
            head_ptr = head_ptr->link();
            --position;
        }
        return head_ptr;
    }

    const node* list_locate(const node* head_ptr, std::size_t position)
    {
        if (head_ptr == NULL || position < 1)
            return NULL;
        while (position > 1)
        {
            head_ptr = head_ptr->link();
            --position;
        }
        return head_ptr;
    }

    void list_head_remove(Node_Ptr& head_ptr)
    {
        assert(head_ptr != NULL);

        Node_Ptr temp = new node;
        temp = head_ptr;
        head_ptr = head_ptr->link();
        delete temp;
    }

    void list_remove(node* previous_ptr)
    {
        Node_Ptr temp = new node;
        temp = previous_ptr->link();
        previous_ptr->set_link(temp->link());
        delete temp;
    }

    void list_clear(Node_Ptr& head_ptr)
    {
        while (head_ptr != NULL)
        {
            list_head_remove(head_ptr);
        }
    }

    void list_copy(const node* source_ptr, Node_Ptr& head_ptr, Node_Ptr& tail_ptr)
    {
        if (source_ptr == NULL)
        {
            head_ptr = NULL;
            tail_ptr = NULL;
            return;
        }

        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;
        source_ptr = source_ptr->link();

        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data());
            source_ptr = source_ptr->link();
            tail_ptr = tail_ptr->link();
        }

    }

    void list_copy(const node* source_ptr, Node_Ptr& head_ptr)
    {
        if (source_ptr == NULL)
        {
            head_ptr = NULL;
            return;
        }
        list_head_insert(head_ptr, source_ptr->data());
        Node_Ptr tail_ptr = head_ptr;
        source_ptr = source_ptr->link();

        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data());
            source_ptr = source_ptr->link();
            tail_ptr = tail_ptr->link();
        }
    }

    void list_piece(const node* start_ptr, const node* end_ptr,
        Node_Ptr& head_ptr, Node_Ptr& tail_ptr)
    {
        if (start_ptr == NULL || start_ptr == end_ptr)
        {
            head_ptr = NULL;
            tail_ptr = NULL;
            return;
        }

        list_head_insert(head_ptr, start_ptr->data());
        tail_ptr = head_ptr;
        start_ptr = start_ptr->link();

        while (start_ptr != end_ptr)
        {
            list_insert(tail_ptr, start_ptr->data());
            start_ptr = start_ptr->link();
            tail_ptr = tail_ptr->link();
        }

    }

    /*std::ostream& operator<<(std::ostream& outs, const node* head_ptr)
    {
        const node* cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        {
            outs << cursor->data() << " ";
        }
        return outs;
    }*/

    std::size_t list_occurrences(const node* head_ptr, const node::value_type& target)
    {
        size_t count = 0;
        for (auto cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        {
            if (cursor->data() == target)
            {
                ++count;
            }
        }
        return count;
    }

    void list_tail_attach(node*& head_ptr, const node::value_type& entry)
    {
        if (head_ptr == NULL) // If the list is empty this will be the first node
        {
            list_head_insert(head_ptr, entry);
            return;
        }
        node* new_node = new node(entry, NULL); // creates the new node to be attached
        auto cursor = head_ptr;
        while (cursor->link() != NULL)  // moves the cursor to the tail of the list
        {
            cursor = cursor->link();
        }
        cursor->set_link(new_node);
    }

    void list_tail_remove(node*& head_ptr)
    {
        // Assuming not empty list
        assert(head_ptr != NULL);

        // If one node in the list, remove it.
        if (head_ptr->link() == NULL)
        {
            list_head_remove(head_ptr);
            return;
        }

        node* temp = new node;
        auto cursor = head_ptr;
        // moves the cursor to the node before the tail
        while (cursor->link()->link() != NULL)
        {
            cursor = cursor->link();
        }
        temp = cursor->link();
        cursor->set_link(NULL);
        delete temp;
    }

    node* list_copy_front(const node* source_ptr, std::size_t n)
    {
        assert(n <= list_length(source_ptr) && n >= 0);

        node* head_ptr = NULL;
        if (n == 0)
            return head_ptr;
        // insert the first node
        list_head_insert(head_ptr, source_ptr->data());
        source_ptr = source_ptr->link();
        --n;
        for (size_t i = 0; i < n; ++i, source_ptr = source_ptr->link())
        {
            list_tail_attach(head_ptr, source_ptr->data());
        }

        return head_ptr;
    }

} // end of namespace