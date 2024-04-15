
/*
================================================================================#=
CLASS:   Queue
Version: Circular/Floating Array
FILE:    lib/Queue.hpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 5
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

#pragma once
#include "ItemType.hpp"
#include <string>

// -----------------------------------------------------------------------------+-
// In this class, we assume that ItemType.h provides:
//   ItemType:      the data type of the object elements stored in the list
//
//   RelationType:  {LESS, GREATER, EQUAL}
//   Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item
//       GREATER, if self "comes after" item
//       EQUAL, if self and item are the same
// -----------------------------------------------------------------------------+-


class Queue
{
private:
    //QueueItems is a pointer to the array of nodes in the queue that we will be creating.
    ItemType*  queueItems;
    //QueueSize is used to determine the max number of nodes the will be initialized in the array to show the length of the queue itself. 
    int        queueSize;
    //FrontIDX is used as an index value to 'point' to the front of the queue/Least recently added node to the queue that hasn't been removed. FrontIDX actually doesn't point to the first node in line thet holds the item value, but the node before.
    //
    int        frontIdx;
    //RearIdx is used as an index value to 'point' to the most recently added item into queue.
    int        rearIdx;
    //QueueDepth is used to determine the how many items have been added to the queue. 
    int        queueDepth;
    

public:
    // -----------------------------------------------------+-
    // Constructor Destructor
    // -----------------------------------------------------+-
    Queue(int given_max_depth);
    Queue() : Queue(240){};
    ~Queue();

    // -----------------------------------------------------+-
    // Observers
    // -----------------------------------------------------+-
    bool     IsFull()   const;
    bool     IsEmpty()  const;
    int      GetDepth() const;

    std::string &ToString(std::string &s) const;

    // -----------------------------------------------------+-
    // Transformers
    // -----------------------------------------------------+-
    void      Enqueue(ItemType given_item);
    ItemType  Dequeue();
    void      MakeEmpty();
};



