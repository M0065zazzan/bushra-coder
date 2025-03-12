#include <iostream>
#include <cmath>    // For sqrt() and pow()
#include <limits>   // For std::numeric_limits

using namespace std;

// Function prototypes for operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double exponentiate(double a, double b);
double modulus(double a, double b);
double squareRoot(double a);

int main() {
    double num1, num2;
    char operation;
    char continueCalculation;

    do {
        // Ask for the first number and validate input
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        }

        // Ask for the operator
        cout << "Enter an operator (+, -, *, /, ^ for power, % for modulus, r for square root): ";
        cin >> operation;

        // For square root, we only need one number
        if (operation == 'r') {
            cout << "Enter the number: ";
            while (!(cin >> num1)) {
                cout << "Invalid input. Please enter a valid number: ";
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            }
            cout << "Result: " << squareRoot(num1) << endl;
        } else {
            // Ask for the second number and validate input
            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cout << "Invalid input. Please enter a valid number: ";
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            }

            // Perform the operation based on the operator
            switch(operation) {
                case '+':
                    cout << "Result: " << add(num1, num2) << endl;
                    break;
                case '-':
                    cout << "Result: " << subtract(num1, num2) << endl;
                    break;
                case '*':
                    cout << "Result: " << multiply(num1, num2) << endl;
                    break;
                case '/':
                    if (num2 != 0)
                        cout << "Result: " << divide(num1, num2) << endl;
                    else
                        cout << "Error! Division by zero is not allowed." << endl;
                    break;
                case '^':
                    cout << "Result: " << exponentiate(num1, num2) << endl;
                    break;
                case '%':
                    if (num2 != 0)
                        cout << "Result: " << modulus(num1, num2) << endl;
                    else
                        cout << "Error! Modulus by zero is not allowed." << endl;
                    break;
                default:
                    cout << "Invalid operator! Please use one of the following: +, -, *, /, ^, %, r" << endl;
            }
        }

        // Ask if the user wants to continue
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;

    } while (continueCalculation == 'y' || continueCalculation == 'Y');
    
    cout << "Thank you for using the calculator!" << endl;
    return 0;
}

// Function definitions for operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double exponentiate(double a, double b) {
    return pow(a, b);
}

double modulus(double a, double b) {
    return fmod(a, b); // fmod() for floating-point modulus
}

double squareRoot(double a) {
    if (a < 0) {
        cout << "Error! Square root of a negative number is not allowed." << endl;
        return -1; // Indicating an error
    }
    return sqrt(a);
}
