/*
Name: Ethan dixon
Course: Csc 2400-002
Date: Sept 1st 2023
Purpose: Find the Greatest common divisor (GCD) of 2 diffrent numbers
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void Extended(int, int); // Function for Extended Euclidean Algorithm
void ConsecutiveInt (int ,int); // Function for Consecutive Integer Checking
//void MiddleSchool(int, int);

int main(){
    int m,n, hold;
    // getting values from the User 
    cout << "Hello this is a program to help you find the greatest common divisor (GCD) of two numbers of your choosing!! \n\n";
    cout << "Enter your first integer: ";
    cin>> m;
    cout << "Enter your second integer: ";
    cin >> n;

// here to flip the integers for the Extended Euclidean Algorithm
    if(n>m){
        hold=m;
        m=n;
        n=hold;
    }
    //calling the function.
    Extended(m,n);
    ConsecutiveInt(m,n);
}

void Extended(int num1, int num2){

int hold, initX=1, inity=0, lastX=0, lastY=1, Multiple, Hold1, Hold2;
Hold1=num1;
Hold2=num2;
cout << "Extended Euclids Algorithm: ";
while (num2!=0){
Multiple= num1/num2;

hold=num1;
num1=num2;
num2=hold-Multiple*num2;

hold=initX;
initX=lastX;
lastX= hold - Multiple * lastX;

hold =inity;
inity=lastY;
lastY=hold-Multiple*lastY;


}
// Output the GCD and values of x and y
   cout << "GCD ( " << Hold1 << ", " << Hold2 << ")=" << num1 << endl;
cout << "x= " << initX << " y= " << inity << endl;




}

void ConsecutiveInt(int num1, int num2){
    cout << " \nConsecutive integer checking ";
    int MinNum;
    MinNum=num2;

    while((num1%MinNum) || (num2%MinNum)){
        while(num2%MinNum){
            MinNum--;
        }
        while(num1%MinNum){
            MinNum--;
        }
    }
    if (MinNum==1){
        cout << "gcd(" << num1 << ", " << num2 << ") = Undefined" << endl;
    }
    else{
        cout << "gcd(" << num1 << ", " << num2 << ") = " << MinNum << endl;
    }
}