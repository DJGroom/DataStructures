
/*
================================================================================#=
CLASS: ItemType
FILE:  appl/ItemType.hpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
================================================================================#=
*/

#pragma once
#include <string>

enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
private:
    int value;

public:
    ItemType(int given_value);
    ItemType() : ItemType(0){};  // delegating constructor

    RelationType ComparedTo(ItemType) const;  // operator overload would be much nicer

    int       GetValue() const;
    void      SetValue(int given_number);

    std::string &ToString(std::string &s) const;
};


