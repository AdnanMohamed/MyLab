// This is the implementation file for the classes node and Course
// node will be a node in a linked list of courses
// The class node is in the header file: course_list.h
//
// @Author: Adnan Mohamed

#include<iostream>
#include"course_list.h"

namespace courses_adnan {

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

    std::ostream& operator<<(std::ostream& outs, const node* head_ptr)
    {
        const node* cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        {
            outs << cursor->data() << " ";
        }
        return outs;
    }


    // The following is related to the class Course

    std::ostream& operator<<(std::ostream& outs, const Course& the_course)
    {
        outs << "Course Name: " << the_course.name_ << std::endl;
        outs << "Credits Hours: " << the_course.credit_hours_ << std::endl;
        outs << "Letter Grade: " << the_course.letter_grade_;
        return outs;
    }

    bool operator==(const Course& course1, const Course& course2)
    {
        return course1.letter_grade_ == course2.letter_grade_
            && course1.name_ == course2.name_;
    }

} // end of namespace