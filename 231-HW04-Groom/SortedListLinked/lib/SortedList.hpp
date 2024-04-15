
/*
================================================================================#=
CLASS: SortedList
FILE: lib/SortedList.hpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 3
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

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

struct NodeType;

class SortedList
{
private:
    // Use a linked list for storing the nodes in the list.
    // This pointer identifies the "top" node, i.e., the one most recently allocated. The purpose of TopNode is to return the a pointer to the starting place of the list.

    NodeType*  topNode;

    // A pointer to the location of the next item to be returned when iterating through the list.
    //  Used as a point to determine which node the caller is pointing to when iterating through the list.
    NodeType*  currIterLocation;

    // Length is used to describe the current number of elements in the array. This int is used as a condition variable for iterating through the list in many of the functions.
    int        length;

public:
    // -----------------------------------------------------+-
    // Constructor & Destructor
    // -----------------------------------------------------+-
    SortedList();
    SortedList(SortedList &list_a, SortedList &list_b);
    ~SortedList();
    

    // -----------------------------------------------------+-
    // Observers
    // -----------------------------------------------------+-
    bool IsFull() const;
    // Function:  Determines whether list is full.
    // Pre:  List has been initialized.
    // Post: Returns true iff the list is full.
    //       List is unchanged.

    int GetLength() const;
    // Function: Determines the number of elements in list.
    // Post: Returns the number of elements in list
    //       List is unchanged.

    ItemType GetItem(ItemType item, bool found);
    // Retrieves the element whose key matches given item's key (if present).
    //
    // Pre:  List has been initialized.
    //       Key member of the given item is initialized.
    //
    // Post: If List contains an element whose key matches that of
    //       the given item, then found is set to True and
    //       a copy of the found item is returned.
    //       Otherwise, found is set to False and the given_item is returned.
    //
    //       List is always unchanged regardless.
    void SplitLists(ItemType given_item, SortedList &splitlist1, SortedList &splitlist2);
    //Takes a list and splis teh contents of said list into two spereate lists.
    // PRE: All lists have been initalized and so has the given object item 
    //      
    // POST: Will take nodes from the first list and distribute those node to each list.
    //       If the node value is less than the given value it will be in the first list, else it will be in the sceond list. 
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
    //       All elements that match teh given item are deleted.
    //       Will not delete anything if the item doesn't match. 
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
    std::string &ToString(std::string &s) const;
};
