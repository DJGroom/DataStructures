#include "SortedListArray.hpp"


ArrayOfRecords::ArrayOfRecords(int max)
{

    length = 0;

    maxItems = max;

    arraylist = new Nodetype[max];
    
    free = 0;
   
    numOfFree = max;
   
    listData = NUL;
    
    InitializeNext(max);
}

ArrayOfRecords::ArrayOfRecords()
{
    length = 0;
    maxItems = 50;
    arraylist = new Nodetype[50];
    free = 0;
    numOfFree = maxItems;
    listData = NUL;
    InitializeNext(maxItems);
}
void ArrayOfRecords::InitializeNext(int maxItems)
{
    for (int index = 0; index < maxItems - 1; index++)
    {
        arraylist[index].next = index + 1;
        /*
        std::cout << std::endl << "Node->" ;

        std::string why1 = std::to_string(index);
        std::cout << why1;
        
        std::cout << "Next->" ;

        std::string why = std::to_string(arraylist[index].next);
        std::cout << why;
        */
    }  
    arraylist[maxItems - 1].next = NUL;

}
int ArrayOfRecords::AllocateNodeFromFreeList()
{
    
    
    int floating_free = free;
    free = arraylist[free].next;

    numOfFree--;
    return floating_free;

}
int ArrayOfRecords::InsertNode(int node_after_free, int node_before_free)
//This function will insert the accolocated free node from the Allocate function after the given node index
{   
    int floating_free = AllocateNodeFromFreeList();
    
    /*if(node_after_free == NUL)
    {
        floating_free = node_before_free;
        arraylist[floating_free].next = NUL; 
        return floating_free;
    }*/
    if(node_after_free == listData)
    {
        
        arraylist[floating_free].next = listData; 
        listData = floating_free;
    }
    else
    {
        arraylist[node_before_free].next = floating_free;
        arraylist[floating_free].next = node_after_free;
    }

    return floating_free;
}

void ArrayOfRecords::RemoveNode(int given_node_index)
{ 
    int temp_free = free;
    free = given_node_index;
    arraylist[free].next = temp_free;
    numOfFree++;
}
bool ArrayOfRecords::IsEmpty()
{
    if(listData == NUL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ArrayOfRecords::IsFull()
{
    if(free == NUL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int ArrayOfRecords::Size()
{
    return length;
}
int ArrayOfRecords::MaxSize()
{
    return maxItems;
}
void ArrayOfRecords::PutItem(Sorted3Dpoint given_point) 
//List goes biggest from smallest starting from list data
{
    if(free == NUL)
    {
        throw std::invalid_argument("No More Room!");
        return;
    }

    int temp_listdata = listData;
    //trailing_temp will only be used if 
    int trailing_temp_listdata = NUL;

    if(listData == NUL)
    {
    int the = AllocateNodeFromFreeList();
    listData = 0;
    arraylist[listData].next = NUL;
    std::cout << "Creating List: " << std::endl;
    length++;
    arraylist[listData].point = given_point;
    return;

    }
    
    for(int i = 0; i < length; i++)
    {
            
        if(arraylist[temp_listdata].point <= given_point)
        {
            int node_to_be_put_in = InsertNode(temp_listdata, trailing_temp_listdata);
            arraylist[node_to_be_put_in].point = given_point;
            length++;
            std::cout << "Inserting in middle of list" << std::endl;
            return;
        }
        trailing_temp_listdata = temp_listdata;
        temp_listdata = arraylist[temp_listdata].next;
        
    }
    std::cout << "Adding to the end of the list" << std::endl;
    int node_to_be_put_in = InsertNode(temp_listdata, trailing_temp_listdata);
    arraylist[node_to_be_put_in].point = given_point;
    length++;
    
    
}
Sorted3Dpoint ArrayOfRecords::GetItem(std::string name1)
{
    std::string temp;
    int iteration = 0;
    while(name1 != temp || listData > iteration)
    {
        temp = arraylist[iteration].point.GetName();
        iteration++;
    }
    if(name1 != temp || listData > iteration)
    {
        throw std::invalid_argument("Item was not found!");
    }
    return arraylist[iteration - 1].point;
}
void ArrayOfRecords::DeleteItem(std::string given_name1)
{
    int next_listdata = arraylist[listData].next;
    int temp_listdata = listData;


    if(listData == NUL)
    {
        throw std::invalid_argument("No list to delete from");
    }
    
    if(arraylist[temp_listdata].point.GetName() == given_name1)
    {
        if(arraylist[listData].next == NUL)
        {

            //Only one item in the list so we set listData to Nul
            RemoveNode(listData);
            listData = NUL;
            length--;
            return;
        }
        else
        {
            //We are deleting the first_item in the list, so we must make a new first
            int actual_temp = listData;
            
            listData = arraylist[listData].next;
            RemoveNode(actual_temp);
            
            length--;
            return;
        }
        
    }
    
    for(int i = 1; i < length; i++)
    {
        
        if(arraylist[next_listdata].point.GetName() == given_name1)
        {
            
            
            /*if(arraylist[next_listdata].next == NUL)
            {
                std::cout << "Removing node from free list but there is only the last remaining node. ";
                RemoveNode(next_listdata);
                arraylist[temp_listdata].next = NUL;
                length--;
                return;
            } */
            arraylist[temp_listdata].next = arraylist[next_listdata].next;
            RemoveNode(next_listdata);
            length--;
            
            return;
        }
        next_listdata = arraylist[next_listdata].next;
        temp_listdata = arraylist[temp_listdata].next;
        
    }
    //We gotten to the end of teh list at this point. 
    throw std::invalid_argument("No list to delete from");

}

ArrayOfRecords::ArrayOfRecords(ArrayOfRecords& original)
{
    
    if(original.length < original.maxItems/2)
    {
        maxItems = original.maxItems;
    }
    else
    {
        maxItems = original.maxItems * 2;
    }
    length = 0;
    arraylist = new Nodetype[maxItems];
    free = 0;
    numOfFree = maxItems;
    listData = NUL;
    InitializeNext(maxItems);
    //I need to initialize the rest of the nexts for the copy here.
    //Copy Point data
    int next_listdata = original.listData;
    for(int i = 0; i < original.length; i++)
    {  

        PutItem(original.arraylist[next_listdata].point);
        /*
        std::cout << std::endl << std::to_string(i) << std::endl;
        std::string output;
        this->ToString(output);
        std::cout << output;
        */
        next_listdata = original.arraylist[next_listdata].next;
    }
}
std::string& ArrayOfRecords::ToString(std::string &s) const
{
    s.clear();
    std::stringstream ss;
    ss << std::endl << std::endl;
    ss << "ToString..." << std::endl;
    ss << "maxItems: " << maxItems << std::endl;
    ss << "free:     " << free << std::endl;
    ss << "listData: " << listData << std::endl;
    ss << "length: " << length << std::endl;

    for(int idx = 0; idx < maxItems; idx++)
    {
        ss << "idx: " << idx;
        ss << "  Point Name: " << arraylist[idx].point.GetName() << "  Values:  ";
        ss << "X: " << arraylist[idx].point.x << "Y: " << arraylist[idx].point.y <<  "Z: " << arraylist[idx].point.z;
        ss << "  Next: " << arraylist[idx].next << std::endl;
    }
    s.append(ss.str());
    return s;
};
ArrayOfRecords& ArrayOfRecords::operator+=(Sorted3Dpoint point)
{
    this->PutItem(point);
    return *this;
}
Sorted3Dpoint ArrayOfRecords::operator[](int number)
{
    return arraylist[number].point;
}
Sorted3Dpoint& ArrayOfRecords::Iter::operator*()
{
    std::cout << "Yood";
    return list.arraylist[CurrIndex].point;
}
const ArrayOfRecords::Iter& ArrayOfRecords::Iter::operator++()
{
    std::cout << "Yoopp";
    CurrIndex = list.arraylist[CurrIndex].next;
    std::cout << "Yoon";
    return *this;
}
bool ArrayOfRecords::Iter::operator!=(Iter& iter)
{
    std::cout << "Yooq";
    return CurrIndex != iter.CurrIndex;
}
ArrayOfRecords::Iter ArrayOfRecords::begin()
{
    
    int temp_list = listData;
    Iter iter(*this, temp_list);
    std::cout << "Yoob";
    return iter;
}
ArrayOfRecords::Iter ArrayOfRecords::end()
{
    int temp_list = listData;
    for(int i = 0; i < length - 1; i++)
    {
        temp_list = arraylist[temp_list].next;
    }
    Iter iter(*this, temp_list);
    std::cout << "Yooe";
    return iter;
}


