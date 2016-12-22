// ========================================================
//HW2P1 Binary Search
//Your name: Samir Asfirane
//Complier:  g++
//File type: source file binary_search.cpp
//=========================================================

#include <iostream> 
using namespace std;

// function binarySearch prototype takes four arguements and returns none
void binarySearch(int arr[], int elem, int first, int last);


int main() {

// delcare a constant variable
// used for the size of the array
const int MAX_SIZE = 10;

// declare and initialize the integer 
// that will hold user value
int neededInteger;


// declare the array of integers that
// we want to search and intialize it
int arrInt[MAX_SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

// initialize first and last with correct values before calling 
// binary search
int first = 0, last = MAX_SIZE - 1;

// repeat this operation
do
{	
	// Display a message to the user asking for a number to search or -999 to quit
	cout << "Enter an integer number to search for in the array or -999 to quit!" << endl;
	// read from the keyboard the user input
	// and store it in neededInteger	
	// if input is not an integer	
	if (!(cin >> neededInteger)) {	
			    // display an error message and ask user to enter an integer 
				cout << "The input you entered is illegal, please enter an integer! " << endl;
				cin.clear(); // flush the input buffer
				cin.ignore(INT_MAX, '\n'); // ingonre the line typed until the end of line character
				continue;	// continue looping		
			
		}
		// if input is an integer
		else {
			// if the input is -999 then quit the program
			if (neededInteger == -999) {
				cout << "The program will quit now" << endl; // inform the user program is quitting
				cin.clear(); // flush the input buffer
				cin.ignore(INT_MAX, '\n'); // ingonre the line typed until the end of line character
				break; // break out of the loop
			}
			// if the input is an integer and it is not -999 proceed to search
			else {
				// call the binarySearch function passing arrInt as the
				// array to be searched, neededInteger the integer entered 
				// by user to be searched, first element in array = 0, and 
                // last element is MAX_SIZE - 1  which is 9
				binarySearch(arrInt, neededInteger, first, last); // call search function
				cin.clear(); // flush the input buffer for the next entry
				cin.ignore(INT_MAX, '\n'); // ingonre the line typed until the end of line character
			}
			
		}

	}



// repeat the loop until user enters -999
while (neededInteger!=-999);

}

// ========================================================
// method binarySearch (int arr[], int elem, int first, int last)  
// takes an integer array, the integer to search, postion of the   
// first element in the array and position of the last element in
// the array to search as arguments and returns no argument, but 
// displays if the element was found or not and at what position 
// it was found 
//=========================================================
void binarySearch(int arr[], int elem, int first, int last){
	// declare variable middle to hold the middle of the list
	int middle;

	// compare the value to the lowest value and the highest
	// in the already sorted array if the element to search is 
	// smaller than the smallest element or greater than the 
	// biggest element in the sorted array than the element
	// is not in the list
	if (elem<arr[first] || elem> arr[last]) {
		// display a message indicating the element wasn't found
		cout << "The integer you entered has not been found!" << endl;		
	}	

	// if the element is in between the smallest and the biggest
	// elements of the sorted list then search for it
	else {
		// find the middle value in the sorted list
		// and compare the searched element to the 
		// middle element
		middle = first + (last - first) / 2;
		// if the element is equal to the middle element in the list
		// then display that it was found and at what postion it was found 
		if (arr[middle] == elem) cout << "Element "<< elem <<" was found at position : " << first + 1 << endl;
		// if not found compare it to the middle element
		else {
			// if the searched element is smaller than 
			// the element in the middle of the list
			if (elem < arr[middle]) {
				// devide the list by making last middle-1
				// to search the lower half list where it 
				// should  be found
				last = middle - 1;  
			}
			
			else {
				//if the searched element is bigger than
				// the element in the middle of the list
				if (elem > arr[middle])
					// devide the list by making first middle+1
					// to search the uper half list where it 
					// should  be found
					first = middle + 1;
			}
			// call binary search recursively for the new half list
			// to continue searching until found or until the half
			// list is reduced to one element in which case we display
			// element not found
			binarySearch(arr, elem, first, last);
		}
	}
	
}