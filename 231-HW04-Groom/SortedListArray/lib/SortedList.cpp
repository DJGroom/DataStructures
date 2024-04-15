// David Groom altered this code from the C++ data structure author Nell Dale and the original can be found at jbllearning.com

#include "SortedList.hpp"
SortedList::SortedList(int max_list_size)
{
  max_length = max_list_size;
  list_elements = new ItemType[max_length];
  list_length = 0;
  currIterPos = -1;
}

SortedList::SortedList(SortedList &list_a, SortedList &list_b)
{
max_length = 200;
list_elements = new ItemType[max_length];
currIterPos = 0;

//mereg
list_length = 0;
int listOnelength = list_a.GetLength();
int listTwolength = list_b.GetLength();
    while(list_length < listOnelength)
    {
    PutItem(list_a.GetNextItem());
    }
list_a.ResetList();
    while(list_length < listOnelength + listTwolength)
    {
    PutItem(list_b.GetNextItem());
    }
list_b.ResetList();
}

SortedList::~SortedList()
{
  delete[] list_elements;
}

void SortedList::MakeEmpty() 
{
  list_length = 0;
} 

bool SortedList::IsFull() const
{
  return (list_length == max_length);
}

int SortedList::GetLength() const
{
  return list_length;
}

ItemType SortedList::GetItem(ItemType item, bool& found) 
{
  int midPoint;
  int first = 0;
  int last = list_length - 1;

  bool moreToSearch = first <= last;
  found = false;
  while (moreToSearch && !found) 
  {
    midPoint = ( first + last) / 2;
    switch (item.ComparedTo(list_elements[midPoint])) 
    {
      case LESS    : last = midPoint - 1;
                     moreToSearch = first <= last;
                     break;
      case GREATER : first = midPoint + 1;
                     moreToSearch = first <= last;
                     break;
      case EQUAL   : found = true;
                     item = list_elements[midPoint];
                     return item;
    }
  }
  //Exception Here
}

void SortedList::SplitLists(ItemType given_item, SortedList& list_a, SortedList& list_b)
{
  return;
}
    

void SortedList::DeleteItem(ItemType item) 
{
  int location = 0;
  while(location < list_length)
  //While there is more in teh list to compare to
  {
    if(item.ComparedTo(list_elements[location]) == EQUAL)
    //If the given item's value is equal to the array's value at location's index, do the following
    {
      for (int index = location + 1; index < list_length; index++)
      //For all array indexes after the given item's found index-
      {
        list_elements[index - 1] = list_elements[index];
        //Substract one from all index values so that 
      }
      list_length--;
      //Record the fact that we have now shortened the length of the list
    }
    else
    {
      location++;
      //Keep looking
    }
  }
}
void SortedList::PutItem(ItemType item) 
{
  bool moreToSearch;
  int location = 0;

  moreToSearch = (location < list_length);
  while (moreToSearch) 
  {
    switch (item.ComparedTo(list_elements[location])) 
    {
      case LESS    : moreToSearch = false;
                     break;
      case GREATER : location++;
                     moreToSearch = (location < list_length);
                     break;
      case EQUAL   : moreToSearch = false;
                      break;               
    } 
  } 
  for (int index = list_length; index > location; index--)
    list_elements[index] = list_elements[index - 1];
  list_elements[location] = item;
  list_length++;
}

void SortedList::ResetList()
// Post: currentPos has been initialized.
{
  currIterPos = -1;
}

ItemType SortedList::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
  currIterPos++;
  return list_elements[currIterPos];
}
std::string &SortedList::ToString(std::string &s) const
{
    s.clear();
    for(int i = 0; i < list_length; i++)
    {
      s += ",";
      list_elements[i].ToString(s);
    }
    return s;
};
