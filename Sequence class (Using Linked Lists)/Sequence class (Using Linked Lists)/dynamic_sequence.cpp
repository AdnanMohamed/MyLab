// This is the implementation file for the class sequence.
// The class interface is in dynamic_sequenc.h
// @Author: Adnan Mohamed
//
// CLASS INVARIANT:
//  1- node_adnan::node* head_ptr_ - pointing to the head of the list
//  2- node_adnan::node* tail_ptr_ - pointing to the last node in the list
//  3- node_adnan::node* cursor_ - pointing to the current node in the list
//  4- node_adnan::node* precursor_ - pointing to the item before the item pointed to by cursor
//  5- size_type many_nodes_ - equals the number of nodes in the list

#include<iostream>
#include"dynamic_sequence.h"
#include"linked_list.cpp"
#include<cassert>

namespace dynamic_sequence_adnan{

    sequence::sequence()
    {
        many_nodes_ = 0;
        head_ptr_ = NULL;
        tail_ptr_ = NULL;
        cursor_ = NULL;
        precursor_ = NULL;
    }

    sequence::sequence(const sequence& source)
    {
        many_nodes_ = source.many_nodes_;
        head_ptr_ = NULL;
        node_adnan::list_copy(source.head_ptr_, head_ptr_, tail_ptr_);
        cursor_ = head_ptr_;
        precursor_ = head_ptr_;
    }

    sequence::~sequence()
    {
        node_adnan::list_clear(head_ptr_);
        many_nodes_ = 0;
        tail_ptr_ = NULL;
        cursor_ = NULL;
        precursor_ = NULL;
    }

    void sequence::start()
    {
        cursor_ = head_ptr_;
        precursor_ = head_ptr_;
    }

    void sequence::advance()
    {
        if (cursor_ != NULL)
        {
            precursor_ = cursor_;
            cursor_ = cursor_->link();
        }
    }

    void sequence::insert(const value_type& entry)
    {

        if (!is_item())
        {
            node_adnan::list_head_insert(head_ptr_, entry);
            tail_ptr_ = head_ptr_;
            cursor_ = head_ptr_;
            precursor_ = head_ptr_;
            ++many_nodes_;
            return;
        }
        
        if (cursor_ == head_ptr_)
        {
            node_adnan::list_head_insert(head_ptr_, entry);
            cursor_ = head_ptr_;
            precursor_ = head_ptr_;
        }
        else
        {
            node_adnan::list_insert(precursor_, entry);
            cursor_ = precursor_->link();
        }
        ++many_nodes_;
    }

    void sequence::attach(const value_type& entry)
    {

        if (!is_item())
        {
            node_adnan::list_head_insert(head_ptr_, entry);
            tail_ptr_ = head_ptr_;
            cursor_ = head_ptr_;
            precursor_ = head_ptr_;
        }
        else
        {
            node_adnan::list_insert(cursor_, entry);
            precursor_ = cursor_;
            cursor_ = cursor_->link();
            if (cursor_->link() == NULL)
                tail_ptr_ = cursor_;
        }
        ++many_nodes_;
    }

    sequence::value_type sequence::operator[](const size_type& index)const
    {
        assert(index >= 0 && index < many_nodes_);
        return node_adnan::list_locate(head_ptr_, index + 1)->data();
    }

    std::ostream& operator <<(std::ostream& outs, const sequence& s)
    {
        for (auto cursor = s.head_ptr_; cursor != NULL; cursor = cursor->link())
        {
            outs << cursor->data() << " ";
        }
        return outs;
    }

    sequence::value_type sequence::current() const
    {
        assert(cursor_ != NULL);

        return cursor_->data();
    }

    bool sequence::is_item() const
    {
        if (cursor_ != NULL)
            return true;
        else
            return false;
    }

    void sequence::remove_current()
    {
        assert(is_item());
        if (cursor_ == head_ptr_)
        {
            node_adnan::list_head_remove(head_ptr_);
            cursor_ = head_ptr_;
        }
        else
        {
            node_adnan::list_remove(precursor_);
            cursor_ = precursor_->link();
        }
        --many_nodes_;
    }

    void sequence::operator =(const sequence& source)
    {
        if (this != &source)
        {
            this->~sequence();
            many_nodes_ = source.many_nodes_;
            node_adnan::list_copy(source.head_ptr_, head_ptr_, tail_ptr_);
            cursor_ = head_ptr_;
            precursor_ = head_ptr_;
        }
    }

    void sequence::operator+=(const sequence& addend)
    {
        if (addend.many_nodes_ == 0) // if it's an empty sequence, no need to proceed
            return;
        
        if (many_nodes_ == 0)
        {
            for (auto cursor = addend.head_ptr_; cursor != NULL; cursor = cursor->link())
            {
                this->attach(cursor->data());
            }
            return;
        }

        int i = 0;
        int max = addend.many_nodes_;
        cursor_ = tail_ptr_;
        for (auto cursor2 = head_ptr_; i < max; cursor2 = cursor2->link(), ++i)
        {
            this->attach(cursor2->data());
        }
        
    }

    sequence operator+(const sequence& s1, const sequence& s2)
    {
        sequence temp(s1);
        temp += s2;
        return temp;
    }

} // end of namespace