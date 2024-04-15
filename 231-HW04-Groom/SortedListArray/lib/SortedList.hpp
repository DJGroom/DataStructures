
/*
================================================================================#=
CLASS:   SortedList
Version: Array-Based
FILE:    lib/SortedList.hpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 4
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

#pragma once
#include <string>
#include "ItemType.hpp"

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

class SortedList
{
private:
    // This is an array based implementation of the sorted list.
    // The 
    ItemType *list_elements;

    // The current number of elements in the array.
    int list_length;
    int max_length;

    // A record of the location of the last item returned
	// when iterating through the list.
    int currIterPos;

public:
    // -----------------------------------------------------+-
    // Constructors & Destructor
    // -----------------------------------------------------+-
    SortedList(int max_list_size);

    SortedList() : SortedList(200){};  // delegating constructor

    SortedList(SortedList &list_a, SortedList &list_b);

    ~SortedList();


    // -----------------------------------------------------+-
    // Observers
    // -----------------------------------------------------+-
    // Returns true iff the list is full.
    bool IsFull() const;

    // Returns the number of elements in list
    int GetLength() const;

    // Returns the given string as
    // a string representation of the content of the list.
    std::string &ToString(std::string &s) const;

    // Retrieves the item whose key matches given item's key
    //
    // If List contains an element whose key matches that of
    // the given item, then found is set to True and
    // the found item is returned.
    // Otherwise,
    // found is set to False and the given_item is returned.
    // List is always unchanged regardless.
    ItemType GetItem(ItemType given_item, bool& found);

    // Split this list on the given_item.
    // A copy of each item less than or equal to the given_item
    // is added to list_a, and
    // a copy of each item greater than the given_item
    // is added to list_b.
    // List remains unchanged.
    void SplitLists(ItemType given_item, SortedList& list_a, SortedList& list_b);
    // -----------------------------------------------------+-
    // Transformers
    // -----------------------------------------------------+-
    void MakeEmpty();
    // Function: Returns the list to the empty state.
    // Post:  List is empty.

    void PutItem(ItemType item);
    // Function: Adds item to list.
    // Pre:  List has been initialized.
    //       List is not full.
    //       Item is not already in the list.
    // Post: Item is in list.

    void DeleteItem(ItemType item);
    // Function: Deletes the element whose key matches item's key.
    // Pre:  List has been initialized.
    //       Key member of item is initialized.
    //       One and only one element in list has a key matching item's key.
    // Post: No element in list has a key matching item's key.

    // -----------------------------------------------------+-
    // Iterators
    // -----------------------------------------------------+-
    void ResetList();
    // Function: Initializes current position for an iteration through the list.
    // Pre:  List has been initialized.
    // Post: Current position is prior to list.

    ItemType GetNextItem();
    // Function: Gets the next element in list.
    // Pre:  List has been initialized and has not been changed since last call.
    //       Current position is defined.
    //       Element at current position is not last in list.
    //
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.
};

