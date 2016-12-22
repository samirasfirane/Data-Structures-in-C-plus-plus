//****************************************************************************
//  CS311 Linked //  Header File  slist.cpp
// ** HW: HW03P2
// ** Your name:  Samir Asfirane
//****************************************************************************


#include <iostream>
#include "slist.h"

using namespace std;

// Basic constructors that intializes front rear and cout
slist::slist()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

// This constructor takes an argument of type reference to 
// constant slist and creates an integral copy of that list, 
// element by element. Due to front, rear and count of list 
// declared protected, the only way to access them without 
// altering them is to use a reference to a constant.
slist::slist(const slist& list)
{
  front = NULL; // intialize front of created list to Null
  rear = NULL;  // intialize rear of created list to Null
  count = 0;    // intialize elements count of created list to 0

  // temp is a pointer to the first node in the list
  // that is to be copied
  Node* temp = list.front;

  // goes through the list to be copied from front to rear until
  // temp points to Null which happens right after temp = rear
  while (temp != NULL)
    {
      // we use the addRear method to add the copies of elements 
      // from list to be copied to the new list
      this->addRear(temp->Elem);// add element to current list being created
      temp = temp->Next;// points to next element    
    }
}

// Overloaded equality operator compares two lists and
// return true if and only if the two lists are equal 
// element by element it takes a reference to a list
// of type slist as a parameter and return a boolean.
bool slist::operator==(slist list)
{
  // check if both lists are empty in which case they're 
  // equal, even if they have different addresses in memory
  if (list.isEmpty() && this->isEmpty())
    {
      return true; // return true cause they're equal
    }

  // if they're not both empty and they're
  // of a different size they're not equal
  else if (this->count != list.count)
    {
      return false; // return false cause they're not equal
    }
  // if they're not both empty and they have
  // the same size and they point to the same 
  // object then they're the same
  else if (&list == this)
    {
      return true; // return true becasue they're the same
    }
  // if they're not both empty and have the same size but 
  // point to two different locations in memory we need to 
  // loop through both and compare them element by element to
  // each other.
  else {
    // create a node that points to the front of the calling list
    Node* node_current = this->front;
    // create a node that points to the front of the parameter list
    Node* node_compared = list.front;
    // as long as there are elements to compare
    while (node_current != NULL)
      {
	// if two elements in the compared lists are found to be 
	// differents then return false
	if (node_current->Elem != node_compared->Elem)
	  {
	    return false; // two elements found to be differents
	  }

	// if the elements compared are not differents
	node_current = node_current->Next; // move to the next one in the calling list
	node_compared = node_compared->Next; // move to the next one in the compared list
      }
    // if no elements are found to be differents then 
    // the lists are equal and we return true
    return true;
  }
}

// Definition of the new overloaded assignement operator that takes
// a reference to a constant list and returns a reference to the new
// list that has been assigned the content of the list which reference 
// was passed as a parameter since we cannot return the whole list.
slist& slist::operator=(const slist& list)
{
  // check if the objects are equal using the overloaded
  // equality operator before assignement
  if (&list == this)  return *this; // do nothing
  else
    {
      // if the calling list is not empty we
      // need to make it empty before assigning new elements
      el_t elem;  // declare the element used by deleteRear to delete Rear element
      // as long as there are elements to be deleted
      while (!this->isEmpty())
	{
	  this->deleteRear(elem); // delete the rear element 
	}

      // Declare a temp node to be used for temporary values to be copied to the empty list
      // intialize temp to front of the list to be copied
      Node* temp = list.front;

      // as long as the list to be copied has elements in it
      while (temp != NULL) 
	{
	  // add a copy of the front of the list to be copied to the rear of the empty list
	  this->addRear(temp->Elem);
	  // move temp to the next node in the list to be copied
	  temp = temp->Next; 
	}
    }
  return *this;// return a reference to the list that was copied to (current list) 
}


// Definition of method search(el_t key) that takes as argument of type
// el_t and returns and integer representing the position the 
// element of type el_t in the list if found in the list searched
// or return -1 if not found
int slist::search(el_t Key)
{
  // check if list is empty
  if (isEmpty())
    {
      throw Underflow(); // if empty throw underflow
    }
  // search_node represents the node being searched for the el_t key
  Node *search_node = front; 
  // search_position represents the current search position in the list
  int search_position = 1; 

  // while there are still elements to be searched
  while (search_node != NULL)
    {
      // if the data part of the node searched equals 
      // the element searched
      if (search_node->Elem == Key)
	{
	  return(search_position); // return the current position
	}
      // if not found in the current element
      else 
	{
	  search_position++; // increment the position by 1
	  search_node = search_node->Next; // move to the next node to continue search
	}
    }
  return -1; // if not found return -1
}

// Definition of method replace(el_t Elem, int I) that takes 
// an argument Elem of type el_t and an integer I and replaces 
// the element in the Ith position with Elem 
// this method returns no arguments. 
void slist::replace(el_t Elem, int I)
{
  // checks if index supplied is correct
  // by comparing it to the number of elements and 1
  if ((I < 1) || (I > count + 1))
    {
      throw OutOfRange(); // if wrong index supplied throw an out of range exception but do not exit!
    }
  // if index correct check if list is empty
  else if (isEmpty())
    {
      throw Underflow(); // If the list is empty() throw underflow but do not exit!
    }
  else
    {
      // search_node represents the node being searched for Ith element
      // starting with the front Node
      Node *search_node = front;

      // we loop through the list using a for loop
      // starting with position 1 and going through until
      // we reach I-1
      for (int i = 1; i < I; i++)
	{
	  search_node = search_node->Next;// as we go make search_node point to the next node
	}

      // once we point to the Ith element
      search_node->Elem = Elem; // we replace the data part with Elem
    }
}



