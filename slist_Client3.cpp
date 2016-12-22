//****************************************************************************
//  CS311 Linked //  Header File  Client.cpp
// ** HW: HW03P3
// ** Your name:  Samir Asfirane
//****************************************************************************

# include <iostream>
# include "slist.h"

using namespace std;

// Prototype for function copy test
void CopyTest(slist);

int main() {

  slist L1 = slist();          // create a slist named L1
  L1.addFront(1);              // add 1 to the front
  L1.addRear(2);               // add 2 to the Rear
  L1.addRear(3);               // add 3 to the Rear
  L1.addRear(4);               // add 4 to the Rear
  L1.addRear(5);               // add 5 to the Rear
  // display a message before the call to copy test
  cout << "Calling the CopyTest function to copy L1 and display the copy! " << endl;
  CopyTest(L1);                // calling CopyTest
  // display a message to user to know which list we are displaying
  cout << " diplaying L1 after making a copy! " << endl;
  L1.displayAll();             // display L1 
  L1 = L1;                     // assign L1 to L1
  // display a message to user to know which list we are displaying
  cout << " Displaying L1 after assignement L1 = L1 ! " << endl;
  L1.displayAll();             // display L1
  slist L2 = slist();          // create a slist named L2
  L2.addFront(7);              // add 7 to the front
  L2.addRear(8);               // add 8 to the Rear
  L2.addRear(9);               // add 9 to the Rear
  L2.addRear(10);              // add 10 to the Rear
  // display a message to user to know which list we are displaying
  cout << " Displaying L2 before assignement ! " << endl;
  L2.displayAll();             // display L2
  L2 = L1;                     // assign L1 to L2 
  // display a message to user to know which list we are displaying
  cout << " Displaying L2 after assignement L2 = L1 ! " << endl;
  L2.displayAll();             // display L2
  el_t RearL1;                 // declare the element that will hold removed value
  L1.deleteRear(RearL1);       // remove L1 rear and store in RearL1
  // display a message to user to know which list we are displaying
  cout << " Displaying L1 after removing rear ! " << endl;
  L1.displayAll();             // display L1
  L1.displayAll();             // display L1 again
  // display a message to user to know which list we are displaying
  cout << " Displaying L2 after removing rear from L1 ! " << endl;
  L2.displayAll();             // display L2 again
  





  return (0);

}

// Method CopyTest(slist list) takes a slist as an argument
// makes a copy of it by calling the copy constructor 
// of slist add node 6 to its rear and displays the results
// copy test returns no value
void CopyTest(slist list) {
  // calls the copy constructor to create a copy of list
  slist listCopy = slist(list);
  // calls addRear to add node 6 to the copy list
  listCopy.addRear(6);
  // displays the new copy with the addition
  listCopy.displayAll();
}

