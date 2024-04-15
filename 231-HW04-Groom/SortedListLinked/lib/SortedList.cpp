
/*
================================================================================#=
CLASS: SortedList
FILE: lib/SortedList.cpp

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 3
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

#include "SortedList.hpp"
#include <fstream>
#include <iostream>

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
SortedList::SortedList()
{
    topNode = NULL;
    length  = 0;
    ResetList();
    currIterLocation = NULL;
};

SortedList::~SortedList()
{
    MakeEmpty();
};

SortedList::SortedList(SortedList &list_a, SortedList &list_b)
{
//This constructor works the same as the array, but the listData 
length = 0;
topNode = NULL;
int listOnelength = list_a.GetLength();
int listTwolength = list_b.GetLength();
while(length < listOnelength)
    {
    PutItem(list_a.GetNextItem());
    }
list_a.ResetList();
while(length < listOnelength + listTwolength)
    {
    PutItem(list_b.GetNextItem());
    }
list_b.ResetList();
}
// -----------------------------------------------------+-
// Observers
// -----------------------------------------------------+-
bool SortedList::IsFull() const
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


int SortedList::GetLength() const
{
    return length;
};


ItemType SortedList::GetItem(ItemType item, bool found)
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
};

// -----------------------------------------------------+-
// Transformers
// -----------------------------------------------------+-

void SortedList::SplitLists(ItemType given_item, SortedList &splitlist1, SortedList &splitlist2 )
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
};

void SortedList::MakeEmpty()
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
};

void SortedList::PutItem(ItemType item)
{
  NodeType* newNode;  	// pointer to node being inserted
  NodeType* predLoc;  	// trailing pointer
  NodeType* location; 	// traveling pointer
  bool moreToSearch;

  location = topNode;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    switch(item.ComparedTo(location->info))
    {
        case EQUAL: moreToSearch = false;
                    break;
        case GREATER: predLoc = location;
                    location = location->next;
                    moreToSearch = (location != NULL);
                    break;
        case LESS:    moreToSearch = false;
                    break;
    }
    
  }

  // Prepare node for insertion
  newNode = new NodeType;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = topNode;
    topNode = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
};
void SortedList::DeleteItem(ItemType given_item)
{
    NodeType* location = topNode;
    NodeType* tempLocation;
    while(location->next != NULL)
    {
        
        if (given_item.ComparedTo(location->info) == EQUAL)
        {
            if(location == topNode)
            {
                topNode = topNode->next;   
            }
            tempLocation = location;
            location = location->next;
            delete tempLocation;
            length--; 
        }
        if (given_item.ComparedTo(location->info) == EQUAL)
        {
            if(location == topNode)
            {
                topNode = topNode->next;   
            }
            tempLocation = location;
            location = location->next;
            delete tempLocation;
            length--; 
        }
        if (given_item.ComparedTo((location->next)->info) == EQUAL)
        {
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
};
    
    
// -----------------------------------------------------+-
// Iteration Support
// -----------------------------------------------------+-
void SortedList::ResetList()
{
    currIterLocation = NULL;
};

ItemType SortedList::GetNextItem()
{
    ItemType item;
    if(currIterLocation == NULL)
        currIterLocation = topNode;
    else
        currIterLocation = currIterLocation->next;

    item = currIterLocation->info;
    return item;
};
std::string &SortedList::ToString(std::string &s) const
{
    if(topNode == NULL)  
    {
        return s;
    }
    else
    {
        NodeType *tempi = new NodeType();
        tempi = topNode;
        s.clear();
        while(tempi != NULL) 
        {
            tempi->info.ToString(s);
            tempi = tempi->next;
        }
        return s;
    }
}