//****************************************************************************
// CS311 Linked //  list File  llist.cpp
// Author: Samir Asfirane 
// HW: HW3P1
//****************************************************************************

#include <iostream>
#include "llist.h"

using namespace std;

// Basic constructors that intializes front rear and cout
llist::llist()
{
  front = NULL; // initializes front to Null
  rear = NULL;  // initializes rear to Null
  count = 0;    // initializes count to 0
}

// Class distructor goes through the list
// starting from the front and delete all
// the elements one by one.
llist::~llist()
{
  Node *ptr = front;
  Node *temp;
  while (ptr!=NULL)
    {
      temp = ptr->Next;
      delete ptr;
      ptr = temp;
    }
}

// method isEmpty takes no argument and returns a boolean
// true if list is empty and false if list is not empty.
bool llist::isEmpty()
{
  // list is empty if both front and rear elements are NULL
  if ((front == NULL) && (rear == NULL))
    {
      return(true); // if true return true
    }
  else
    {
      return(false); // return false otherwise
    }
}

// method dispplayAll takes no arguments and returns none
// method displays the elements of the list to the console window
// if list is empty method displays your list is empty
void llist::displayAll()
{
  // checks if list is empty
  if (isEmpty())
    {
      cout << "Your list is empty !" << endl; // displays empty message
    }
  else
    {
      // use a pointer to go through the list
      Node *temp = front; 
      // intialize i to 0
      int i = 0;

      
      // loop through the list using the count as limit
      // print all nodes one by one
      while (i!=count)
	{
	  cout << "[ " << temp->Elem << " ] ";
	  temp = temp->Next;
	  i++;
	}
      cout << endl;
    }
}

// method addFront takes an argument of type
// el_t and add it to the front of the list 
// addRear returns no argument
void llist::addFront(el_t NewNum)
{
  // if is empty
  if (isEmpty())
    {
      Node *temp = new Node;    // creat a new Node
      temp->Next = NULL;        // make its pointer point to NULL since temp is first element in the list
      temp->Elem = NewNum;      // the data part of the node is the argument passed to the function
      front = temp;             // set front element to temp
      rear = temp;              // set rear element to temp
    }
  else
    {
      Node *temp = new Node;  // Create a new node
      temp->Next = front;       // make the pointer of the new node point to the old front
      front = temp;             // make front point to the new front (new node added)
      front->Elem = NewNum;     // save the elem added in the data part of front
    }
  count++;
}

// method addRear takes an argument of type
// el_t and add it to the rear of the list if 
// list not empty, if list empty adds it to front
// addRear returns no arguments
void llist::addRear(el_t NewNum)
{
  // if the list is empty
  if (isEmpty())
    {
      Node *temp = new Node; // creat a new Node
      temp->Next = NULL;     // make its pointer point to NULL since temp is first element in the list
      temp->Elem = NewNum;   // the data part of the node is the argument passed to the function
      front = temp;          // set front element to temp
      rear = temp;           // set rear element to temp
    }
  else
    {
      rear->Next = new Node;// Create a new node that is the new rear
      rear = rear->Next;      // save the pointer to the new rear in rear
      rear->Elem = NewNum;      // save the elem added in the data part of rear
      rear->Next = NULL;      // the pointer in the node rear points to NULL
    }
  count++;  // increment the element count in the list 
}

// method deleteRear receive a reference to an element OldNum as
// argument, delete the front of the list and saves it in the 
// element that it received the reference as argument OldNum, this method
// returns no value.
void llist::deleteRear(el_t& OldNum)
{
  // if the list is empty there is nothing to delete
  if (isEmpty())
    {
      throw Underflow(); // If the list is empty() throw underflow but do not exit!
    }
  // if the list is not empty
  else
    {
      OldNum = rear->Elem; // save the element to be deleted in OldNum.

      // in case there is only one element in the list
      // the list becomes empty after deleting the only element
      if (front->Next == NULL)
	{
	  front = NULL;  // set front to NULL 
	  rear = NULL;   // set rear to NULL 
	}
      // if there are more than one elements in the list 
      else 
	{
	  Node *temp = front;// set temp to hold front value 

	  // loop until we reach the element that points to rear
	  while (temp->Next != rear)
	    {
	      temp = temp->Next; // make temp point to that element
	    }

	  delete rear;       // delete rear element 
	  rear = temp;   // set the new rear to the value in temp
	  rear->Next = NULL; // and set the pointer in rear to point to NULL  
	}

      count--; // decrement the number of elements in list by one
    }
}

// method deleteFront receive a reference to an element OldNum as
// argument, delete the front of the list and saves it in the 
// element that it received the reference as argument OldNum, this method
// returns no value. 
void llist::deleteFront(el_t& OldNum)
{
  // if list is empty there is no element to delete
  if (isEmpty())
    {
      throw Underflow(); // If the list is empty() throw underflow but do not exit!
    }

  // if list is not empty
  else
    {
      OldNum = front->Elem; // save the element to be deleted in OldNum.

      // in case there is only one element in the list
      // the list becomes empty after deleting the only element
      if (front->Next == NULL) 
	{
	  front = NULL;  // set front to NULL 
	  rear = NULL;   // set rear to NULL
	}
      // if there are more than one elements in the list 
      else 
	{
	  Node *temp = front->Next; // make temp point to the second element in the list
	  delete front;             // delete front
	  front = temp;          // set the temp which contains the old second element to become the new front
	}
      count--; // decrement the number of elements in list by one
    }
}

// method deleteIth receives and index where to find 
// the element to delete and a reference to an element OldNum as
// argument, delete the Ith element of the list and saves its 
// data part in OldNum the element that it received the reference 
// as argument. this method returns no value. 
void llist::deleteIth(int I, el_t& OldNum)
{
  // checks if index supplied is correct
  // by comparing it the number of elements and 1
  if ((I < 1) || (I > count))
    {
      throw OutOfRange(); // if wrong index supplied throw an out of range exception but do not exit!
    }

  // if index correct check if list is empty
  else if (isEmpty())
    {
      throw Underflow(); // If the list is empty() throw underflow but do not exit!
    }
  // case where I is index of front element 
  else if (I == 1) 
    {
      deleteFront(OldNum); // delete front element by calling deleteFront method
    }
  // case where I is index of rear element
  else if (I == count)
    {
      deleteRear(OldNum); // delete rear element by calling deleteRear method
    }
  // in the case  the index is of an element in the middle
  else
    {
      Node *temp, *temp_del; // declare to pointers to use for deletion and substitution 
      temp = front;          // intialize temp as front to use to go through the list
      // loop through the list looking for the Ith -1 element
      for (int i = 0; i < I - 2; i++)
	{
	  temp = temp->Next; // temp points now to the Ith -1 element in the list
	}

      temp_del = temp->Next;       // temp_del points to the Ith element in the list ( element to be deleted)
      OldNum = temp_del->Elem;     // save the data part of the Ith element in OldNum 
      temp->Next = temp_del->Next; // make the Ith -1 element points to the Ith +1 element

      delete temp_del;   // delete the Ith element          
      count--; // decrement the list element number by one
    }
}

// method addBeforeIth receives and index where to find 
// the position where to add the element and the element to add NewNum
// as arguments, add NewNum to the list at the Ith position 
// this method returns no value. 
void llist::addBeforeIth(int I, el_t NewNum)
{
  // checks if index supplied is correct
  // by comparing it the number of elements and 1
  if ((I < 1) || (I > count + 1))
    {
      throw OutOfRange(); // if wrong index supplied throw an out of range exception but do not exit!
    }
  // if index correct check if list is empty
  else if (isEmpty())
    {
      throw Underflow(); // If the list is empty() throw underflow but do not exit!
    }
  // case where I is index of front element 
  else if (I == 1)
    {
      addFront(NewNum); // add front element by calling addFront method
    }
  // case where I is index of rear element + 1 which is a legit index
  else if (I == count + 1)
    {
      addRear(NewNum); // add rear element by calling addRear method
    }
  // in the case  the index is of an element in the middle
  else
    {
      Node *temp, *temp_add; // declare to pointers to use for deletion and substitution 
      temp = front;          // intialize temp as front to use to go through the list
      // loop through the list looking for the Ith -1 element
      for (int i = 0; i < I - 2; i++)
	{
	  temp = temp->Next; // temp points now to the Ith -1 element in the list
	}

      temp_add = new Node;         // create the new node to add and point to it using temp_add
      temp_add->Next = temp->Next; // temp_add now points to the old Ith element
      temp->Next = temp_add;       // temp which is in the old Ith-1 element points to temp_add the new Ith element
      temp_add->Elem = NewNum;     // updating the data part of new node pointed to by temp_add

      count++; // increment the count of the elements of the list by one
    }
}
