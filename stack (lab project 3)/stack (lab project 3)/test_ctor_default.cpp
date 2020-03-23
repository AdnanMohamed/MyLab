//  Stack class test program
//
//  Testing default constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;

        // VERIFY
        assert(x.empty() == true);
    }


    std::cout << "Done testing default ctor." << std::endl;

}
