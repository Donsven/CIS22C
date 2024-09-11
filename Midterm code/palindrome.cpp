/*
LAB NUMBER: MIDTERM ASSIGNMENT
NAME: NELSON LEE
PURPOSE OF THIS ASSIGNMENT: CREATE A PROGRAM THAT RETURNS THE PALINDROME OF INTEGERS
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 8;

//Function to check if a number is a palindrome
bool isPalindrome(int input) {
    int original = input;
    int reversed = 0;

    if (input < 0 || input > 99999){
        return false;
    }

    while (input > 0) {
        reversed = reversed * 10 + input % 10;
        input /= 10;
    }
    return original == reversed;
}

// Function to sort an array in descending order using selection sort
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    int input;

    //Get input for Palindromes and avoid duplicates
    cout << "Please enter the numbers to be checked: ";
    while (cin >> input && input != -1) {
        if (input >= 0 && input <= 99999 && count < MAX_SIZE) {
            bool exists = false;
            for (int i = 0; i < count; i++){
                if (numbers[i] == input){ 
                    exists = true; 
                    break; 
                }
            }
            if (!exists){
                numbers[count++] = input;
            }
        }
    }
    
    //Get the count for amount of Palindromes to print
    int palindromes[MAX_SIZE];
    int palindromeCount = 0;
    for (int i = 0; i < count; i++){
        if (isPalindrome(numbers[i])){
            bool exists = false;

            for (int j = 0; j < palindromeCount; j++){
                if (palindromes[j] == numbers[i]){ 
                    exists = true; 
                    break; 
                }
            }

            if (!exists){ 
                palindromes[palindromeCount++] = numbers[i];
            }
        }
    }

    // Sort palindromes in descending order for printing
    sortDescending(palindromes, palindromeCount);

    // Print palindromes
    cout << "The Palindromes are: ";
    for (int i = 0; i < palindromeCount; i++){
        cout << palindromes[i] << " ";
    }
    cout << endl;
    
    return 0;
}
