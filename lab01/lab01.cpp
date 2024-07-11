
/*
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
function IsArrayPrimeIter(arr[], size)
    isPrime = true
    print "Entering IsArrayPrimeIter"

    for i = 0 to size -1
        for h = 2 to square root of arr[i]
            if arr[i] mod h == 0
                isPrime = false
            end if
        end for
    end for

    print "Leaving IsArrayPrimeIter"
    return isPrime
end function

Pre: arr -- a non-empty array of integer numbers
        size -- the number of elements inside 'arr'
Post:
Return: true or false
*/

bool IsArrayPrimeIter(int arr[], int size) {
    bool isPrime = true;
    cout << "Entering IsArrayPrimeIter" << endl;
    for (int i = 0; i < size; i++) {
        if(arr[i] <= 1){
            isPrime = false;
            break;
        }
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
function IsPrimeRecur (num, divisor)
    print "Entering IsPrimeRecur"

    if num <= 1
        return false
    if divisor == 1
        return true
    if num mod divisor returns 0
        return false
    result = IsPrimeRecur(num, divisor - 1)
    print "Leaving IsPrimeRecur"
    return result

end function

Pre:    num -- an integer used to check if a number is prime
        divisor -- an integer used to check if a number can be divisible
Post:
Return: true or false
*/

bool IsPrimeRecur(int num, int divisor) {
    cout << "Entering IsPrimeRecur" << endl;
    if (num <= 1) {
        return false;
    }
    if (divisor == 1) {
        return true;
    }
    if (num % divisor == 0) {
        return false;
    }
    bool result = IsPrimeRecur(num, divisor - 1);
    cout << "Leaving IsPrimeRecur" << endl;
    return result;
}

/*
function IsArrayPrimeRecur(arr, size)
    print "Entering IsArrayPrimeRecur"

    if size == 0
        return true
    end if

    if not IsPrimeRecur(arr[size - 1], arr[size - 1] -1)
        return false
    end if

    result = IsArrayPrimeRecur(arr, size -1)
    print "Leaving IsArrayPrimeRecur"
    return result
end function

Pre:    arr -- a non-empty array of integer numbers
        size -- the number of elements inside 'arr'
Post:
Return: true or false

*/

bool IsArrayPrimeRecur(int arr[], int size) {
    cout << "Entering IsArrayPrimeRecur" << endl;
    if (size == 0) {
        return true;
    }
    if (!IsPrimeRecur(arr[size - 1], arr[size - 1] - 1)) {
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

    cout << "------------------------------------";
    cout << endl;

    if (IsArrayPrimeIter(arr, numInts)) {
        cout << "Prime Array using iteration" << endl;
        cout << "------------------------------------";
        cout << endl;
    } else {
        cout << "Not a Prime Array using iteration" << endl;
        cout << "------------------------------------";
        cout << endl;

    }

    if (IsArrayPrimeRecur(arr, numInts)) {
        cout << "Prime Array using recursion" << endl;
        cout << "------------------------------------";
        cout << endl;

    } else {
        cout << "Not a Prime Array using recursion" << endl;
        cout << "------------------------------------";
        cout << endl;

    }

    char finished;
    while(finished != 'y'){
        cout << "Have you finished observing the output? (y/n): ";
        cin >> finished;
    }
    return 0;
}