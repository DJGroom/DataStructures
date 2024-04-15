
/*
================================================================================#=
CLASS:   Queue
Version: Circular/Floating Array
FILE:    lib/Queue.cpp

ACKNOWLEDGEMENTS:
Robert Enisnk is the creator of teh Tostring Method in this class, as well as the provider for most of teh infrastructor in this program.
The implementation of the code has been created by David Groom  
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 5
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

#include "Queue.hpp"
#include <string>
#include <stdexcept>


// -----------------------------------------------------+-
// Constructor
// -----------------------------------------------------+-
Queue::Queue(int given_max_depth)
//Post: Variables initialized
// Initalizing all variables required for the queue 
//Notice that our given max depth must be one larger because we require a free space in our array. Also, front and rear could be set to any array position.
{
    queueSize = given_max_depth + 1;
    frontIdx = queueSize - 1;
    rearIdx = queueSize - 1;
    queueItems = new ItemType[queueSize];
    queueDepth = 0;
};

// -----------------------------------------------------+-
// Destructor
// -----------------------------------------------------+-
Queue::~Queue()
//Pre: queueItems must be initialized
//Post: queueItems is deleted. 
{
    delete [] queueItems; 
};

// -----------------------------------------------------+-
// Observers
// -----------------------------------------------------+-
bool Queue::IsFull() const
//Pre: rearIdx, queueSize, and frontIdx must be initialized
//Post: Returns a bool value based on whether the remainder of rear + 1 out of the queueSize equals the front.
//Remember that rear + 1 is necessary because if we just did rear, this operation would be the same as IsEmpty();
{
    return ((rearIdx + 1) % queueSize == frontIdx);
};

bool Queue::IsEmpty() const
//Pre: rearIdx and frontIdx must be initialized
//Post: Returns a bool value based on whether the rear int equals the front int
{
    return (rearIdx == frontIdx);
};

int Queue::GetDepth() const
//Pre: queueDepth has been initialized
//Post: Returns Queuedepth.
{
    return queueDepth;
};

std::string &Queue::ToString(std::string &s) const
{
    std::string item_string;

    s.clear();
    s.append("[");
    s.append(std::to_string(queueDepth)+": ");

    for(auto idx = 0; idx < queueSize; idx++)
    {
        if(idx > 0) {
            s.append(", ");
        }
        if(idx == rearIdx) {
            s.append("(r");
            s.append(std::to_string(idx));
            s.append(")");
        }
        if(idx == frontIdx) {
            s.append("(f");
            s.append(std::to_string(idx));
            s.append(")");
        }
        if(frontIdx < rearIdx) {
            if(idx > frontIdx && idx <= rearIdx) {
                s.append(queueItems[idx].ToString(item_string));
            }
            else {
                s.append("---");
            }
        }
        else if(rearIdx < frontIdx){
            if(idx > frontIdx || idx <= rearIdx) {
                s.append(queueItems[idx].ToString(item_string));
            }
            else {
                s.append("---");
            }
        }
        else {
            s.append("---");
        }
    }
    s.append("]");
    return s;
}

// -----------------------------------------------------+-
// Transformers
// -----------------------------------------------------+-
void Queue::Enqueue(ItemType given_item)
//Pre: rearIdx, queueSize, queueItems, and queueDepth have been initialized, and the queue is not full. 
//Post: A new item has been added to the queue at the index value of rearidx + 1. 
//This code essentially checks to see if the queue is full, throws an exception if so. Or, increments rear, finds the remainder of rear using queuesize to ensure 
//that we don't try to access an array position that doesn't exist, then sets that array location of rear to item passed into the array. Then incremenst queuedepth.
{       
    if(IsFull())
    {
        throw std::invalid_argument("Queue Is Full. Please Dequeue.");
    }
    else
    {

        rearIdx = (rearIdx + 1) % queueSize;
        //Set the index value of rear to rear plus 1 in terms of remiander of the entire QueueSize
        queueItems[rearIdx] = given_item;
        //Set the queue item value of the index value Rear to the given item
        queueDepth++;
        //Add 1 to the depth of stack 
    }
    
};

ItemType Queue::Dequeue()
//Pre: frontIdx, queueSize, queueItems, and queueDepth have been initialized, and the queue is not empty. 
//Post: We return an item from frontIdx + 1 back to the caller. 
//This code essentially checks to see if the queue is empty, throws an exception if so. Or, increments front, finds the remainder of front using queuesize to ensure 
//that we don't try to access an array position that doesn't exist, then decrements queueDepth, and finally returns an item at the array location of front. 
{   
    if(IsEmpty())
    {
        throw std::invalid_argument("Queue is Empty. Please Enqueue.");
    }
    else
    {
        frontIdx = (frontIdx + 1) % queueSize;
        //Set the index value of rear to rear plus 1 in terming of remiander of the entire QueueSize
        queueDepth--;
        //Subtract 1 from the depth of stack 
        return queueItems[frontIdx];
        //Return the item at the frontidx index of the queue
    }
    
};

void Queue::MakeEmpty()
//Pre: frontIdx, rearIdx, queueSize, and QueueDepth have been initialized.
//Post: front and rear positions are set to what they where when the array was initialized, and the quedepth is set to zero. 
{
    frontIdx = queueSize - 1;
    rearIdx = queueSize - 1;
    //Set front and rear to the same index value to represent that it is empty. 
    queueDepth = 0;
    //Set teh depth of teh queue to zero since there in no items in the list. 
};