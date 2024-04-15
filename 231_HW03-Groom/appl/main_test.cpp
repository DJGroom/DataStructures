
/*
================================================================================#=
FILE: appl/main_test.cpp

Test application for the Unsorted List.
================================================================================#=
*/

#include "UnsortedList.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


enum TestOperationType
{
    NEW_LIST,
    GET_LENGTH,
    IS_FULL,
    PUT_ITEM,
    MAKE_EMPTY,
    GET_ITEM,
    DELETE_ITEM,
    PRINT_LIST,
    RESET_LIST,   // @@@ TODO:
    GET_NEXT,   // @@@ TODO:
   /*SPLIT_LIST,*/ 
};


struct TestStep
{
    TestOperationType oper;
    ItemType          item;
    int               expected_int;
    bool              expected_bool;
};


std::string test_get_length(UnsortedList* given_list, TestStep given_step)
{
    std::string result_string = "";

    int expected_length = given_step.expected_int;
    int actual_length = given_list->GetLength();

    if(actual_length != expected_length) {
        result_string  = "Expected Length: " + std::to_string(expected_length);
        result_string += "  Got: " + std::to_string(actual_length);
    }
    return result_string;
};

std::string test_is_full(UnsortedList* given_list, TestStep given_step)
{
    std::string result_string = "";

    int expected_bool = given_step.expected_bool;
    int actual_bool = given_list->IsFull();

    if(actual_bool != expected_bool) {
        result_string  = "Expected Result: " + std::to_string(expected_bool);
        result_string += "  Got: " + std::to_string(actual_bool);
    }
    return result_string;
};

std::string test_put_item(UnsortedList* given_list, TestStep given_step)
{
    std::string result_string = "";

    given_list->PutItem(given_step.item);

    return result_string;
};

std::string test_make_empty(UnsortedList* given_list)
{
    std::string result_string = "";

    given_list->MakeEmpty();

    return result_string;
};

std::string test_get_item(UnsortedList* given_list, TestStep given_step)
{
    std::string result_string = "";
    std::string item_string = "";

    bool expected_found_flag = given_step.expected_bool;
    bool actual_found_flag = !expected_found_flag;

    ItemType actual_item = given_list->GetItem(given_step.item, actual_found_flag);

    if(actual_found_flag != expected_found_flag) {
        result_string  = "Expected Found Result: " + std::to_string(expected_found_flag);
        result_string += "  Got: " + std::to_string(actual_found_flag);
        return result_string;
    }

    if(EQUAL != actual_item.ComparedTo(given_step.item)) {
        result_string  = "Expected Item: " + given_step.item.ToString(item_string);
        result_string += "  Got: " + actual_item.ToString(item_string);
        return result_string;
    }

    return result_string;

};

std::string test_delete_item(UnsortedList* given_list, TestStep given_step)
{
    std::string result_string = "";

    given_list->DeleteItem(given_step.item);

    return result_string;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
// Driver/Dispatcher for all tests.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
bool test_list_operations(void)
{
    using namespace std;

    bool all_tests_passed = true;

    static TestStep test_steps[] = {

        {NEW_LIST,    ItemType(),  0, false},
        {NEW_LIST,    ItemType(),  0, false},
        {GET_LENGTH,  ItemType(),  0, false},

        {PUT_ITEM,    ItemType(1), 0, false},
        {PUT_ITEM,    ItemType(2), 0, false},
        {PUT_ITEM,    ItemType(3), 0, false},
        {PRINT_LIST,  ItemType(),  0, false},
        {GET_LENGTH,  ItemType(),  3, false},

        {MAKE_EMPTY,  ItemType(),  0, false},
        {GET_LENGTH,  ItemType(),  0, false},
        {PUT_ITEM,    ItemType(1), 0, false},
        {PUT_ITEM,    ItemType(2), 0, false},
        {PUT_ITEM,    ItemType(3), 0, false},
        {PUT_ITEM,    ItemType(4), 0, false},
        {PUT_ITEM,    ItemType(5), 0, false},
        {IS_FULL,     ItemType(),  0, false},
        {GET_LENGTH,  ItemType(),  5, false},
        {PRINT_LIST,  ItemType(),  0, false},
        {GET_ITEM,    ItemType(4), 0, true},

        {DELETE_ITEM, ItemType(3), 0, false},
        {PRINT_LIST,  ItemType(),  0, false},
        {DELETE_ITEM, ItemType(1), 0, false},
        {PRINT_LIST,  ItemType(),  0, false},
        {DELETE_ITEM, ItemType(5), 0, false},
        {PRINT_LIST,  ItemType(),  0, false},
        {GET_LENGTH,  ItemType(),  2, false},
    };

    // -------------------------------------------------------------+-
    // The Object Under Test.
    // -------------------------------------------------------------+-
    UnsortedList *the_list = NULL;
    int length;

    // -------------------------------------------------------------+-
    // Dispatch each test step to the appropriate test function.
    // -------------------------------------------------------------+-
    auto test_step_num = 0;
    for(auto step: test_steps) {
        cout << "Testing step number: " << ++test_step_num << " - ";

        std::string result;
        std::string item_string;

        try {
            switch(step.oper) {

            case NEW_LIST:
                cout << "New List. " << flush;
                if(the_list != NULL) delete the_list;
                the_list = new UnsortedList;
                cout << "New List Complete. " << flush;
                break;

            case GET_LENGTH:
                cout << "Get Length: ";
                result = test_get_length(the_list, step);
                break;

            case IS_FULL:
                cout << "Is Full: ";
                result = test_is_full(the_list, step);
                break;

            case MAKE_EMPTY:
                cout << "Make Empty: ";
                result = test_make_empty(the_list);
                break;

            case PUT_ITEM:
                cout << "Put Item: ";
                result = test_put_item(the_list, step);
                break;

            case GET_ITEM:
                cout << "Get Item: ";
                result = test_get_item(the_list, step);
                break;

            case DELETE_ITEM:
                cout << "Delete Item: ";
                result = test_delete_item(the_list, step);
                break;

            case PRINT_LIST:
                cout << "Print List: ";
                the_list->ResetList();
                length = the_list->GetLength();
                for(auto count = 0; count < length; count++)
                {
                    if(count > 0) cout << ", ";
                    ItemType next_item = the_list->GetNextItem();
                    cout << next_item.ToString(item_string);
                }
                cout << "  ";
                break;
            /*case SPLIT_LIST:
                cout << "Split List: ";
                result = test_split_list(the_split_list, list1, list2, step)
                */
            default:
                throw std::runtime_error("Unrecognized Operation!");
                break;
            }
        }
        catch(const std::exception& ex) {
            all_tests_passed = false;
            cout << "    Exception: " << ex.what() << endl;
            cout << endl;
        }

        if(result.length() > 0)
            all_tests_passed = false;
        else
            result = "Passed.";
        cout << result << endl;
    }
    return all_tests_passed;
};

// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {
    using namespace std;

    // Get the current time and
    // Print a small "banner" to announce that we are starting the test;
    std::time_t start_time = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()
    );
    cout << endl;
    cout << endl;
    cout << "Test Run - begins at: " << std::ctime(&start_time) << endl;

    // Run all the list tests...
    if(  !test_list_operations()  )
    {
        cout << endl;
        cout << "Test run had one or more failed tests." << endl;
        cout << endl;
        return EXIT_FAILURE;

    } else {
        cout << endl;
        cout << "All Tests Finished Successfully - Hurrah!" << endl;
        cout << endl;
        return EXIT_SUCCESS;
    }
};


