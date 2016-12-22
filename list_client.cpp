//****************************************************************************
// CS311 Linked //  list File  client.cpp
// Author: Samir Asfirane 
// HW: HW3P1
//****************************************************************************

#include <iostream>
#include "llist.h"

using namespace std;

// Function prototypes for test case 
// one through 4 
void function1();
void function2();
void function3();
void function4();

int main()
{
  // number to be used as the user selection
  int selection=0;
  
  // display menu message to the user
  
  while (selection!=5) {
    cout << "Please enter the case number you want to do entries must be 1 to 4 and 5 to quit : " << endl;
    cin >> selection;
    switch (selection) {
      // case 1 program calls function 
    case 1: function1();
      break;
    case 2: function2();
      break;
    case 3: function3();
      break;
    case 4: function4();
      break;
    case 5: cout << "the program will quit now!  " << endl;
      break;
    default: cout << "the entry you made is not valid please enter an integer between 1 and 5. Thank you! " << endl;

    }
  }


  return(0);
}
// function function1() display case1 from the 
// assignement sheet, takes no argument
// and returns no argument just make the menu easier
// and user friendly
void function1()
{
  // declare a new list of type llist
  llist List = llist();
  // declare element to hold removed values
  el_t elem;

  // check if List is empty
  if (List.isEmpty())
    {
      cout << "The list was checked and the list is empty! " << endl; // display message that is empty
    }
  else
    {
      cout << "The list was checked and the list is not empty!" << endl; // display message that is not empty
    }

  // display the list 
  List.displayAll(); 
  // add 1 to the list 
  List.addRear(1);
  // add 2 to the list
  List.addRear(2);
  // add 3 to the list 
  List.addRear(3);
  // display the list 
  List.displayAll();
  // delete element from front
  try { List.deleteFront(elem); }
  // catch exception if any
  catch (llist::Underflow) {
    cout << " The list you are trying to delete from is empty" << endl;
  }
  // display removed element
  cout << elem << endl;
  // delete element from front
  try { List.deleteFront(elem); }
  // catch exception if any
  catch (llist::Underflow) { 
    cout << " The list you are trying to delete from is empty" << endl; 
  }
  // display removed element
  cout << elem << endl;
  // display the list 
  List.displayAll();
  // check if List is empty
  if (List.isEmpty())
    {
      cout << "The list was checked and the list is empty! " << endl; // display message that is empty
    }
  else
    {
      cout << "The list was checked and the list is not empty!" << endl; // display message that is not empty
    }
  // delete element from rear
  try { List.deleteRear(elem); }
  // catch exception if any
  catch (llist::Underflow) {
    cout << " The list you are trying to delete from is empty" << endl;
  }
  // display removed element
  cout << elem << endl;
  // check if List is empty
  if (List.isEmpty())
    {
      cout << "The list was checked and the list is empty! " << endl; // display message that is empty
    }
  else
    {
      cout << "The list was checked and the list is not empty!" << endl; // display message that is not empty
    }
}
// function function2() display case2 from the 
// assignement sheet, takes no argument
// and returns no argument just make the menu easier
// and user friendly
void function2()
{
  // declare a new list of type llist
  llist List = llist();
  // declare element to hold removed values
  el_t elem;
  // add 5 to front of the list
  List.addFront(5);
  // add 4 to the front of the list
  List.addFront(4);
  
  // delete front element
  try{ List.deleteFront(elem); }
  // catch underflow if any
  catch (llist::Underflow) {
    cout << " The list you are trying to delete from is empty" << endl;
  }
  
  // add 6 then 8 then 9 to list
  List.addRear(6);
  List.addRear(8);
  List.addRear(9);
  // display list 
  List.displayAll();
  try
    {
      // add 4 before position 1
      List.addBeforeIth(1, 4);
      // add 7 before position 4
      List.addBeforeIth(4, 7);
      // add10 before position 7
      List.addBeforeIth(7, 10);
    }
  // catch any out of range index exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }
  
  try
    {
      // add 12 before position 9 
      List.addBeforeIth(9, 12);
    }
  // catch any out of range index exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }
  
  try
    {
      // add 0 befrore position 0
      List.addBeforeIth(0, 0);
    }
  // catch any out of range index exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }
  // display list
  List.displayAll();
  // remove element at position 1 
  List.deleteIth(1, elem);
  // display removed element
  cout << elem << endl;
  // remove element at position 6
  List.deleteIth(6, elem);
  // display removed element
  cout << elem << endl;
  // remove element at position 3
  List.deleteIth(3, elem);
  // display removed element
  cout << elem << endl;

  try
    {
      // remove element at position 5
      List.deleteIth(5, elem);
    }
  // catch any out of range index exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  try
    {
      // remove element at position 0
      List.deleteIth(0, elem);
    }
  // catch any out of range index exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  // display list 
  List.displayAll();

  // while list is not empty
  while (!List.isEmpty())
    {
      // delete from rear
      List.deleteRear(elem);
      // display element removed
      cout << elem << endl;
    }

  // display list
  List.displayAll();
}
// function function3() display case3 from the 
// assignement sheet, takes no argument
// and returns no argument just make the menu easier
// and user friendly
void function3()
{
  
  // declare list 
  llist List = llist();
  // declare element to save element removed
  el_t elem;

  try
    {
      // add 0 before
      List.addBeforeIth(0, 0);
    }
  // catch any out of range index exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }
  
  try
    {
      // delete front element
      List.deleteFront(elem);
    }
  // catch any underflow exception
  catch (llist::Underflow)
    {
      cout << "The list you are trying to delete from is currently empty." << endl;
    }
}
// function function4() display case 4 from the 
// assignement sheet, takes no argument
// and returns no argument just make the menu easier
// and user friendly
void function4()
{
  // declare list 
  llist List = llist();
  // declare element to save element removed
  el_t elem;

  try
    {
      // delete element at 2 position
      List.deleteIth(2, elem);
    }
  // catch any out of range exception
  catch (llist::OutOfRange)
    {
      cout << "The index you provided was out of the range of the list." << endl;
    }

  try
    {
      // delete element in Rear
      List.deleteRear(elem);
    }
  // catch any underflow exception
  catch (llist::Underflow)
    {
      cout << "The list you are tying to delete from is currently empty." << endl;
    }
}
