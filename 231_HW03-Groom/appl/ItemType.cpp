
/*
================================================================================#=
CLASS: ItemType
FILE: appl/ItemType.cpp

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

// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>

// Constructors
ItemType::ItemType()
{ 
    value = 0;
};

ItemType::ItemType(int given_value)
{ 
    value = given_value;
};


// Comparison
RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
};

// (Re)Initialize the value.
void ItemType::Initialize(int number) 
{
    value = number;
};

// Returns a string representation of this item.
std::string &ItemType::RToString(std::string &s) const
{
    s.clear();
    s.append("[:");
    s.append(std::to_string(value));
    s.append(":]");
    return s;
}

