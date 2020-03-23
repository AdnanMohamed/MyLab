////  Stack class test program
////
////  Testing push and pop
////
//
//#include "stack.hpp"
//#include <cassert>
//#include <iostream>
//
//typedef std::string String;
//
////===========================================================================
//int main()
//{
//    // testing stack of integers
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//        stack<int>  x;
//        assert(x.empty() == true);
//        // TEST
//        x.push(1);
//        x.push(2);
//        x.push(3);
//        x.push(4);
//
//        // VERIFY
//        assert(x.empty() == false);
//        int i = 4;
//        while (!x.empty())
//        {
//            assert(x.pop() == i);
//            --i;
//        }
//
//    }
//
//
//    // testing Stack of String
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//        stack<String>  x;
//        assert(x.empty() == true);
//        // TEST
//        x.push("");
//        x.push("Hello");
//        x.push("1234");
//        x.push("Adnan");
//
//        // VERIFY
//        assert(x.empty() == false);
//        assert(x.top() == "Adnan" && x.pop()== "Adnan");
//        assert(x.top() == "1234" && x.pop() == "1234");
//        assert(x.top() == "Hello" && x.pop() == "Hello");
//        assert(x.top() == "" && x.pop() == "");
//    }
//
//    // Testing with char
//        // testing Stack of String
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//        stack<char>  x;
//        assert(x.empty() == true);
//        // TEST
//        x.push('4');
//        x.push('3');
//        x.push('2');
//        x.push('a');
//
//        // VERIFY
//        assert(x.empty() == false);
//
//        assert(x.top() == 'a' && x.pop() == 'a');
//        assert(x.top() == '2' && x.pop() == '2');
//        assert(x.top() == '3' && x.pop() == '3');
//        assert(x.top() == '4' && x.pop() == '4');
//    }
//
//    std::cout << "Done testing push_pop." << std::endl;
//}
