//****************************************************************************
//  CS311 Linked //  Header File  Client.cpp
// ** HW: HW03P2
// ** Your name:  Samir Asfirane
//****************************************************************************

# include <iostream>
# include "slist.h"

using namespace std;

int main() {

  int index;             // decalre index to be used for finding pos and search
  slist list = slist();  // create a slist named list
  list.addFront(4);  // add 4 to the front
  list.addRear(6);   // add 6 to the Rear
  list.addRear(7);   // add 7 to the Rear
  list.addRear(8);   // add 8 to the Rear
  list.displayAll(); // display all element in the list
  index = list.search(6); // search for 6 and assign returned result in index
  // if search fucntion return a value that isn't -1 display found and position
  if (index != -1) cout << " 6 found in pos : " << index << endl;
  // else display element was't found
  else cout << "6 was not found! " << endl;
  list.replace(0, index);  // use the index found to replace 6 by 0
  index = list.search(8); // search for 8 and assign returned result in index
  // if search fucntion return a value that isn't -1 display found and position
  if (index != -1) cout << " 8 found in pos : " << index << endl;
  // else display element was't found
  else cout << "8 was not found! " << endl;
  list.replace(2, index);  // use the index found to replace 8 by 2
  list.displayAll(); // display all element in the list
  index = list.search(5); // search for 5 and assign returned result in index
  // if search fucntion return a value that isn't -1 display found and position
  if (index != -1) cout << " 5 found in pos : " << index << endl;
  // else display element was't found
  else cout << "5 was not found! " << endl;
  return (0);

}
