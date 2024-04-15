
/*
================================================================================#=
CLASS:   Stack
Version: Linked-List
FILE:    lib/Stack.cpp

All code in Stack.cpp and is coded by David Groom with the exception of the ToString Method which was created by Robert Ensink. 
This code was inspired by the orginal code found below. 

ACKNOWLEDGEMENTS:
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
    Chapter 5
    Available for download here:
        https://www.jblearning.com/catalog/productdetails/9781284089189#productInfo
================================================================================#=
*/

#include "Stack.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

// -----------------------------------------------------+-
// NodeType
// -----------------------------------------------------+-
//The Data Structure we are using to hold our items and point to the next item in the stack
struct NodeType
{
    ItemType info;
    NodeType* next;
};
// -----------------------------------------------------+-
// Constructor
// -----------------------------------------------------+-
Stack::Stack()
//Post: topNode and stackDepth are intialized
{
    topNode = NULL;
    stackDepth = 0;
};
// ---------------------------------------------------+-
// Destructor
// -----------------------------------------------------+-
Stack::~Stack()
//Deconstructs the stack
//Post: The stack has no nodes that will cause leaking memory.
{
    MakeEmpty();
}
// -----------------------------------------------------+-
// Observers
// -----------------------------------------------------+-
bool Stack::IsFull() const
//Checks to see if stack is full.
//Post: Returns false
//Robert Ensink told me that this linked list shouldn't be full, so he told me I could just return false
{
    return false;
};
bool Stack::IsEmpty() const 
//Checks to see if stack is empty.
//Post: Returns true if the stack is empty and false if it isn't 
{
    if(topNode == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};
int Stack::GetDepth() const
//Get the stack's depth.
//Post: returns the stack's length.
{
    return stackDepth;
};
ItemType Stack::Top()
//Read the top item in the stack
//Post: returns the value of top stack item and if there is no item, will throw an exception. 
{
    //
    if(topNode == NULL)
    {
        throw std::invalid_argument("The Stack has nothing to Pop!");
    }
    else
    {
        return topNode->info;
    }
};
std::string &Stack::ToString(std::string &s) const
//Borrowed Code From Robert Ensink.
//Pre: stackdepth and topNode are initalized.
//Post:  The contents on the stack are returned as a string to the caller. 
//Adds the contents of the stack into a referenced string in teh string data type. Highschooler level-Turns all the numbers in the stack into words.
{
    NodeType*   next_node = topNode;
    std::string item_string;

    s.clear();
    s.append("[");
    s.append(std::to_string(stackDepth)+": ");

    for(auto idx = 0; idx < stackDepth; idx++)
    {
        if(idx > 0) {
            s.append(", ");
        }
        auto next_item = next_node->info;
        s.append(next_item.ToString(item_string));
        next_node = next_node->next;
    }
    s.append("]");
    return s;
};
// -----------------------------------------------------+-
// Transformers
// -----------------------------------------------------+-

void Stack::Push(ItemType item)
// Adds a new item to the top of the stack.
// Pre:  Stack has been initialized.
// Post: New node has been pushed onto the top of the stack. 
{
    NodeType* topstack = new NodeType;
    //Creating a new topnode
    topstack->info = item;
    //Setting that new node's info to the given item's info
    topstack->next = topNode;
    //Setting that new node to point to the top of teh stack. 
    topNode = topstack;
    //Setting the top of the stack as the most recent node.
    stackDepth++;
};
ItemType Stack::Pop()
//Returns the top item in the stack and then removes it from the stack
//Pre:  Stack has been initialized.
//Post: Item from teh top of the stack has been returned and deleted
//Returns the top item and deletes the top item in the stack
{
if(topNode == NULL)
{
    throw std::invalid_argument("The Stack has nothing to Pop!");
}
else
{
    NodeType* temptopstack;
    temptopstack = topNode;
    //Create a temp point that point to teh same location TopNode does.
    topNode = topNode->next;
    //Changing TopNode so that it points to the next node in the stack
    ItemType tempitem; 
    tempitem = temptopstack->info;
    //Returning the value of the old TopNode
    delete temptopstack;
    //Deleting the teh Old TopNode
    stackDepth--; 
    //Reducing teh stack depth by one since we have removed an item
    return tempitem;
}
}
void Stack::MakeEmpty()
//Removes all nodes in the list and sets stackDepth to Zero.
//Post: No nodes remain in the list and stackDepth is zero. 
//I was able to fix my makeEmpty, did you know you get a segmentation fault if you don't set stackDepth to 0?
{
    //Set a temporary pointer
    NodeType* tempNode;
    
    while (topNode != NULL)
    //While the top of the stack doesn't point to the bottom of the stack
    {
        tempNode = topNode;
        //Set a temporary pointer to the 
        topNode = topNode->next;  
        //Set the pointer of TopNode to the 'next' pointer of the node that TopNode points to. 
        delete tempNode;
        //Delete what tempNode points to. 
    }
    stackDepth = 0;
    //Set the length of the stack to 0. 

}