// This is the implementation file for the class node
// and some other functions used in general with linked lists
// The class node is in the header file: linked_list.h
//
// @Author: Adnan Mohamed

#include<iostream>
#include"linked_list.h"

namespace node_adnan {

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

        size_t length = list_length(source_ptr);
        size_t d_length = length;
        node::value_type* data = new node::value_type[length];

        while (d_length > 0)                              // saving the data of the original list to be inserted
        {                                                 // to the new list. The process of putting the data in the
            data[d_length - 1] = source_ptr->data();      // array takes in account the insertion operation.
            source_ptr = source_ptr->link();
            --d_length;
        }


        list_head_insert(head_ptr, data[0]); // Setting first outside the loop to directly
        tail_ptr = head_ptr;                 // set the tail also. (For efficiency reasons).


        for (size_t i = 1; i < length; ++i)
        {
            list_head_insert(head_ptr, data[i]);
        }

        delete[] data;
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
        size_t max_length = list_length(start_ptr);
        node::value_type* data = new node::value_type[max_length];
        int index = 0;
        while (start_ptr != end_ptr)
        {
            data[index] = start_ptr->data();
            start_ptr = start_ptr->link();
            ++index;
        }
        --index;
        list_head_insert(head_ptr, data[index]);
        --index;
        tail_ptr = head_ptr;

        while (index >= 0)
        {
            list_head_insert(head_ptr, data[index]);
            --index;
        }

        delete[] data;
    }

} // end of namespace