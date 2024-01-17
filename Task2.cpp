// Task 2 :

// Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. Allow the user to input two numbers
//and choose an operation to perform.

#include<iostream>
#include<cmath>
using namespace std ;

int main()
{
    double a;
    double b;

    cout << "What is the value of the First Number ? \n";
    cin >> a ;

    cout << "What is the value of the Second Number ? \n";
    cin >> b ;

    char oper ;

    cout << "Enter the Operation you want to Perform :( + , - , * , / , % ) \n" ;
    cin >> oper ;

    switch(oper)
    {
        case '+' :
        cout << "Sum is : " << a + b << endl ;
        break;

        case '-' :
        cout << "Difference is : " << a - b << endl ;
        break;

        case '*' :
        cout << "Product is : " << a * b << endl ;
        break;

        case '/' :
        cout << "After Dividing , result is : " << a / b << endl ;
        break;

        default :
        cout << "Invalid Operator Entered ! Retry ! \n" ;
        break;
    }


    return 0 ;
}