
/*
================================================================================#=
FILE: appl/main_test.cpp

Test application for the Sorted List.
================================================================================#=
*/

#include "SortedList.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


// ---------------------------------------------------------------------+-
// TEST THE SORTED LIST
// ---------------------------------------------------------------------+-
bool test_the_sorted_list(void)
{
    using namespace std;

    string result_string = "";
    string list_string = "";
    string item_string = "";

    // -------------------------------------------------------------+-
    // The Object Under Test.
    // -------------------------------------------------------------+-
    SortedList *the_list    = NULL;
    SortedList first_list;
    SortedList second_list;

    int expected_length;
    int actual_length;

    // -------------------------------------------------------------+-
    // New List
    // -------------------------------------------------------------+-
    if(the_list != NULL) delete the_list;
    the_list = new SortedList;
    cout << "New List Complete. " << endl;

    // -------------------------------------------------------------+-
    // New List Again
    // -------------------------------------------------------------+-
    
    if(the_list != NULL) delete the_list;
    the_list = new SortedList;
    cout << "New List Complete. " << endl;
    
    // -------------------------------------------------------------+-
    // Get Length
    // -------------------------------------------------------------+-
    expected_length = 0;
    actual_length = the_list->GetLength();

    if(actual_length != expected_length) {
        result_string  = "Expected Length: " + std::to_string(expected_length);
        result_string += "  Got: " + std::to_string(actual_length);
        cout << result_string << endl;
        return false;
    }
    cout << "Get Length Complete. " << endl;

    // -------------------------------------------------------------+-
    cout << "List: " << the_list->ToString(list_string) << endl;

    // -------------------------------------------------------------+-
    // Put some items into the list.
    // -------------------------------------------------------------+-
    the_list->PutItem(ItemType(9));
    cout << "After PutItem( 9) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(12));
    cout << "After PutItem(12) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(7));
    cout << "After PutItem( 7) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(18));
    cout << "After PutItem(18) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(0));
    cout << "After PutItem( 0) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(36));
    cout << "After PutItem(36) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(42));
    cout << "After PutItem(42) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(18));
    cout << "After PutItem(18) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(7));
    cout << "After PutItem( 7) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(36));
    cout << "After PutItem(36) List: " << the_list->ToString(list_string) << endl;
    the_list->PutItem(ItemType(42));
    cout << "After PutItem(42) List: " << the_list->ToString(list_string) << endl;
    cout << "Put Items Complete. " << endl;

    // -------------------------------------------------------------+-
    // Get Length
    // -------------------------------------------------------------+-
    expected_length = 11;
    actual_length = the_list->GetLength();

    if(actual_length != expected_length) {
        result_string  = "Expected Length: " + std::to_string(expected_length);
        result_string += "  Got: " + std::to_string(actual_length);
        cout << result_string << endl;
        return false;
    }
    cout << "Get Length Complete. " << endl;

    // -------------------------------------------------------------+-
    // Delete some items from the list.
    // -------------------------------------------------------------+-
    the_list->DeleteItem(ItemType(0));
    cout << "After DeleteItem( 0) List: " << the_list->ToString(list_string) << endl;
    the_list->DeleteItem(ItemType(18));
    cout << "After DeleteItem(18) List: " << the_list->ToString(list_string) << endl;
    the_list->DeleteItem(ItemType(42));
    cout << "After DeleteItem(42) List: " << the_list->ToString(list_string) << endl;
    the_list->DeleteItem(ItemType(7));
    cout << "After DeleteItem( 7) List: " << the_list->ToString(list_string) << endl;
    the_list->DeleteItem(ItemType(96));
    cout << "After DeleteItem(96) List: " << the_list->ToString(list_string) << endl;
    cout << "Delete Items Complete. " << endl;

    // -------------------------------------------------------------+-
    // Get Length
    // -------------------------------------------------------------+-
    expected_length = 4;
    actual_length = the_list->GetLength();

    if(actual_length != expected_length) {
        result_string  = "Expected Length: " + std::to_string(expected_length);
        result_string += "  Got: " + std::to_string(actual_length);
        cout << result_string << endl;
        return false;
    }
    cout << "Get Length Complete. " << endl;

    if(the_list->IsFull()) {
        return false;
    }

    // -------------------------------------------------------------+-
    // Get Item
    // -------------------------------------------------------------+-
    bool     found = false;
    ItemType got_one;

    got_one = the_list->GetItem(ItemType(36), found);
    cout << "Got: " << got_one.ToString(item_string) << "flag: " << found << endl;

    got_one = the_list->GetItem(ItemType(77), found);
    cout << "Got: " << got_one.ToString(item_string) << "flag: " << found << endl;

    cout << "Get Item Complete. " << endl;

    // -------------------------------------------------------------+-
    // Make Empty
    // -------------------------------------------------------------+-
    the_list->MakeEmpty();
    cout << "After MakeEmpty() List: " << the_list->ToString(list_string) << endl;

    // -------------------------------------------------------------+-
    // Iterate
    // -------------------------------------------------------------+-
    the_list->PutItem(ItemType(1));
    the_list->PutItem(ItemType(2));
    the_list->PutItem(ItemType(3));
    the_list->PutItem(ItemType(4));
    the_list->PutItem(ItemType(5));

    the_list->ResetList();
    actual_length = the_list->GetLength();
    for(auto count = 0; count < actual_length; count++)
    {
        cout << "Next Item: " << the_list->GetNextItem().ToString(item_string) << endl;
    }

    // -------------------------------------------------------------+-
    // Merge
    // -------------------------------------------------------------+-
    // Create two lists to be merged.
    for(auto count=0; count <=20; count++)
    {
        if(0==count%2) {
            // Even items go into first list.
            first_list.PutItem(ItemType(count));
        } else {
            // Odd items go into second list.
            second_list.PutItem(ItemType(count));
        }
    }
    cout << "first_list: " << first_list.ToString(list_string) << endl;
    cout << "second_list: " << second_list.ToString(list_string) << endl;

    // Merge those two lists to create a new list.
    if(the_list != NULL) delete the_list;
    the_list = new SortedList(first_list, second_list);
    cout << "After Merge: " << the_list->ToString(list_string) << endl;

    // -------------------------------------------------------------+-
    // Split
    // -------------------------------------------------------------+-
    the_list->SplitLists(
        ItemType(10), first_list, second_list
    );
    cout << "After Split, first_list: "  << first_list.ToString(list_string) << endl;
    cout << "After Split, second_list: " << second_list.ToString(list_string) << endl;

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
        // Run all the list tests...
        if(!test_the_sorted_list())
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


