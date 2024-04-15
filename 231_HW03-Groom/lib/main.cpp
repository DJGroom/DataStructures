
#include "UnsortedList.hpp"

#include "ItemType.hpp"

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


int main(){
//Creating items
ItemType *one = new ItemType(1);
ItemType *two = new ItemType(56);
ItemType *three = new ItemType(9);
ItemType *four = new ItemType(26);
ItemType *five = new ItemType(13);
ItemType *six = new ItemType(16);
ItemType *seven = new ItemType(17);
UnsortedList *list = new UnsortedList();
//Putting all items in a list
list->PutItem(*one);
list->PutItem(*two);
list->PutItem(*three);
list->PutItem(*four);
list->PutItem(*five);
list->PutItem(*six);
list->PutItem(*seven);
//Creating Two seperate lists and putting some items in them
UnsortedList *list1 = new UnsortedList();
list1->PutItem(*five);
UnsortedList *list2 = new UnsortedList();
list2->PutItem(*six);
list->SplitList(*list1, *list2, *seven);
//Testing split list
list1->GetNextItem();
list2->GetNextItem();
printf("Split list one test: %d", list1->GetNextItem());
printf("Split list two test: %d", list2->GetNextItem());
//Here I am grabbing the next couple of items to see if these lists have been split properly and then printing teh results
list1->ResetList();
list2->ResetList();
//Reseting list to ensure that I have acces to each item in teh linked list. 
list1->PutItem(*three);
list1->DeleteItem(*three);
//Putting two identical objects in a list and deleting both of them 
list2->DeleteItem(*three);
//Trying to delete an object that isn't there
printf("Delete list one item one %d", list1->GetNextItem());
printf("Delete list one item two %d", list1->GetNextItem());
printf("Delete list one item two %d", list1->GetNextItem());
printf("Delete list one item two %d", list1->GetNextItem());

printf("Delete list two item one %d", list2->GetNextItem());
printf("Delete list two item two %d", list2->GetNextItem());
return 0; 
}