//****************************************************************************
//  CS311 Linked //  Header File  slist.h
// ** HW: HW03P3 Extra Credit
// ** Your name:  Samir Asfirane
//****************************************************************************

// include llist.h to be inherited
#include "llist.h"

using namespace std;

// We define an element type el_t as int
// as an element of the structure
typedef int el_t;

// definition of class slist as inheriting publicly from
// llist class to allow access to public methods and members 
// and vertical access to protected methods and memebers.
class slist : public llist
{
 public:
   
  slist();// public constructor   

  // copy constructor
  slist(const slist& list);

  // overloaded assignment operator
  slist& operator=(const slist& slist);

  // overloaded equality operator
  bool operator==(slist slist);

  // function to search elements in the list
  int search(el_t Key);
  // function to replace elements in the list
  void replace(el_t Elem, int I);
};
