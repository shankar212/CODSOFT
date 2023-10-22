#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "Calculator" << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation ( + , - , * , / ): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "The sum of " << num1 << " and " << num2 << " is " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "The difference between " << num1 << " and " << num2 << " is " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "The product of " << num1 << " and " << num2 << " is " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "The division of " << num1 << " by " << num2 << " is " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            break;
    }

    return 0;
}
