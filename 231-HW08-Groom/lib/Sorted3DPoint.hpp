
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
#include <vector>
#include <sstream>
#include <iostream>
#include <list>
#include <iomanip>

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
static const int NUL = -1;

class Sorted3Dpoint
{
    protected:
        
        
        int CompareToMyself(const Sorted3Dpoint other)
        {
            //If the caller's object is bigger than the object passed through teh parameter,
            //Return 1, if smaller, return -1, and if the objects are equal than return 
            if(x > other.x)
            {
                return 1;
            }
            else if( x < other.x)
            {
                return -1;
            }
            if(y > other.y)
            {
                return 1;
            }
            else if( y < other.y)
            {
                return -1;
            }
            if(z > other.z)
            {
                return 1;
            }
            else if( z < other.z)
            {
                return -1;
            }
            else
            {
                return 0;
            }

        }
        
    public:
        std::string name;
        double x, y, z;
        friend std::ostream &operator<<(std::ostream& os, const Sorted3Dpoint& ob);
        Sorted3Dpoint(std::string iname, double ix, double iy, double iz);
        Sorted3Dpoint();
        void SetName(std::string iname);
        std::string GetName();
        void SetXYZ(double ix, double iy, double iz);
        std::vector<double> GetXYZ();
        std::string& ToString(std::string &s) const;
        bool operator==(Sorted3Dpoint const &ob2);
        bool operator>(Sorted3Dpoint const &ob2);
        bool operator>=(Sorted3Dpoint const &ob2);
        bool operator<(Sorted3Dpoint const &ob2);
        bool operator<=(Sorted3Dpoint const &ob2);
        


        
};
 struct Nodetype
{
    int next;
    Sorted3Dpoint point;
};       




/*




*/

        