
/*
All code files to be submitted as part of the submission should have a name block at the top.
The name block should clearly indicate
the Lab Number,
the name of the person, and
a one line statement explaining the purpose of the assignment.
Your code files should also include
pre/post headers as discussed in the documentation guidelines in the first week of class, and
have a comment block of pseudocode as necessary just before the relevant section of the code.
Remember - pseudocode is not the same as inline comments or comments all over the code.
Remember to include a 'pause' of some type before your program exits to allow me to observe the console output when I compile and run your program.
Run your program in the console with the following inputs:
NumInts = 5, Ints = 53 5099 1223 567 17
NumInts = 4, Ints = 1871 8069 3581 6841
Remember to take multiple screenshots of the both the runs so that they are clearly readable without needing to zoom in.
For documentation, include your name block as well pre/post and pseudocode for the 3 functions which are not 'main'. For pre/post documentation and pseudocode examples,
 

Things to remember:

Only submissions in ZIP file format will be accepted - no gzip, 7z, tar, rar or any other file format.
Not including the name block will result in a 10% penalty.
Not including screenshots will result in a 10% penalty.
Not including pseudocode where necessary will result in a 20% penalty.
Not including pre/post headers will result in a 20% penalty.
*/

/*
LAB NUMBER: LAB 1
NAME: NELSON LEE, CHRISTINA VO
PURPOSE OF THIS ASSIGNMENT:  DEMONSTRATING THE DIFFERENCE BETWEEN ITERATION AND RECURSION BY CHECKING IF ALL ELEMENTS OF AN ARRAY ARE PRIME.
*/



#include <iostream>
#include <cmath>
using namespace std;

/*
PSEDUOCODE:
Pre: arr -- a non-empty array of integer numbers
        size -- the number of elements inside 'arr'
Post:
Return: true or false
*/

bool IsArrayPrimeIter(int arr[], int size) {
    bool isPrime = true;
    cout << "Entering IsArrayPrimeIter" << endl;
    for (int i = 0; i < size; i++) {
        for (int h = 2; h <= sqrt(arr[i]); h++) {
            if (arr[i] % h == 0) {
                isPrime = false;
            }
        }
    }
    cout << "Leaving IsArrayPrimeIter" << endl;
    return isPrime;
}

/*
PSEDUOCODE:
Pre: num -- an integer used to check if a number is prime
         divisor -- an integer used to check if a number can be divisible
Post:
Return: true or false
*/

bool IsPrimeRecur(int num, int divisor) {
    cout << "Entering IsPrimeRecur" << endl;
    if (num <= 1) {
        cout << "Leaving IsPrimeRecur" << endl;
        return false;
    }
    if (divisor == 1) {
        cout << "Leaving IsPrimeRecur" << endl;
        return true;
    }
    if (num % divisor == 0) {
        cout << "Leaving IsPrimeRecur" << endl;
        return false;
    }
    bool result = IsPrimeRecur(num, divisor - 1);
    cout << "Leaving IsPrimeRecur" << endl;
    return result;
}

/*
PSEDUOCODE:
Pre:    arr -- a non-empty array of integer numbers
        size -- the number of elements inside 'arr'
Post:
Return: true or false

*/

bool IsArrayPrimeRecur(int arr[], int size) {
    cout << "Entering IsArrayPrimeRecur" << endl;
    if (size == 0) {
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return true;
    }
    if (!IsPrimeRecur(arr[size - 1], arr[size - 1] - 1)) {
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return false;
    }
    bool result = IsArrayPrimeRecur(arr, size - 1);
    cout << "Leaving IsArrayPrimeRecur" << endl;
    return result;
}



int main() {
    const int SORT_MAX_SIZE = 16;
    int numInts;
    cout << "Enter the number of elements in the array: ";
    cin >> numInts;

    if(numInts < 1){
        cout << "Invalid array size entered, please try again";
        return 0;
    }

    if (numInts > SORT_MAX_SIZE) {
        numInts = SORT_MAX_SIZE;
    }
    
    int arr[SORT_MAX_SIZE];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < numInts; i++) {
        cin >> arr[i];
    }

    if (IsArrayPrimeIter(arr, numInts)) {
        cout << "Prime Array using iteration" << endl;
    } else {
        cout << "Not a Prime Array using iteration" << endl;
    }

    if (IsArrayPrimeRecur(arr, numInts)) {
        cout << "Prime Array using recursion" << endl;
    } else {
        cout << "Not a Prime Array using recursion" << endl;
    }

    return 0;
}