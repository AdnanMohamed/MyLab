//  Stack class test program
//
//  Tests: cpy ctor
//
#include"string.hpp"
#include "stack.hpp"
#include <cassert>
#include <iostream>



//===========================================================================
int main()
{
    // stack of doubles
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<double>  x;
        stack<double> y(x);
        // VERIFY
        assert(x.empty() && y.empty());
        y.push(7.7);
        x.push(-3.1);
        assert(y.top() == 7.7 && x.top() == -3.1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<double>  x;
        x.push(1.1);
        x.push(2.2);
        x.push(3.3);
        stack<double> y(x);
        // VERIFY
        assert(!x.empty() && !y.empty());
        assert(x.pop() == 3.3 && y.pop() == 3.3);
        assert(x.pop() == 2.2 && y.pop() == 2.2);
        assert(x.pop() == 1.1 && y.pop() == 1.1);
    }

    // stack of strings
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<double>  x;
        stack<double> y(x);
        // VERIFY
        assert(x.empty() && y.empty());
        y.push(7.7);
        x.push(-3.1);
        assert(y.top() == 7.7 && x.top() == -3.1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x;
        stack<String> y(x);
        assert(y.empty());
        // VERIFY
        y.push("Adnan Mohamed");
        assert(x.empty() && !y.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> name1;
        name1.push("Adnan");
        name1.push("Mohamed");
        
        stack<String> name2(name1);
        stack<String> name3(name1);
        // VERIFY
        assert(name1.top() == "Mohamed" && name2.top() == name1.top()
            && name3.top() == name1.top());
        name3.pop();
        name3.pop();
        assert(name3.empty() && !name1.empty() && !name2.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x;


        x.push("");
        x.push("Hello");
        x.push("1234");
        x.push("Adnan");
        stack<String> y(x);
        // VERIFY
        assert(x.empty() == false);
        assert(y.top() == x.top() && x.top() == "Adnan");
        x.pop(); y.pop();
        assert(x.top() == "1234" && y.top() == "1234");
        x.pop(); y.pop();
        assert(x.top() == "Hello" && y.top() == "Hello");
        x.pop(); y.pop();
        assert(x.top() == "" && y.top() == "");
        x.pop(); y.pop();

        assert(x.empty() && y.empty());
        y.push("Change");
        assert(x.empty() && y.top() == "Change");
    }

    std::cout << "Done testing copy constructor." << std::endl;

}
