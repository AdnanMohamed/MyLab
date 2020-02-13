// This header file contains class node and some 
// linked lists toolkit functions
// The class Node and the helping functions are within namespace courses_adnan
// @Author: Main and Savitch

// CLASS Course:
//  CONSTRUCTORS:
//   Course(std::string course_name = " ", int credit_hours = int(), std::string letter_grade = " ")
//    Postcondition: The course has a name, credit hours, and letter grade.
//
//  ACCESSORS:
//	 std::string get_course_name()const
//	  Postcodition: returns the course name
//
//   int get_course_hours()const
//	  Postcondition: returns the course credit hours
//
//	 std::string get_course_grade()const
//	  Postcondition: returns the course's letter grade
//
//  MUTATORS
//   void set_course_name(std::string name)
//	  Postcondition: The name of the course is the set to the given argument.
//
//	 void set_credit_hours(int credit_hours)
//	  Postcondition: The credit hours of the course is the set to the given argument.
//
//	 void set_letter_grade(std::string letter_grade)
//    Postcondition: The letter grade of the course is the set to the given argument.
//
//  NON MEMBER FUNCTIONS:
//	 std::ostream& operator<<(std::ostream& outs, const Course& the_course)
//	  Postcondition: Prints out the course's name, credit hours, letter grade.
//
//	 bool operator==(const Course& course1, const Course& course2);
//	  Postcondition: Returns True if course1 has the same name, credit hours otherwise false
//

// TYPEDEF for the node class:
//     typedef node* Node_Ptr&;
//
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is defined as node::value_type in a
//     typedef statement. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the node class:
//   node(
//     const value_type& init_data = value_type(),
//     node* init_link = NULL
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*). 
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//   
//   void set_link(node* new_link)
//     Postcondition: The node now contains the specified new link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this node.
//
//   const node* link( ) const <----- const version
//   node* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node.
//   
// FUNCTIONS in the linked list toolkit:
//   size_t list_length(const node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list.
//
//   void list_head_insert(Node_Ptr& head_ptr, const node::value_type& entry) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   void list_insert(node* previous_ptr, const node::value_type& entry) 
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   const node* list_search(const node* head_ptr, const node::value_type& target) 
//   node* list_search(node* head_ptr, const node::value_type& target) 
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned.
//
//   const node* list_locate(const node* head_ptr, size_t position) 
//   node* list_locate(node* head_ptr, size_t position) 
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned.
//
//   void list_head_remove(Node_Ptr& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   void list_remove(node* previous_ptr) 
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   void list_clear(Node_Ptr& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   void list_copy(const node* source_ptr, Node_Ptr& head_ptr, Node_Ptr& tail_ptr) 
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//
//   void list_copy(const node* source_ptr, Node_Ptr& head_ptr);
//     Precondition: source_ptr is a pointer pointing to the head of the original list.
//     Postcondition: head_ptr is a pointer pointing to the head of a new list which contains
//     the same values of the nodes in the original list.
//
//  void list_piece(
//    const node* start_ptr, const node* end_ptr, 
//    Node_Ptr& head_ptr, Node_Ptr& tail_ptr
//  )
//    Precondition: start_ptr and end_ptr are pointers to nodes on the same
//    linked list, with the start_ptr node at or before the end_ptr node
//    Postcondition: head_ptr and tail_ptr are the head and tail pointers for a
//    new list that contains the items from start_ptr up to but not including 
//    end_ptr.  The end_ptr may also be NULL, in which case the new list 
//    contains elements from start_ptr to the end of the list.
//
//  std::ostream& operator<<(std::ostream& outs, const node* head_ptr);
//    Precondition: head_ptr is the pointer to the head node in the list.
//    Postcondition: The list will be printed to the stream.
//
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#ifndef MAIN_SAVITCH_NODE1_H  
#define MAIN_SAVITCH_NODE1_H
#include <cstdlib> // Provides size_t and NULL

namespace courses_adnan
{

    class Course {
    public:
        // CONTRUCTOR

        Course(std::string course_name = " ", int credit_hours = 0, std::string letter_grade = " ")
            :name_(course_name), credit_hours_(credit_hours), letter_grade_(letter_grade) {}

        // Accessors
        std::string get_course_name()const { return name_; }
        int get_course_hours()const { return credit_hours_; }
        std::string get_course_grade()const { return letter_grade_; }

        // MUTATORS
        void set_course_name(std::string name) { name_ = name; }
        void set_credit_hours(int credit_hours) { credit_hours_ = credit_hours; }
        void set_letter_grade(std::string letter_grade) { letter_grade_ = letter_grade; }

        friend std::ostream& operator<<(std::ostream& outs, const Course& the_course);
        friend bool operator==(const Course& course1, const Course& course2);

    private:
        std::string name_;
        int credit_hours_;
        std::string letter_grade_;
    };

    class node
    {
    public:
        // TYPEDEF
        typedef Course value_type;

        // CONSTRUCTOR
        node(
            const value_type& init_data = value_type(),
            node* init_link = NULL
        )
        {
            data_field = init_data; link_field = init_link;
        }

        // Member functions to set the data and link fields:
        void set_data(const value_type& new_data) { data_field = new_data; }
        void set_link(node* new_link) { link_field = new_link; }

        // Constant member function to retrieve the current data:
        value_type data() const { return data_field; }

        // Two slightly different member functions to retreive
        // the current link:
        const node* link() const { return link_field; }
        node* link() { return link_field; }

    private:
        value_type data_field;
        node* link_field;
    };

    typedef node* Node_Ptr;

    // FUNCTIONS for the linked list toolkit
    std::size_t list_length(const node* head_ptr);
    void list_head_insert(Node_Ptr& head_ptr, const node::value_type& entry);
    void list_insert(node* previous_ptr, const node::value_type& entry);
    node* list_search(node* head_ptr, const node::value_type& target);
    const node* list_search(const node* head_ptr, const node::value_type& target);
    node* list_locate(node* head_ptr, std::size_t position);
    const node* list_locate(const node* head_ptr, std::size_t position);
    void list_head_remove(Node_Ptr& head_ptr);
    void list_remove(node* previous_ptr);
    void list_clear(Node_Ptr& head_ptr);
    void list_copy(const node* source_ptr, Node_Ptr& head_ptr, Node_Ptr& tail_ptr);
    void list_copy(const node* source_ptr, Node_Ptr& head_ptr);
    void list_piece(const node* start_ptr, const node* end_ptr,
        Node_Ptr& head_ptr, Node_Ptr& tail_ptr);
    std::ostream& operator<<(std::ostream& outs, const node* head_ptr);
}

#endif

