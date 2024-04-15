
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
    int *list_elements;

    // The current number of elements in the array.
    int list_length;
    int max_length;
    int true_first;
    int true_last;
    // A record of the location of the last item returned
	// when iterating through the list.
    int currIterPos;

public:
    // -----------------------------------------------------+-
    // Constructors & Destructor
    // -----------------------------------------------------+-
    SortedList(int max_list_size);

    SortedList() : SortedList(200){};  // delegating constructor

    ~SortedList();


    // -----------------------------------------------------+-
    // Observers
    // -----------------------------------------------------+-
    //Sort simply uses quicksort but in with the class values.
    void Sort();
    //QuickSort sorts the list in a recursive manner
    void QuickSort(int values[], int first , int last);
    //Split is the funtcion that actually does all the work. 
    void Split(int values[], int first , int last, int& splitpoint);
    //Returns the max length of the list as initialized during construction
    int MaxLength();
    // Returns true iff the list is full.
    bool IsFull() const;

    // Returns the number of elements in list
    int GetLength() const;

    //Adds a item to the end of the list
    void Append(int item);
    
    // Returns the given string as
    // a string representation of the content of the list.
    std::string &ToString(std::string &s) const;

    // -----------------------------------------------------+-
    // Transformers
    // -----------------------------------------------------+-

    // -----------------------------------------------------+-
    // Iterators
    // -----------------------------------------------------+-
};

