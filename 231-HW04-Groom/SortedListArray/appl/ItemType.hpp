
/*
================================================================================#=
CLASS: ItemType
FILE: appl/ItemType.hpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 3
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/
#pragma once
#include <string>

// -----------------------------------------------------------------------------+-
// This header file defines the data type (ItemType class) for
// the elements that we store in our Unsorted List data structure.
//
// Finally, this header also defines a RelationType enumeration to represent
// the result of comparing one ItemType with another.
// -----------------------------------------------------------------------------+-
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
private:
    // In this case, our element is just a simple integer value.
    int value;

public:
    ItemType();
    ItemType(int given_value);

    RelationType ComparedTo(ItemType) const;

    std::string &ToString(std::string &s) const;

    void Initialize(int number);
};



