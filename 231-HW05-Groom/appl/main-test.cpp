
/*
================================================================================#=
FILE: appl/main-test.cpp
ACKNOWLEDGEMENTS: Robert Ensink wrote lines 1-23 and 162-201.
David Groom made the rest of the code. 
Test application for the Stack class.
================================================================================#=
*/

#include "Stack.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


// ---------------------------------------------------------------------+-
// TEST THE STACK
// ---------------------------------------------------------------------+-
bool test_the_stack(void)
{
    using namespace std;
    string expected_string = "";
    string actual_string = "";
    int expected_length;
    int actual_length;
    int expected_itemvalue;
    int actual_itemvalue;
    
 
    //Creating a new item
    ItemType *test_object = new ItemType();

    //Creating a new stack
    Stack *test_stack = new Stack();

    cout << endl << "Testing Stack Depth: ";
    //Testing Constructor length
    actual_length = test_stack->GetDepth();
    expected_length = 0;
    cout << "Expected Length:" << to_string(expected_length) << " Actual Length:" << to_string(actual_length) <<  endl; 
    if(actual_length != expected_length)
    {
        return false;
    }

    cout << endl << "Testing IsEmpty: ";
    //Testing IsEmpty
    if(test_stack->IsEmpty() == false)
    {
        cout << "IsEmpty failed!";
        return false;
    }
    cout << "IsEmpty passed" << endl;

    cout << endl << "Testing Push and Top: " << endl;
    //Testing Push and Top
    test_stack->Push(ItemType(3));
    cout << "Pushing 3 onto the stack: " << endl;
    test_stack->ToString(actual_string);
    cout << actual_string << endl;
    *test_object = test_stack->Top();
    actual_itemvalue = test_object->GetValue();
    expected_itemvalue = 3;
    cout << "Top Expected Value: " << to_string(expected_itemvalue) << " Top Actual Value: " << to_string(actual_itemvalue) << endl;
    if(actual_itemvalue != expected_itemvalue)
    {
        return false;
    }

    actual_string.clear();
    cout << endl << "Testing Pop:" << endl;
    //Testing Pop return item portion
    cout << "Stack before Pop: " << endl;
    test_stack->ToString(actual_string);
    cout << actual_string << endl;
    actual_string.clear();

    cout << "Stack after Pop: " << endl;
    *test_object = test_stack->Pop();
    test_stack->ToString(actual_string);
    cout << actual_string << endl;
    actual_string.clear();

    actual_itemvalue = test_object->GetValue();
    expected_itemvalue = 3;
    cout << "Expected Pop Return Value: " << to_string(expected_itemvalue) << " Actual Pop Return Value: " << to_string(actual_itemvalue) << endl;

    cout << endl << "Testing Top when nothing is in the stack: " << endl;
    //Testing Top after Pop when nothing is in the stack
    try
    {
        cout << "Expected Value: " << "An error" << endl << " Actual Value: ";
        *test_object = test_stack->Top();
        actual_itemvalue = test_object->GetValue();
        cout << to_string(actual_itemvalue) << endl;
        return false;
    }
    catch(const invalid_argument& exception)
    {
        cout << "You cannot Top an empty list" << endl;
    }


    //Testing Pop when there is nothing in the stack
    cout << endl << "Testing Pop when there is nothing in the stack: " << endl;
    try
    {
        cout << "Expected Value: " << "An error" << endl << " Actual Value: ";
        *test_object = test_stack->Pop();
        actual_itemvalue = test_object->GetValue();
        cout << to_string(actual_itemvalue) << endl;
        return false;
    }
    catch(const invalid_argument& exception)
    {
        cout << "You cannot Pop an empty list" << endl;
    }

    //Adding items to stack
    cout << endl << "Adding Items...";
    test_stack->Push(ItemType(3));
    test_stack->Push(ItemType(5));
    test_stack->Push(ItemType(1));
    actual_string.clear();

    cout << endl << "Testing Stack Depth Again: ";
    //Testing StackLength length
    actual_length = test_stack->GetDepth();
    expected_length = 3;
    cout << "Expected Length:" << to_string(expected_length) << " Actual Length:" << to_string(actual_length) <<  endl; 
    if(actual_length != expected_length)
    {
        return false;
    }

    //Testing Make Empty
    cout << endl << "Testing MakeEmpty: " << endl; 
    test_stack->ToString(actual_string);
    cout << endl << "Stack before MakeEmpty: " << actual_string << endl; 
    test_stack->MakeEmpty();
    test_stack->ToString(actual_string);
    cout << "Stack after MakeEmpty: " << actual_string << endl; 

    //Testing IsFull
    cout << endl << "Testing IsFull: " << endl; 
    if(test_stack->IsFull() == false)
    {
        cout << "IsFull Passed!" << endl; 
    }
    else
    {
        cout << endl << " IsFull Failed. This is literally impossible..." << endl;
        return false; 
    }

    cout << endl << "You did it! You're not sus!" << endl;

    return true;
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

    try
    {
        if(!test_the_stack())
        {
            cout << endl << endl;
            cout << "Test run had one or more failed tests." << endl;
            cout << endl;
            return EXIT_FAILURE;

        } else {
            cout << endl << endl;
            cout << "All Tests Finished Successfully - Hurrah!" << endl;
            cout << endl;
            return EXIT_SUCCESS;
        }
    }
    catch(const std::exception& ex) {
        cout << "    Exception: " << ex.what() << endl;
        cout << endl;
        return EXIT_FAILURE;
    }
};
