// ========================================================
//HW2P2 Sorting Analysis-Merge Sort
//Your name: Samir Asfirane
//Complier:  g++
//File type: source file merge_sort.cpp
//=========================================================

#include <iostream> 
#include <vector>
using namespace std;

// function combine prototype takes three arguments 
// and returns none
void combine(vector <int> L1, vector <int> L2, vector <int>& L3);

// function displayAll prototype takes one argument
// and returns none
void displayAll(vector <int> L1);

// beginning of main
int main() {

  // declare three vectors L1, L2 to hold 
  // user input and L3 to hold sorted list
  vector<int> L1, L2, L3;

  // initialize first and last with correct values before calling 
  // binary search
  int number; 

  // repeat this operation twice 
  // to fill in L1 and L2
  for (int i = 0; i < 2; i++)
    {
      // Display a message to the user asking for integers in increasing order one at a time
      cout << "Enter three integers in increasing order one at a time for list # : " << i+1 << endl;
      // read from the keyboard the user input
      // and store it in neededInteger
      // if input is not an integer
      for (int j = 0; j < 3; j++) {
	if (!(cin >> number)) {
	  // display an error message and ask user to enter an integer 
	  cout << "The input you entered is illegal, please enter an integer! " << endl;
	  cin.clear(); // flush the input buffer
	  cin.ignore(INT_MAX, '\n'); // ingonre the line typed until the end of line character
	  j = 0; // reintialize j as the input was incorrect
	  continue;// continue looping

	}
	// if input is an integer
	else {
	  // use i to differentiate between the two lists
	  switch (i){
	    // if we are taking integers for L1
	  case 0: {
	    // check that the number enetered
	    // are in increasing order, first case
	    // when the list is empty we add  
	    // the integer to the list
	    if (L1.empty()) {
	      L1.push_back(number); // add current element to the list
	      
	    }
	    // if the list is not empty we compare
	    // the entered element with the last element 
	    // so far in the list if lesser or equal 
	    else if (number <= L1.back()) {
	      // display an error message and ask for a new entry
	      cout << " You entered an number that is not in increasing order" << endl;
	      cout << "Please try again with a different number" << endl;
	      j--; // decrement j since the entry was erroneous 
	      continue; // continue looping
	    }
	    // if the element entered is greater than all
	    // the last element in the list (thus all elements)
	    // add the entry to the list
	    else if (number > L1.back()) {
	      L1.push_back(number); // add current element to the list
	      
	    }
	  }
	    break; // end of case 0

	    // else if we are taking integers for L2
	  case 1: {
	    // check that the number enetered
	    // are in increasing order, first case
	    // when the list is empty we add  
	    // the integer to the list
	    if (L2.empty()) L2.push_back(number);
	    // if the list is not empty we compare
	    // the entered element with the last element 
	    // so far in the list if lesser or equal 
	    else{
	      if (number <= L2.back()) {
		// display an error message and ask for a new entry
		cout << " You entered an number that is not in increasing order" << endl;
		cout << "Please try again with a different number" << endl;
		j--; // decrement j since the entry was erroneous 
		continue; // continue looping
	      }
	      // if the element entered is greater than all
	      // the last element in the list (thus all elements)
	      // add the entry to the list
	      else if (number > L2.back()) L2.push_back(number);  // add current element to the list
	    }

	  }
	    break;  // end of case 1


	    // This is in case i goes over 1 which should never happen
	  default: cout << "Your loop is questionable, check your code please! " << endl;
	    break;  // end of default


	  }
	}
      }
    }

  // display L1 and L2 to the user to see
  // the two lists before the call to combine
  cout << " Your first list : ";
  displayAll(L1);
  cout << " Your second list : ";
  displayAll(L2);
  // call combine for with L1 and L2 as arguments 
  // and L3 is the third argument that is the result 
  // of the combination
  combine(L1, L2, L3);
  // display L3 after the combination
  cout << " Your combined list is : ";
  displayAll(L3);

}

// ==========================================================
// method combine(vector <int>, vector <int>, vector <int>)  
// takes an three integer vectors as arguments, L1, L2 and L3   
// it combines the sorted vectors L1 and L2 into a new sorted 
// vector L3 using merge sort and it returns nothing 
//===========================================================
void combine(vector <int> L1, vector <int> L2, vector <int>& L3) {
  // repeat this operation until one of 
  // the twolists to combine is empty
  while (!(L1.empty()) && !(L2.empty())) {

    // if the first element in the first list
    // is smaller than the first element in the 
    // second list 
    if (L1.at(0) <= L2.at(0)) {
      L3.push_back(L1.at(0)); // add the smaller element to the new combined list
      L1.erase(L1.begin()); // erase the added element from the list it was added from

    }

    // if the first element in the second list
    // is smaller than the first element in the 
    // first list
    else {
      if (L2.at(0) < L1.at(0)) {
	L3.push_back(L2.at(0)); // add the smaller element to the new combined list
	L2.erase(L2.begin()); // erase the added element from the list it was added from
      }
    }
  }
  

  // check if L1 list is empty then add 
  // the remainder of L2 List to the combined list L3
  if (L1.empty()) {
    // go through the remainder of L2
    for (int i = 0; i < L2.size() ; i++) {
      L3.push_back(L2.at(i)); // add all remaining elements in L2 to L3

    }
  }

  // the other situation
  else
    {
      // check if L2 list is empty then add 
      // the remainder of L1 List to the combined list L3
      if (L2.empty()){
	// go through the remainder of L1
	for (int i = 0; i < L1.size() ; i++) {
	  L3.push_back(L1.at(i)); // add all remaining elements in L1 to L3

	}
      }
    }


}

//===========================================================
// method displayAll takes a vector of integers as argument
// checks if empty if not empty display all elements, if empty
// display empty
//===========================================================
void displayAll(vector <int> L1) {
  // if the vector is empty displays that the list is empty
  if (L1.empty()) cout << "Your list is empty! " << endl; 

  // otherwise starting from the beginning of list display all the elements
  else {
    // display a space before displaying elements
    cout << "  ";
    // go through all elements in the list 
    for (int i = 0; i < L1.size(); i++)
      {

	cout << " " << L1[i] << " "; // display element with space
      }
    cout << endl; // go to next line
  }
}
