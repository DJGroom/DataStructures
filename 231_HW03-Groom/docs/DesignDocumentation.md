
# Unsorted List (Array Based Implementation)
Based on: C++ Plus Data Structures: Chapter 3: ADT Unsorted List

## CRC Cards

----
##### Class Name: ItemType
----
##### Responsibilities:
```
Define RelationType: LessThan, GreaterThan, EqualTo.

ComparedTo: compares this Item with another and returns RelationType.

ToString: returns a string representation of the item.
```


----
##### Class Name: UnsortedType
----
##### Responsibilities:
```
Constructor:
    Creates a new empty list.

Destructor:
    Does the needful to free any dynamically allocated memory.

IsFull:
    Observer.
    Returns boolean whether list is full.

GetLength:
    Observer.
    Returns current length of the list.

GetItem:
    Observer.
    Finds the given item in the list and returns that item if found.
    Returns a boolean flag to indicate whether the item was found.

MakeEmpty:
    Transformer.
    Resets the list to an empty state, length is zero.

PutItem:
    Transformer.
    Adds the given item to the list.

DeleteItem:
    Transformer.
    Deletes the given item from the list.

ResetList:
    Iterator.
    Resets the state of the iteration back to the start of the list.

GetNextItem:
    Iterator.
    Gets the next element from the list within the current iteration through the list.
```


