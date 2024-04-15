
/*
================================================================================#=
CLASS: ItemType
FILE:  appl/ItemType.cpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
================================================================================#=
*/

#include "ItemType.hpp"

#include <fstream>
#include <iostream>

// Constructor
ItemType::ItemType(int given_value)
{
    value = given_value;
};


// Comparison
RelationType ItemType::ComparedTo(ItemType other_item) const
{
    if (value < other_item.value)
        return LESS;

    else if (value > other_item.value)
        return GREATER;

    else
        return EQUAL;
};

// Setter & Getter
int ItemType::GetValue() const
{
    return value;
};

void ItemType::SetValue(int given_number)
{
    value = given_number;
    return;
};

// ToString
std::string& ItemType::ToString(std::string& s) const
{
    s.clear();
    s.append("{");
    s.append(std::to_string(value));
    s.append("}");
    return s;
}

