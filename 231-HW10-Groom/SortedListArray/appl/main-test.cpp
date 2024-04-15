
/*
================================================================================#=
FILE: appl/main-test.cpp

Test application for the Sorted List of Integers.
This app tests both the array-based and linked-list versions.

SPDX-License-Identifier: MIT-0
================================================================================#=
*/

#include "SortedList.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <ios>     // boolalpha

using namespace std;


bool smoke_test_array(void)
{
    // ---------------------------------------------------------------------+-
    // Basic test of all methods.
    // Includes programmatic validation of expected results.
    // ---------------------------------------------------------------------+-
    std::string list_string;

    cout << std::boolalpha;

    // -----------------------------------------------------+-
    cout << endl << endl;
    cout << "Construction..." << endl;
    SortedList list_under_test(64);

    //cout << "list: " << list_under_test << endl;
    //cout << "list: " << list_under_test.ToStringReversed(list_string) << "(reversed)" << endl;
    //cout << "List is Empty?  " << list_under_test.IsEmpty()   << endl;
    //cout << "List is Full?   " << list_under_test.IsFull()    << endl;
    //cout << "Length:         " << list_under_test.Length()    << endl;
    //cout << "MaxLength:      " << list_under_test.MaxLength() << endl;

    // -----------------------------------------------------+-
    cout << endl;
    cout << "Adding some values..." << endl;
    list_under_test.Append(1);
    list_under_test.Append(2);
    list_under_test.Append(3);
    list_under_test.Append(4);
    list_under_test.Append(5);
    list_under_test.Append(6);

    list_under_test.ToString(list_string);
    cout << list_string; 
    /*
    list_under_test += (4);
    list_under_test += (5);
    list_under_test += (5);
    list_under_test += (6);
    list_under_test += (6);
    list_under_test += (6);
    
    cout << "list: " << list_under_test << endl;
    cout << "list: " << list_under_test.ToStringReversed(list_string) << "(reversed)" << endl;
    cout << "List is Empty?  " << list_under_test.IsEmpty()   << endl;
    cout << "List is Full?   " << list_under_test.IsFull()    << endl;
    cout << "Length:         " << list_under_test.Length()    << endl;
    */
    // -----------------------------------------------------+-
    /*
    cout << endl;
    cout << "Deleting 2..." << endl;
    list_under_test.Delete(2);
    cout << "list: " << list_under_test << endl;

    cout << endl;
    cout << "Deleting 3,4,5..." << endl;
    list_under_test.Delete(3);
    list_under_test.Delete(4);
    list_under_test.Delete(5);
    cout << "list: " << list_under_test << endl;

    cout << endl;
    cout << "Deleting all 6s..." << endl;
    list_under_test -= (6);
    list_under_test -= (6);
    list_under_test -= (6);
    list_under_test -= (6);
    list_under_test -= (6);
    cout << "list: " << list_under_test << endl;

    cout << endl;
    cout << "Making Empty..." << endl;
    list_under_test.MakeEmpty();
    cout << "list: " << list_under_test << endl;

    cout << endl;
    cout << "Sorted List of Random Values..." << endl;
    for(auto count = 1; count <= 18; count++)
    {
        int rand_value = rand() % 2048;
        list_under_test.Append(rand_value);
    }
    cout << "list: " << list_under_test << endl;
    list_under_test.Sort();
    cout << "list: " << list_under_test << endl;
    */
    return true;
};


// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main()
{
    // Get the current time and
    // Print a small "banner" to announce that we are starting the test;
    std::time_t start_time = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()
    );
    cout << endl;
    cout << endl;
    cout << "Test Run - begins at: " << std::ctime(&start_time) << endl;

    srand(time(NULL));

    bool result = true;
    // Stop testing after the first failure.

    try
    {
        // -----------------------------------------------------+-
        // Smoke Tests
        // -----------------------------------------------------+-
        if(result) {
            cout << endl << endl;
            cout << "Smoke Test: Array - Starting..." << endl;
            result = smoke_test_array();
            cout << endl;
            cout << "Smoke Test: Array - Complete." << endl;
        }

        //// if(result) {
            //// cout << endl << endl;
            //// cout << "Smoke Test: List - Starting..." << endl;
            //// result = smoke_test_list();
            //// cout << "Smoke Test: List - Complete." << endl;
        //// }
    }
    catch(const std::exception& ex) {
        cout << "Test throws unexpected exception: " << ex.what() << endl;
        cout << endl;
        return EXIT_FAILURE;
    }

    cout << endl << endl;
    string version_string = "test version: Wednesday, Nov 29";

    if(result)
    {
        cout << "No Test Crashed - Phew! (" << version_string << ")" << endl;
        cout << endl;
        return EXIT_SUCCESS;

    } else {
        cout << "Test run had one or more FAILED tests. (" << version_string << ")" << endl;
        cout << endl;
        return EXIT_FAILURE;
    }
};


#if 0

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


bool smoke_test_list(void)
// Basic test of all list methods.
// Some automatic validation of expected results.
{
    using namespace std;

    // -------------------------------------------------------------+-
    // Construct a SortedPointList
    // -------------------------------------------------------------+-
    SortedPointList the_list(12);


    // -------------------------------------------------------------+-
    // Put some points into the list.
    // -------------------------------------------------------------+-
    Point3D point_d("D", 4.0, 2.0, 3.0);
    the_list.PutItem(point_d);

    Point3D point_e("E", 5.0, 2.0, 3.0);
    the_list.PutItem(point_e);

    Point3D point_f("F", 6.6, 2.6, 3.6);
    the_list.PutItem(point_f);

    Point3D point_a("A", 1.1, 2.1, 3.1);
    the_list.PutItem(point_a);

    Point3D point_b("B", 2.0, 2.0, 3.0);
    the_list.PutItem(point_b);

    Point3D point_d2("D", 4.1, 2.2, 3.3);   // another D
    the_list.PutItem(point_d2);

    Point3D point_c("C", 3.0, 2.0, 3.0);
    the_list.PutItem(point_c);

    cout << endl << endl;
    cout << "The list after putting some points: " << endl << the_list << endl;
    cout << "List is Empty? " << the_list.IsEmpty()   << endl;
    cout << "List is Full?  " << the_list.IsFull()    << endl;
    cout << "Length:        " << the_list.Length()    << endl;
    cout << "MaxLength:     " << the_list.MaxLength() << endl;

    // -------------------------------------------------------------+-
    // Get a point from the list.
    // -------------------------------------------------------------+-
    const Point3D *acquired_point;

    acquired_point = the_list.GetItem("F");
    cout << endl << endl;
    if(acquired_point == NULL)
        cout << "Got Point 'F': Not Found" << endl;
    else
        cout << "Got Point 'F': " << *acquired_point << endl;

    acquired_point = the_list.GetItem("Foo");
    cout << endl << endl;
    if(acquired_point == NULL)
        cout << "Got Point 'Foo': Not Found" << endl;
    else
        cout << "Got Point 'F': " << *acquired_point << endl;

    // -------------------------------------------------------------+-
    // Remove all the points from the list.
    // -------------------------------------------------------------+-
    cout << endl << endl;
    cout << "Before any deletes: " << endl << the_list << endl;
    the_list.DeleteItem("A");
    cout << "After Delete Point A: " << endl << the_list << endl;

    the_list.DeleteItem("D");
    cout << "After Delete Point D: " << endl << the_list << endl;

    the_list.DeleteItem("B");
    cout << "After Delete Point B: " << endl << the_list << endl;

    the_list.DeleteItem("C");
    cout << "After Delete Point C: " << endl << the_list << endl;

    the_list.DeleteItem("E");
    cout << "After Delete Point E: " << endl << the_list << endl;

    the_list.DeleteItem("F");
    cout << "After Delete Point F: " << endl << the_list << endl;

    cout << "The list after deleting all points: " << endl << the_list << endl;
    cout << "List is Empty? " << the_list.IsEmpty()   << endl;
    cout << "List is Full?  " << the_list.IsFull()    << endl;
    cout << "Length:        " << the_list.Length()    << endl;

    // -------------------------------------------------------------+-
    // Add some points, make a copy then make empty.
    // -------------------------------------------------------------+-
    cout << endl << endl;
    the_list += point_f;
    the_list += point_d;
    the_list += point_e;
    the_list += point_a;
    the_list += point_c;
    the_list += point_b;
    cout << "The list after adding some more points: " << endl << the_list << endl;
    cout << "List is Empty? " << the_list.IsEmpty()   << endl;
    cout << "List is Full?  " << the_list.IsFull()    << endl;
    cout << "Length:        " << the_list.Length()    << endl;

    SortedPointList the_copy_list = the_list;

    the_list.MakeEmpty();
    cout << "The list after make empty: " << endl << the_list << endl;
    cout << "List is Empty? " << the_list.IsEmpty()   << endl;
    cout << "List is Full?  " << the_list.IsFull()    << endl;
    cout << "Length:        " << the_list.Length()    << endl;

    cout << endl << endl;
    cout << "The copy list: " << endl << the_copy_list << endl;
    cout << "List is Empty? " << the_list.IsEmpty()   << endl;
    cout << "List is Full?  " << the_list.IsFull()    << endl;
    cout << "Length:        " << the_list.Length()    << endl;

    // -------------------------------------------------------------+-
    // Iterate through copy.
    // -------------------------------------------------------------+-
    cout << endl << endl;
    for(Point3D next_pt : the_copy_list)
    {
        cout << "Iteration: next_pt: " << next_pt << endl;
    }

    // -------------------------------------------------------------+-
    // Iterate through copy again using [] operator.
    // -------------------------------------------------------------+-
    cout << endl << endl;
    for(auto index = 0; index < the_copy_list.Length(); index++)
    {
        cout << "Iteration: next_pt: " << the_copy_list[index] << endl;
    }

    return true;
};

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#endif

