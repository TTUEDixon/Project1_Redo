/*
Name: Ethan dixon
Course: Csc 2400-002
Date: OCT 7th 2023
Purpose: Find the Greatest common divisor (GCD) of 2 diffrent numbers
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib> // for abs
using namespace std;

void Extended(int, int);
void ConsecutiveInt(int, int);

int main() {
    int m, n, hold;
    // welcome prompt/gathering user inputs

    cout << "Hello! This is a program to help you find the greatest common divisor (GCD) of two numbers of your choosing.\n\n";
    cout << "Enter your first integer: ";
    cin >> m;
    cout << "Enter your second integer: ";
    cin >> n;
    // runs the functions
    if (m == 0 && n == 0) {
        cout << "The GCD of 0 and 0 is undefined." << endl;
    } else {
        // Ensure that m and n are positive
        m = abs(m);
        n = abs(n);

        // makes sure that the 2nd number isnt larger than the 1st number
        if (n > m) {
            hold = m;
            m = n;
            n = hold;
        }
        // Runs the functions
        Extended(m, n);
        ConsecutiveInt(m, n);
    }
}

//Name: Extended 
// Parameter: Int num1 and int num2 
// Purpose: Finds the GCD of 2 numbers using the extended elcuids method
void Extended(int num1, int num2) {
    int hold, initX = 1, inity = 0, lastX = 0, lastY = 1, Multiple, Hold1, Hold2;
    Hold1 = num1;
    Hold2 = num2;
    cout << "Extended Euclidean Algorithm: ";
    
    while (num2 != 0) {
        Multiple = num1 / num2;
        hold = num1;
        num1 = num2;
        num2 = hold - Multiple * num2;

        hold = initX;
        initX = lastX;
        lastX = hold - Multiple * lastX;

        hold = inity;
        inity = lastY;
        lastY = hold - Multiple * lastY;
    }
// OutPut
    if (num1 == 0) {
        cout << "GCD(" << Hold1 << ", " << Hold2 << ") = Undefined" << endl;
        cout << "x = " << initX << ", y = " << inity << endl;
    }
    else {
        cout << "GCD(" << Hold1 << ", " << Hold2 << ") = " << num1 << endl;
        cout << "x = " << initX << ", y = " << inity << endl;
    }
}
// Name: ConsecutiveInt
// Parameters: Int num1, Int num2
// Purpose: Finds the GCD by using the consecutive interger algorithm
void ConsecutiveInt(int num1, int num2) {
   cout << "\nConsecutive Integer Checking: ";
    // knocks out situations when the user inputs 0 as one of their numbers
    if (num1 == 0) {
        cout << "GCD(" << num1 << ", " << num2 << ") = " << abs(num2) << endl;
    } 
    else if (num2 == 0) {
        cout << "GCD(" << num1 << ", " << num2 << ") = " << abs(num1) << endl;
    } 
    else {
        int MinNum = num2;
        // runs the Consecutive Intergeralgorithm
        while (num1 % MinNum || num2 % MinNum) {
            while (num2 % MinNum) {
                MinNum--;
            }
            while (num1 % MinNum) {
                MinNum--;
            }
        }
        // Output
          if (MinNum == 1) {
            cout << "GCD(" << num1 << ", " << num2 << ") = Undefined" << endl;
        }
        else {
            cout << "GCD(" << num1 << ", " << num2 << ") = " << MinNum << endl;
        }
    }
}






