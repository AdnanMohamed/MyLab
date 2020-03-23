//  Stack class test program
//
//  Test: swap()
//

#include"string.hpp"
#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    // stack of int
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> x;
        stack<int> y;
        // TEST
        x.swap(y);

        // VERIFY
        assert(y.empty() && x.empty());
        x.push(3);
        y.push(5);
        assert(y.pop() == 5 && x.pop() == 3);
    }

    {
        stack<int>  x;
        assert(x.empty() == true);
        // TEST
        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);

        stack<int> y;
        y.push(10);
        y.push(9);
        y.push(8);
        y.push(7);

        x.swap(y);

        int i = 7, j = 4;
        while (!x.empty() && !y.empty())
        {
            assert(x.pop() == i && y.pop() == j);
            
            ++i; --j;
        }
    }

        // Testing with String
        {
            //------------------------------------------------------
            // SETUP FIXTURE
    
            // TEST
            stack<String> x;
            stack<String> y;
            y = x;
            assert(y.empty());
            // VERIFY
            y.push("Adnan Mohamed");
            y.swap(x);
            assert(!x.empty() && y.empty());
        }
    
        {
            //------------------------------------------------------
            // SETUP FIXTURE
    
            // TEST
            stack<String> name1;
            stack<String> name2;
    
            name1.push("Mohamed");
            name1.push("Ali");
            name1.push("Mansoor");
            name1.push("Hashem");
            name1.push("Adnan");

            name2.push("Hello");
            name2.push("World");

            name2.swap(name1);
            
            // VERIFY
            assert(name1.pop() == "World");
            assert(name1.pop() == "Hello");

            assert(name2.pop() == "Adnan");
            assert(name2.pop() == "Hashem");
            assert(name2.pop() == "Mansoor");
            assert(name2.pop() == "Ali");
            assert(name2.pop() == "Mohamed");
        }
    
        // stack of char
        {
            //------------------------------------------------------
            // SETUP FIXTURE
    
            // TEST
            stack<char> x;
            stack<char> y;
    
            x.push('1');
            x.push('2');
            x.push('3');
            
            y.push('a');
            y.push('b');
            y.push('c');
            
            x.swap(y);
            
            x.push('d');
            y.push('4');

            // swap again
            y.swap(x);

            assert(x.pop() == '4');
            assert(x.pop() == '3');
            assert(x.pop() == '2');
            assert(x.pop() == '1');

            assert(y.pop() == 'd');
            assert(y.pop() == 'c');
            assert(y.pop() == 'b');
            assert(y.pop() == 'a');
        }

        // swaping the same stack
        {
            stack<String> s;
            s.push("Hi");
            s.push("You");
            s.swap(s);
            assert(s.pop() == "You");
            assert(s.pop() == "Hi");
        }
    


    std::cout << "Done testing swap." << std::endl;
}
