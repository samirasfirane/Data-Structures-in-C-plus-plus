//****************************************************************************
//  CS311 Linked //  Header File  llist.h
// ** HW: HW03P1
// ** Your name:  Samir Asfirane
//****************************************************************************


// We define an element type el_t as int
// as an element of the structure
typedef int el_t;

using namespace std;

// The basic elements of a Linked list are nodes.
// a node is composed of data and a reference to 
// the next node in our case the data is an element 
// of type el_t and the reference is a pointer to the
// next node in the list, if current node is the last 
// one in the list the pointer is NULL.
struct Node
{
  el_t Elem;
  Node *Next;
};

// definition of class llist as protected allows it's
// inheritance use and keeps it safe from lateral alteration
class llist
{
  // definition of class llist as protected allows it's
  // inheritance use and keeps it safe from lateral alteration
 protected:
  int count;// counter for the number of elements 
  Node *front;// front is a pointer to a Node which is at the "front" of the list.
  Node *rear;// rear is a pointer to a Node which is at the "rear" of the list.

  
 public:
   
  llist();// public constructor
  ~llist();// public destructor

  // Exception handling classes
  class Underflow {};// exception is thrown when accessing empty list is attempted
  class OutOfRange {};// exception thrown when index out of bound access is attempted

  // method to check if the list is empty or not
  bool isEmpty();
  // method displayAll() to display the content of the list
  void displayAll();

  // method addFront adds an element to the front of the list
  void addFront(el_t NewNum);

  // method addRear adds an element to the rear of the list
  void addRear(el_t NewNum);

  // method deleteFront deletes an element to the front of the list
  // this method passes parameters by reference
  void deleteFront(el_t& OldNum);

  // method deleteRear deletes an element to the rear of the list
  // this method passes parameters by reference
  void deleteRear(el_t& OldNum);

  // method addBeforeIth adds an element at the Ith position of the list
  void addBeforeIth(int I, el_t OldNum);
  // method deleteIth deletes the element at Ith position of the list
  void deleteIth(int I, el_t& OldNum);
};
