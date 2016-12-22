//****************************************************************************
//  CS311 Linked //  Header File  hw3ec.cpp
// ** HW: HW03P3 Extra Credit
// ** Your name:  Samir Asfirane
//****************************************************************************

# include <iostream>
# include "slist.h"

using namespace std;


int main() {

  el_t NumTemp = 0;            // create an element to be used as value storage
  slist L1 = slist();          // create an empty slist named L1
  slist L2 = slist();          // create an empty slist named L2
  // display message before test case 1
  cout << "1.L1 is empty and L2 is empty " << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;   // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;     // if not equal print to the console they're not equal
  // adding two elements to L2 in preparation for test case 2
  L2.addFront(1);   // adding element 1 to the front of L2
  L2.addRear(2);    // adding element 2 to the rear of L2 
  // display message before test case 2
  cout << "2.L1 is empty and L2 has 2 elements " << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;   // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;     // if not equal print to the console they're not equal
  // remove element from L2 in preparation for test case 3 
  L2.deleteRear(NumTemp);    // remove one element by removing rear
  L2.deleteRear(NumTemp);    // remove second element by removing rear
  if (L2.isEmpty()) cout << " L2 is empty now !" << endl;  // verify that L2 is empty
  // adding two elements to L2 in preparation for test case 3
  L1.addFront(1);   // adding element 1 to the front of L1
  L1.addRear(2);    // adding element 2 to the rear of L1
  // display message before test case 3
  cout << "3.L1 has 2 elements and L2 is empty " << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;    // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;      // if not equal print to the console they're not equal
  // adding elements to L1 in preparation of test case 4
  L1.addRear(3); // adding element 3 to the rear
  // adding elements to L2 in preparation of test case 4
  L2.addFront(1);   // adding element 1 to the front of L2
  L2.addRear(2);    // adding element 2 to the rear of L2 
  L2.addRear(3);    // adding element 3 to the rear of L2 
  // display message before test case 4
  cout << "4.L1 has 1,2,3 and L2 has 1,2,3" << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;   // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;     // if not equal print to the console they're not equal
  // remove element 3 from L2 in preparation for test case 5
  L2.deleteRear(NumTemp);
  // display message before test case 5
  cout << "5.L1 has 1,2,3 and L2 has 1,2 " << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;   // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;     // if not equal print to the console they're not equal
  // adding element 3 and 4 to L2 in preparation for test case 6
  L2.addRear(3);
  L2.addRear(4);
  // display message before test case 5
  cout << "6.L1 has 1,2,3 and L2 has 1,2,3,4 " << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;   // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;     // if not equal print to the console they're not equal
  // remove the third element from L2 which is 3 in preparation for test case 7
  L2.deleteRear(NumTemp);     // remove the rear
  L2.replace(NumTemp, 3);     // replace element on 3 pos which is 3 by NumTemp which is 4
  // display message before test case 7
  cout << "7.L1 has 1,2,3 and L2 has 1,2,4 " << endl;
  // comparing L1 and L2 using the overloaded == operator
  if (L1 == L2) cout << " L1 is equal to L2 " << endl;   // if equal print to the console they're equal
  else  cout << " L1 is not equal to L2 " << endl;     // if not equal print to the console they're not equal
  return (0);

}



