// This is a simple program which displays a menu of choices for
// a gift list. You may add to, remove from, edit, view, and send the gift_list to a txt file.
// This program will demonstrate the use of the class gift_list
// 
// @Author: Adnan Hashem Mohamed
//
#include<iostream>
#include"gift_list.h"
#include<fstream>

using std::cout; using std::cin; using std::endl;
using namespace gift_list_adnan; using std::string;

char get_user_command();
void menu();
Name user_input_name();
gift_list::gifts user_input_gifts();
void get_info(Name&, gift_list::gifts&);
gift_list::gift get_info();
void print_record(std::ostream& outs, const gift_list& the_gift_list, const Name& person);

int main()
{
    cout << "**Note: choices are on the left\n\n";
    char choice;
    gift_list my_list;
    string gift_name;
    int num_of_gifts, count;
    Name person;
    gift_list::gift the_gift;
    gift_list::gifts gifts_container;
    string file_name;
    do
    {
        menu();
        choice = get_user_command();
        switch (choice)
        {
        case '+': 
            get_info(person, gifts_container);
            my_list.add(person, gifts_container);
            cout << endl;
            cout << person << " is successfully added to the list.\n\n";
            break;
        case 'R':
            person = user_input_name();
            if (my_list.in_list(person))
            {
                my_list.remove(person);
                cout << endl;
                cout << person << " is removed from the list.\n\n";
            }
            else
                cout << person << " is not in list.\n\n";
            break;
        case 'E': 
            cout << "Choose from the following:\n";
            cout << "[1] Add gifts to a person.\n";
            cout << "[2] Remove gifts from a person.\n";
            choice = get_user_command();
            if (choice == '1')
            {
                person = user_input_name();
                if (my_list.in_list(person))
                {
                    gifts_container = user_input_gifts();
                    for (int i = 0; i < gifts_container.size(); ++i)
                        my_list.add_gift(person, gifts_container[i]);
                }
                else
                    cout << person << " is not in the list.\n\n";
            }
            else if (choice == '2')
            {
                person = user_input_name();
                if (my_list.in_list(person))
                {
                    cout << "How many gifts would you like to remove?\n";
                    cin >> num_of_gifts;
                    for (int i = 0; i < num_of_gifts; ++i)
                    {
                        cout << "Gift name: ";
                        cin >> gift_name;
                        if (my_list.remove_gift(person, gift_name))
                            cout << "The gift is removed.\n\n";
                        else
                            cout << "The gift was not found in the gifts.\n\n";
                    }
                }
                else
                    cout << person << " is not in the list.\n\n";
            }
            else
                cout << "INVALID CHOICE\n\n";
            break;
        case 'V':
            cout << "Choose from the following:\n";
            cout << "[1] View all.\n";
            cout << "[2] View specific record.\n";
            choice = get_user_command();
            if (choice == '1')
            {
                cout << "*********************\n";
                gift_list_adnan::print_list(cout, my_list);
                cout << "*********************\n";
            }
            else if (choice == '2')
            {
                person = user_input_name();
                if (my_list.in_list(person))
                {
                    cout << "*********************\n";
                    print_record(cout, my_list, person);
                    cout << "*********************\n";
                }
                else
                    cout << person << " is not in the list.\n\n";
            }
            else
                cout << "INVALID CHOICE\n\n";
            break;
        case 'C':
            cout << "Choose from the following:\n";
            cout << "[1] View Total Costs.\n";
            cout << "[2] View specific Cost.\n";
            choice = get_user_command();
            if (choice == '1')
            {
                cout << "Total costs: $" << my_list.gifts_cost() << endl << endl;
            }
            else if (choice == '2')
            {
                person = user_input_name();
                if (my_list.in_list(person))
                {
                    cout << "The costs for " << person << " gifts: $" << my_list.gifts_cost(person) << endl;
                }
                else
                    cout << person << " is not in the list.\n\n";
            }
            else
                cout << "INVALID CHOICE\n\n";
            break;
        case 'S':
            cout << "Choose from the following:\n";
            cout << "[1] Send all to file.\n";
            cout << "[2] Send specific records.\n";
            choice = get_user_command();
            if (choice == '1')
            {
                cout << "Enter the file name (e.g file_name.txt ): ";
                cin >> file_name;
                std::ofstream fout;
                fout.open(file_name);
                gift_list_adnan::print_list(fout, my_list);
                cout << endl;
            }
            else if (choice == '2')
            {
                cout << "Enter the file name (e.g file_name.txt ): ";
                cin >> file_name;
                std::ofstream fout;
                fout.open(file_name);
                cout << "How many people would you like to send ?\n";
                cin >> count;
                for (int i = 0; i < count; ++i)
                {
                    person = user_input_name();
                    if (my_list.in_list(person))
                        print_record(fout, my_list, person);
                    else
                        cout << person << " is not in the list.\n\n";
                }
            }
            else
                cout << "INVALID CHOICE\n\n";
            break;
        case 'Q':// do nothing
            break;
        default:  cout << choice << " is invalid." << endl;
        }
    } while (choice != 'Q');
}

void menu()
{
    cout << "*** MENU ***" << endl;
    cout << "[+] Add a person" << endl;
    cout << "[r] Remove a person" << endl;
    cout << "[e] Edit record" << endl;
    cout << "[v] View person/gifts" << endl;
    cout << "[c] View Costs" << endl;
    cout << "[s] Send to file" << endl;
    cout << "[q] Quit" << endl;
    cout << "--------------------\n";
}

char get_user_command()
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character
    return toupper(command);
}

void get_info(Name& person, gift_list::gifts& the_gifts)
{
    gift_list::gift a_gift;
    person = user_input_name();
    the_gifts = user_input_gifts();
}

gift_list::gift get_info()
{
    string gift_name;
    double gift_price;
    if (cin.peek() == '\n')
        cin.ignore(1);
    cout << "Gift Name: ";
    std::getline(cin, gift_name);
    cout << "Gift Price: $";
    cin >> gift_price;
    gift_list::gift the_gift(gift_name, gift_price);
    return the_gift;
}

Name user_input_name()
{
    string first, middle, last;
    Name person;
    cout << "Enter the name (first middle last): ";
    cin >> first >> middle >> last;
    person.set_first(first); person.set_middle(middle); person.set_last(last);
    
    return person;
}

gift_list::gifts user_input_gifts()
{
    int num_of_gifts;
    gift_list::gift a_gift;
    gift_list::gifts the_gifts;
    
    cout << "How many gifts would you like to add?\n";
    cin >> num_of_gifts;

    for (int i = 0; i < num_of_gifts; ++i)
    {
        a_gift = get_info();
        the_gifts.push_back(a_gift);
    }

    return the_gifts;
}

void print_record(std::ostream& outs, const gift_list& the_gift_list, const Name& person)
{
   print_list(outs, gift_list(person, the_gift_list.get_gifts(person)));
}