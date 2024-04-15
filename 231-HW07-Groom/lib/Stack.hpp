
/*
================================================================================#=
CLASS:   Stack
Version: Class Template, Array-Based Storage, Dynamic Array Allocation
FILE:    lib/Stack.hpp

ACKNOWLEDGEMENTS:
David Groom
Robert Ensink
The original version of this code is found in:
    C++ Plus Data Structures, Sixth Edition (Dale et al., 2018)
    Jones & Bartlett Learning, LLC
================================================================================#=
*/

#pragma once
#include <string>
#include <sstream>


// -----------------------------------------------------+-
// Template class to store elements with FIFO access.
//
// NOTE: because this is a Template Class,
// all the member function implementations
// must be located here, in the header file.
// -----------------------------------------------------+-
//Template here allows for ItemType here to be swapped out for another data type like float or another class at runtime while keeping the functionality of the Stack class the same
//Functionality-Allows classes to be reused for different datatypes without creating a entirely new class.
template<typename ItemType>
class Stack
{
    private:
        int stackDepth;
        int top;
        int maxStack;
        ItemType *items;

    public:

        // -----------------------------------------------------+-
        // Constructor
        // -----------------------------------------------------+-

        Stack(int max)
        /*
        Post: maxStack, top, and items, and stackdepth all have been initialised and set to their proper corrosponing values
        Function: To create the necesary data items required to operate a stack array-based implementation
        */
        {
            maxStack = max;
            top = -1;
            items = new ItemType[maxStack];
            stackDepth = 0;
        }


        Stack()
        /*
        Post: maxStack, top, and items, and stackdepth all have been initialised and set to their proper corrosponing values
        Function: To create the necesary data items required to operate a stack array-based implementation
        */
        {
            maxStack = 500;
            top = -1;
            items = new ItemType[maxStack];
            stackDepth = 0;
        }

        // -----------------------------------------------------+-
        // Observers
        // -----------------------------------------------------+-

        std::string ToString(std::string &s) const
        //Borrowed Code From Robert Ensink.
        //Pre: stackdepth is initalized.
        //Post:  The contents on the stack are returned as a string to the caller. 
        //Adds the contents of the stack into a referenced string in the string data type. Highschooler level-Turns all the items in the stack into words.
        {
            std::stringstream ss;
            s.clear();
            ss << "[";
            ss << stackDepth;
            ss << ": ";

            for(int idx = 0; idx < stackDepth; idx++)
            {
                if(idx > 0) {
                    ss << ", ";
                }
                ss << items[idx];
            }
            ss << "]";
            s.append(ss.str());
            return s;
        };
        

        bool IsEmpty() const
        /*
        Pre: Top has been initialized.
        Post: A boolean value is returned based on if top == -1.
        Function: To check to see if the stack is empty.
        */
        {
            return (top == -1);
        }


        bool IsFull() const
        /*
        Pre: Top and maxStack have been initialized.
        Post: A boolean value is returned.
        Function: To check to see if the stack is full.
        */
        {
            return (top == maxStack-1);
        }

        int GetDepth() const
        /*
        Pre: stackDepth have been initialized.
        Post: A int value is returned based on the value of stackDepth.
        Function: Returns the stack's depth/length.
        */
        {
            return stackDepth;
        }
 
        ItemType Top()
        /*
        Pre: Top and items have been initialized and the stack is not empty.
        Post: Returns the Stack's top item.
        Function: To return the top item in the stack.
        */
        {
            if (IsEmpty())
            {
                throw std::invalid_argument("There is nothing in the Stack!");
            }
                
            return items[top];
        }  
        // -----------------------------------------------------+-
        // Transformers
        // -----------------------------------------------------+- 

        void Push(ItemType newItem) 
        /*
        Pre: Top, stackdepth, and items, have been initialized and the stack is not full.
        Post: Adds a new top item in the stack.
        Function: Adds a new item to the stack.
        */
        {
            if (IsFull())
            {
                throw std::invalid_argument("The Stack is Full!");
            }
            top++;
            items[top] = newItem;
            stackDepth++;
        }


        ItemType Pop()
        /*
        Pre: Top, stackdepth, and items, have been initialized and the stack is not empty.
        Post: Decrements the top in the stack and returns that item to the caller.
        Function: Deletes top item in the stack and returns that item to the caller.
        */
        {
            if( IsEmpty())
            {
                throw std::invalid_argument("There is nothing in the Stack!");
            }
            top--;
            stackDepth--;
            return items[top + 1];
        }


        void MakeEmpty()
        /*
        Post: Sets top to -1 and stackdepth to 0. 
        Function: Empties the contents of the list
        */
        {
            top = -1;
            stackDepth = 0;
        }
        // -----------------------------------------------------+-
        // Destructor
        // -----------------------------------------------------+-

        ~Stack()
        /*
        Post: Deletes the array that holds the contents of the stack. 
        Function: Deletes the stack.
        */
        {
            delete  [] items;
        }

};

