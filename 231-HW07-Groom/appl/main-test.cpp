
/*
================================================================================#=
FILE: appl/main-test.cpp

Test application for the stack class.
================================================================================#=
*/

#include "Stack.hpp"

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <stdexcept>


bool initial_smoke_test(void) {
// Create a stack of integers and perform some basic tests on it.

    using namespace std;

    string stack_string = "";

    // -------------------------------------------------------------+-
    // The Objects Under Test
    // -------------------------------------------------------------+-
    Stack<int>   *the_int_stack = NULL;

    // -------------------------------------------------------------+-
    // New Stack
    // -------------------------------------------------------------+-
    if(the_int_stack != NULL) {
        delete the_int_stack;
        cout << "Stack Destructor Complete. " << endl;
    }
    the_int_stack = new Stack<int>(256);
    cout << "New Stack Complete. " << endl;

    // -------------------------------------------------------------+-
    // New Stack Again
    // -------------------------------------------------------------+-
    if(the_int_stack != NULL) {
        delete the_int_stack;
        cout << "Stack Destructor Complete. " << endl;
    }
    the_int_stack = new Stack<int>(12);
    cout << "New Stack Complete. " << endl;

    // -------------------------------------------------------------+-
    // Print Empty Queue
    // -------------------------------------------------------------+-
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;
    cout << "Depth is: " << the_int_stack->GetDepth() << endl;
    cout << endl;

    // -------------------------------------------------------------+-
    // Push some elements on the stack
    // -------------------------------------------------------------+-
    the_int_stack->Push(7);
    the_int_stack->Push(8);
    the_int_stack->Push(9);
    cout << "After Push 7, 8, & 9..." << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;

    // -------------------------------------------------------------+-
    // Pop some elements from the stack
    // -------------------------------------------------------------+-
    cout << "Top() returns: " << the_int_stack->Top() << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;
    cout << "Pop() returns: " << the_int_stack->Pop() << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;
    cout << "Top() returns: " << the_int_stack->Top() << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;
    cout << "Pop() returns: " << the_int_stack->Pop() << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;
    cout << "Top() returns: " << the_int_stack->Top() << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;
    cout << "Pop() returns: " << the_int_stack->Pop() << endl;
    cout << "Stack is: " << the_int_stack->ToString(stack_string) << endl;

    if(the_int_stack != NULL) {
        delete the_int_stack;
        cout << "Stack Destructor Complete. " << endl;
    }
    return true;
};

template<typename elemType>
bool test_stack(
    Stack<elemType>&  given_stack,
    elemType          test_data[],
    int               num_cases)
// Template function to test the Stack class.
// This function will invoke various member functions on the given stack object
// using the data provided in the test_data array.
// The num_cases parameter defines how many elements are in the test_data array.
{
    using namespace std;
    string stack_string = "";
    string msg_string = "";

    cout << endl;
    cout << "Test Stack Begins... " << endl;

    // -------------------------------------------------------------+-
    // Display initial stack
    // -------------------------------------------------------------+-
    cout << "Stack is: " << given_stack.ToString(stack_string) << endl;
    cout << "Depth is: " << given_stack.GetDepth() << endl;

    // -------------------------------------------------------------+-
    // Push all the given data elements onto the given stack.
    // -------------------------------------------------------------+-
    auto idx = 0;
    while(false == given_stack.IsFull())
    {
        given_stack.Push(test_data[idx]);
        cout << "After Push(" << test_data[idx] << ")..." << endl;
        cout << "Stack is: " << given_stack.ToString(stack_string) << endl;
        idx++;
        if(idx >= num_cases) break;
    }
    if(idx < num_cases) {
        msg_string  = "Stack is too small; idx: " + std::to_string(idx);
        throw(std::runtime_error(msg_string));
    }

    // -------------------------------------------------------------+-
    // Make Empty
    // -------------------------------------------------------------+-
    given_stack.MakeEmpty();
    cout << "After MakeEmpty()" << endl;
    cout << "Stack is: " << given_stack.ToString(stack_string) << endl;

    // -------------------------------------------------------------+-
    // Push again all the given data elements onto the given stack.
    // -------------------------------------------------------------+-
    for(auto idx = 0; idx < num_cases; idx++)
    {
        given_stack.Push(test_data[idx]);
        cout << "After Push(" << test_data[idx] << ")..." << endl;
        cout << "Stack is: " << given_stack.ToString(stack_string) << endl;
    }

    // -------------------------------------------------------------+-
    // Top, Pop, and Verify
    // -------------------------------------------------------------+-
    while(false == given_stack.IsEmpty())
    {
        elemType top_elem = given_stack.Top();
        elemType pop_elem = given_stack.Pop();

        if(top_elem != pop_elem)
        {
            msg_string  = "Mismatch: top: " + std::to_string(top_elem);
            msg_string += "  pop: " + std::to_string(pop_elem);
            throw(std::runtime_error(msg_string));
        }
        cout << "Pop() returns: " << pop_elem << endl;
        cout << "Stack is: " << given_stack.ToString(stack_string) << endl;
    }
    return true;
}

bool test_too_full()
{
    using namespace std;

    string msg_string   = "";
    string stack_string = "";

    cout << endl;
    cout << "Test Too Full Begins... " << endl;

    int push_count = 0;
    int max_depth  = 27; // arbitrary size

    bool pass = true;

    Stack<int> tf_stack(max_depth);

    // Fill the stack
    while(false == tf_stack.IsFull())
    {
        tf_stack.Push(push_count++);
    }
    if(push_count != max_depth)
    {
        msg_string  = "push_count actual: " + std::to_string(push_count);
        msg_string += "  expected: " + std::to_string(max_depth);
        throw(std::runtime_error(msg_string));
    }
    else {
        cout << "After Filling the Stack... " << endl;
        cout << "Stack is: " << tf_stack.ToString(stack_string) << endl;
    }

    // Push one more time to test overflow.
    try {
        // One more push should overflow and cause exception.
        tf_stack.Push(push_count++);

        // If we reach this point, stack did not throw exception as expected.
        pass = false;
        msg_string  = "Full stack did not throw exception.";
        throw(std::runtime_error(msg_string));
    }
    catch(const std::exception& ex) {
        cout << "Caught Exception as expected: " << ex.what() << endl;
    }
    return pass;
};

bool test_too_empty()
{
    using namespace std;

    string msg_string   = "";
    string stack_string = "";

    cout << endl;
    cout << "Test Too Empty Begins... " << endl;

    bool pass = true;

    Stack<int> te_stack;

    // Empty the stack
    te_stack.MakeEmpty();

    cout << "After Making the Stack Empty... " << endl;
    cout << "Stack is: " << te_stack.ToString(stack_string) << endl;

    // Pop to test underflow.
    try {
        // One Pop should underflow and cause exception.
        te_stack.Pop();

        // If we reach this point, stack did not throw exception as expected.
        pass = false;
        msg_string  = "Empty stack did not throw exception.";
        throw(std::runtime_error(msg_string));
    }
    catch(const std::exception& ex) {
        cout << "Caught Exception as expected: " << ex.what() << endl;
    }
    return pass;
};


// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main()
{
    using namespace std;

    // Get the current time and
    // Print a small "banner" to announce that we are starting the test;
    std::time_t start_time = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()
    );
    cout << endl;
    cout << endl;
    cout << "Test Run - begins at: " << std::ctime(&start_time) << endl;

    Stack<int>    stack_of_ints;
    Stack<double> stack_of_doubles;
    Stack<char>   stack_of_chars;

    // -----------------------------------------------------+-
    // Test Data
    // -----------------------------------------------------+-
    int test_data_int[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int test_data_int_len = sizeof(test_data_int)/sizeof(test_data_int[0]);

    double test_data_dbl[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    double test_data_dbl_len = sizeof(test_data_dbl)/sizeof(test_data_dbl[0]);

    char test_data_char[] = {'l', 'o', 'r', 'e', 'm', '-', 'i', 'p', 's', 'u', 'm', '-', 's', 'e', 't'};
    char test_data_char_len = sizeof(test_data_char)/sizeof(test_data_char[0]);

    bool result = true;
    try
    {
        // -----------------------------------------------------+-
        // Smoke Test
        // -----------------------------------------------------+-
        if(result) {
            result = initial_smoke_test();
            cout << "Initial Smoke Test Complete." << endl;
        }

        // -----------------------------------------------------+-
        // Test with int, double, char
        // -----------------------------------------------------+-
        if(result) {
            result = test_stack(stack_of_ints, test_data_int, test_data_int_len);
            cout << "Test Stack<int> Complete." << endl;
        }

        if(result) {
            result = test_stack(stack_of_doubles, test_data_dbl, test_data_dbl_len);
            cout << "Test Stack<double> Complete." << endl;
        }

        if(result) {
            result = test_stack(stack_of_chars, test_data_char, test_data_char_len);
            cout << "Test Stack<char> Complete." << endl;
        }

        // -----------------------------------------------------+-
        // Test Expected Exception Cases
        // -----------------------------------------------------+-
        if(result) {
            result = test_too_full();
            cout << "Test Too Full Complete." << endl;
        }
        if(result) {
            result = test_too_empty();
            cout << "Test Too Empty Complete." << endl;
        }
    }

    catch(const std::exception& ex) {
        cout << "Unexpected Exception: " << ex.what() << endl;
        cout << endl;
        return EXIT_FAILURE;
    }

    if(result)
    {
        cout << endl << endl;
        cout << "All Tests Finished Successfully - Hurrah!" << endl;
        cout << endl;
        return EXIT_SUCCESS;

    } else {
        cout << endl << endl;
        cout << "Test run had one or more FAILED tests." << endl;
        cout << endl;
        return EXIT_FAILURE;
    }
};


