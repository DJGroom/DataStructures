
/*
================================================================================#=
FILE: appl/main-test.cpp
Provided and mostly done by Robert Ensink, completed by David Groom
Test application for the Queue class.
================================================================================#=
*/

#include "Queue.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


// ---------------------------------------------------------------------+-
// TEST THE QUEUE
// ---------------------------------------------------------------------+-
bool test_the_queue(void)
{
    using namespace std;

    string result_string  = "";
    string queue_string   = "";
    string item_string    = "";

    // -------------------------------------------------------------+-
    // The Object Under Test.
    // -------------------------------------------------------------+-
    Queue   *the_queue    = NULL;
    ItemType some_item;

    int expected_depth;
    int actual_depth;

    // -------------------------------------------------------------+-
    // New Queue
    // -------------------------------------------------------------+-
    if(the_queue != NULL) delete the_queue;
    the_queue = new Queue(24);
    cout << "New Queue Complete. " << endl;

    // -------------------------------------------------------------+-
    // New Queue Again
    // -------------------------------------------------------------+-
    if(the_queue != NULL) delete the_queue;
    the_queue = new Queue(12);
    cout << "New Queue Complete. " << endl;

    // -------------------------------------------------------------+-
    // Get Depth
    // -------------------------------------------------------------+-
    expected_depth = 0;
    actual_depth = the_queue->GetDepth();

    if(actual_depth != expected_depth) {
        result_string  = "Expected Depth: " + std::to_string(expected_depth);
        result_string += "  Got: " + std::to_string(actual_depth);
        cout << result_string << endl;
        return false;
    }
    cout << "Get Depth Complete. " << endl;

    // -------------------------------------------------------------+-
    // Print Empty Queue
    // -------------------------------------------------------------+-
    cout << "Queue: " << the_queue->ToString(queue_string) << endl;

    // -------------------------------------------------------------+-
    // Put some items onto the queue.
    // -------------------------------------------------------------+-
    //First trying to add 7 items to the queue then printing the queue. Then adding more items than allowed, trying to get an error. 
    try
    {
        the_queue->Enqueue(ItemType(2));
        the_queue->Enqueue(ItemType(1));
        the_queue->Enqueue(ItemType(8));
        the_queue->Enqueue(ItemType(9));
        the_queue->Enqueue(ItemType(11));
        the_queue->Enqueue(ItemType(4));
        the_queue->Enqueue(ItemType(5));
        cout << "Queue after enqueueing seven items: " << the_queue->ToString(queue_string) << endl;
        cout << "Trying to Enqueue more items than can fit in the queue:" << endl;
        the_queue->Enqueue(ItemType(0));
        the_queue->Enqueue(ItemType(2));
        the_queue->Enqueue(ItemType(7));
        the_queue->Enqueue(ItemType(6));
        the_queue->Enqueue(ItemType(10));
        //Should not enqueue the following but provide the error provided in the method's implementation.
        the_queue->Enqueue(ItemType(101));
        the_queue->Enqueue(ItemType(1011));
         
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    
    cout << "Queue: " << the_queue->ToString(queue_string) << endl;
    // -------------------------------------------------------------+-
    // Remove some items from the queue.
    // -------------------------------------------------------------+-
    //First trying to remove 7 items then printing the queue. Then removing more items than allowed, trying to get an error. 
    try
    {
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        cout << "Queue after dequeueing seven items: " << the_queue->ToString(queue_string) << endl;
        cout << "Trying to Dequeue more items than can be removed in the queue:" << endl;
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        the_queue->Dequeue();
        //Should not dequeue the following but provide the error provided in the method's implementation.
        the_queue->Dequeue();
         
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    cout << "Queue: " << the_queue->ToString(queue_string) << endl;
    


    // -------------------------------------------------------------+-
    // Make Empty
    // -------------------------------------------------------------+-
    //Testing Make Empty by enqueueing items and then implementing MakeEmpty.
    the_queue->Enqueue(ItemType(7));
    the_queue->Enqueue(ItemType(6));
    the_queue->Enqueue(ItemType(10));
    cout << "Queue before MakeEmpty(): " << the_queue->ToString(queue_string) << endl;
    the_queue->MakeEmpty();
    cout << "After MakeEmpty() Queue: " << the_queue->ToString(queue_string) << endl;

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
        if(!test_the_queue())
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


