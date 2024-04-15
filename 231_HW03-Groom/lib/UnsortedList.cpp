
/*
================================================================================#=
CLASS: UnsortedList
FILE: lib/UnsortedList.cpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 3
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

#include "UnsortedList.hpp"


// -----------------------------------------------------+-
// NodeType
// -----------------------------------------------------+-
struct NodeType
{
    ItemType   info;
    NodeType*  next;
};

// -----------------------------------------------------+-
// Constructor & Destructor
// -----------------------------------------------------+-
UnsortedList::UnsortedList()
{
    topNode = NULL;
    length  = 0;
    ResetList();
};

UnsortedList::~UnsortedList()
{
    MakeEmpty();
};

// -----------------------------------------------------+-
// Observers
// -----------------------------------------------------+-
bool UnsortedList::IsFull() const
{
    // Returns true IFF there is no room for another node on the free store.
    try
    {
        NodeType* location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
};


int UnsortedList::GetLength() const
{
    return length;
};


ItemType UnsortedList::GetItem(ItemType& item, bool& found)
{
    bool       moreToSearch;
    NodeType*  location = topNode;
    found = false;
    moreToSearch = (location != NULL);

    while(moreToSearch && !found)
    {
        switch (item.ComparedTo(location->info))
        {
        case LESS:
        case GREATER:
            location = location->next;
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
        moreToSearch = (location != NULL);
    }
    return item;
}

// -----------------------------------------------------+-
// Transformers
// -----------------------------------------------------+-

void UnsortedList::SplitList(UnsortedList &splitlist1, UnsortedList &splitlist2, ItemType given_item)
{
    NodeType* temppoint;
    splitlist1.MakeEmpty();
    splitlist2.MakeEmpty();
    while(topNode != NULL)
    {
        switch(topNode->info.ComparedTo(given_item))
        {
        case LESS:
            splitlist1.PutItem(topNode->info);
            topNode = topNode->next;
            break;
        case GREATER:
            splitlist2.PutItem(topNode->info);
            topNode = topNode->next;
            break;
        case EQUAL:
            splitlist1.PutItem(topNode->info);
            topNode = topNode->next;
            break;
        }
    }
}

void UnsortedList::MakeEmpty()
{
    NodeType* tempPtr;

    while(topNode != NULL)
    {
      tempPtr = topNode;
      topNode = topNode->next;
      delete tempPtr;
    }
    length = 0;
    ResetList();
}

void UnsortedList::PutItem(ItemType given_item)
{
    NodeType* location = new NodeType;  // If 'full' will throw exception
    location->info = given_item;
    location->next = topNode;
    topNode = location;
    length++;
}

void UnsortedList::DeleteItem(ItemType given_item)
{
    NodeType* location = topNode;
    NodeType* tempLocation;
    while(location->next != NULL)
    {
        
        if (given_item.ComparedTo((location->next)->info) == EQUAL)
        {
            if(location == topNode)
            {
                tempLocation = location;
                topNode = topNode->next; 
            }
            tempLocation = location->next;
            location->next = (location->next)->next;
            delete tempLocation;
            length--; 
        }
        else
        {
        location = location->next;  
        }  
    }
    ResetList();
    
    // Note: item must be found in the list?
    /*NodeType* location = topNode;
    NodeType* tempLocation;

    // Locate node to be deleted.
    if (given_item.ComparedTo(topNode->info) == EQUAL)
    {
        tempLocation = location;
        topNode = topNode->next;  // Delete first node.
    }
    else
    {
        while(given_item.ComparedTo((location->next)->info) != EQUAL)
        {
            location = location->next;
        }

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;*/
}
    
    
// -----------------------------------------------------+-
// Iteration Support
// -----------------------------------------------------+-
void UnsortedList::ResetList()
{
    currIterLocation = NULL;
};

ItemType UnsortedList::GetNextItem()
{
    ItemType item;
    if(currIterLocation == NULL)
        currIterLocation = topNode;
    else
        currIterLocation = currIterLocation->next;

    item = currIterLocation->info;
    return item;
};

