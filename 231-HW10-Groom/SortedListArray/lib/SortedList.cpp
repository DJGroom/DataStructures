// David Groom altered this code from the C++ data structure author Nell Dale and the original can be found at jbllearning.com

#include "SortedList.hpp"
#include <string.h>
#include <iostream> 
using namespace std;
int SortedList::MaxLength()
{
  return max_length;
}

SortedList::~SortedList()
{
 delete [] list_elements;
}
void SortedList::Append(int item)
{
  if(IsFull() == true)
  {
    throw std::invalid_argument("List is Full!");
  }
  else
  {
    list_elements[list_length] = item;
    list_length++;
    true_last = list_length - 1;
  }
}
void SortedList::Sort()
{
  QuickSort(list_elements, true_first, true_last);
}
void SortedList::QuickSort(int values[], int first, int last)
{
  if (first < last)
  {
    int splitPoint;
    Split(values, first, last, splitPoint);
    cout << "First After Split: " << to_string(first) << "\n";
    cout << "Last After Split: " << to_string(last) << "\n";
    cout << "splitPoint After Split: " << to_string(splitPoint) << "\n";
    // values[first]..values[splitPoint-1] <= splitVal
    // values[splitPoint] = splitVal
    // values[splitPoint+1]..values[last] > splitVal
    QuickSort(values, first, splitPoint-1);
    QuickSort(values, splitPoint+1, last);
  }
}

void SortedList::Split(int values[], int first, int last, int& splitPoint)
{
  int splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;
  first++;
  do
  {
    std::string temp;
    ToString(temp);
    std::cout << temp << "\n";
    temp.clear();

    cout << "SplitValue: " << to_string(splitVal) << "\n";
    cout << "First: " << to_string(first) << "\n";
    cout << "Last: " << to_string(last) << "\n";
    

    onCorrectSide = true;
    while (onCorrectSide)               // Move first toward last.
    {
      if (values[first] > splitVal)
      {
        onCorrectSide = false;
      }
      else
      {
        first++;
        onCorrectSide = (first <= last);
      } 
    }
      
    onCorrectSide = (first <= last);
    while (onCorrectSide)               // Move last toward first.
    {
      if ((values[last] <= splitVal) == true)
      {
        onCorrectSide = false;
      }
      else
      {
        last--;
        cout << "Yo";
        onCorrectSide = (first <= last);
      }
    }
      
    if (first < last)
    {
      //Swap(values[first].GetValue(), values[last].GetValue());
      //Essentially does the swap function. 
      int first_temp = values[first];
      values[first] = values[last];
      values[last] = first_temp;
      first++;
      last--;
    }
  } while (first <= last);
  splitPoint = last;
  //Swap(values[saveFirst], values[splitPoint]);
  //Essentially does the swap function. 
  int first_temp = values[first];
  values[first] = values[last];
  values[last] = first_temp;

  
  

}
SortedList::SortedList(int max_list_size)
{
  max_length = max_list_size;
  list_elements = new int[max_length];
  list_length = 0;
  currIterPos = -1;
  true_first = 0;
  true_last = 0;
}


bool SortedList::IsFull() const
{
  return (list_length == max_length);
}

int SortedList::GetLength() const
{
  return list_length;
}

std::string &SortedList::ToString(std::string &s) const
{
    s.clear();
    for(int i = 0; i < list_length; i++)
    {
      s += ",";
      s += to_string(list_elements[i]);
    }
    return s;
};
