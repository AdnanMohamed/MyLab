////  Stack class test program
////
////  Tests: =
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
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//
//        // TEST
//        stack<int> x;
//        stack<int> y;
//        y = x;
//        
//        // VERIFY
//        assert(y.empty());
//        y.push(1);
//        assert(x.empty() && !y.empty());
//    }
//
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//
//        // TEST
//        stack<int> x;
//        stack<int> y;
//        y = x;
//
//        // VERIFY
//        assert(y.empty());
//        y.push(1);
//        y.push(2);
//        x.push(6);
//        assert(x.top() != y.top());
//    }
//
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//
//        // TEST
//        stack<int> x;
//        x.push(1);
//        x.push(2);
//        x.push(3);
//        stack<int> y;
//        y = x;
//
//        // VERIFY
//        assert(!y.empty());
//        assert(y.top() == 3);
//        while (!x.empty())
//            x.pop();
//        assert(y.top() == 3);
//    }
//
//    // Testing with String
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//
//        // TEST
//        stack<String> x;
//        stack<String> y;
//        y = x;
//        assert(y.empty());
//        // VERIFY
//        y.push("Adnan Mohamed");
//        assert(x.empty() && !y.empty());
//    }
//
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//
//        // TEST
//        stack<String> name1;
//        stack<String> name2;
//        stack<String> name3;
//
//        name1.push("Adnan Mohamed");
//        name2 = name3 = name1;
//        
//        // VERIFY
//        assert(name1.top() == "Adnan Mohamed" && name2.top() == name1.top() 
//            && name3.top() == name1.top());
//        name3.pop();
//        assert(name3.empty() && !name1.empty() && !name2.empty());
//    }
//
//    {
//        //------------------------------------------------------
//        // SETUP FIXTURE
//
//        // TEST
//        stack<String> x;
//        stack<String> y;
//
//        x.push("");
//        x.push("Hello");
//        x.push("1234");
//        x.push("Adnan");
//        y = x;
//        // VERIFY
//        assert(x.empty() == false);
//        assert(y.top() == x.top() && x.top() == "Adnan");
//        x.pop(); y.pop();
//        assert(x.top() == "1234" && y.top() == "1234");
//        x.pop(); y.pop();
//        assert(x.top() == "Hello" && y.top() == "Hello");
//        x.pop(); y.pop();
//        assert(x.top() == "" && y.top() == "");
//        x.pop(); y.pop();
//
//        assert(x.empty() && y.empty());
//        y.push("Change");
//        assert(x.empty() && y.top() == "Change");
//    }
//
//    std::cout << "Done testing assign." << std::endl;
//
//}
