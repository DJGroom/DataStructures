#pragma once
#include "Sorted3DPoint.hpp"

class ArrayOfRecords
{
    protected:
        
        int length;
        int maxItems;
        int free;
        int numOfFree;
        friend std::ostream &operator<<(std::ostream& os, const ArrayOfRecords& ob);

    public:
        Nodetype *arraylist;
        int listData;
        ArrayOfRecords(int max);
        ArrayOfRecords();
        void InitializeNext(int maxItems);
        int AllocateNodeFromFreeList();
        int InsertNode(int node_after_free, int node_before_free);
        void RemoveNode(int given_node_index);
        bool IsEmpty();
        bool IsFull();
        int Size();
        int MaxSize();
        void PutItem(Sorted3Dpoint given_point);
        Sorted3Dpoint GetItem(std::string name1);
        void DeleteItem(std::string given_name1);
        ArrayOfRecords& operator+=(Sorted3Dpoint point);
        Sorted3Dpoint operator[](int number);
        
        
        ArrayOfRecords(ArrayOfRecords& original);
        std::string& ToString(std::string &s) const; 


        class Iter
        {
            private:
            ArrayOfRecords& list;
            int CurrIndex;
            public:
            Sorted3Dpoint& operator*();
            const ArrayOfRecords::Iter& operator++();
            bool operator!=(Iter& iter);
            Iter(ArrayOfRecords& arraylist, int given_index) : list(arraylist)
            {
                std::cout << "Yoooc";
                ArrayOfRecords &list = arraylist;
                int CurrIndex = given_index; 
            }
            

        };


        Iter begin();
        Iter end();
};
std::ostream &operator<<(std::ostream& os, const ArrayOfRecords& ob)      
{
    std::string sss;
    for(int i = 0; i < ob.length; i++)
    {
        os << "Points:";
        ob.arraylist[i].point.ToString(sss);
        os << sss;
    }
    return os;
};