
/*
================================================================================#=
CLASS:   Stack
Version: Linked-List
FILE:    lib/Stack.hpp

ACKNOWLEDGEMENTS:
All Robert Ensink's handywork.
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

// The implementation uses a Linked-List of Nodes.
struct NodeType;

class Stack
{
private:
    //This pointer points to the top node in the stack. This pointer is used as a starting point in the list when attempting to access or manipulate the list
    NodeType*  topNode;
    //StackDepth simply records the number of nodes that are in the list we have created.
    int        stackDepth;

public:
    // -----------------------------------------------------+-
    // Constructor Destructor
    // -----------------------------------------------------+-
    Stack();
    ~Stack();

    // -----------------------------------------------------+-
    // Observers
    // -----------------------------------------------------+-
    bool     IsFull()   const;
    bool     IsEmpty()  const;
    int      GetDepth() const;
    ItemType Top();

    std::string &ToString(std::string &s) const;

    // -----------------------------------------------------+-
    // Transformers
    // -----------------------------------------------------+-
    void     Push(ItemType item);
    ItemType Pop();
    void MakeEmpty();
};

