#include <iostream>
using namespace std;

class BasicCalculator {
private:
    BasicCalculator() {} // Private constructor to prevent instantiation

public:
    // Static method for addition
    static double performAddition(double operand1, double operand2) {
        return operand1 + operand2;
    }

    // Static method for subtraction
    static double performSubtraction(double operand1, double operand2) {
        return operand1 - operand2;
    }

    // Static method for multiplication
    static double performMultiplication(double operand1, double operand2) {
        return operand1 * operand2;
    }

    // Static method for division
    static double performDivision(double operand1, double operand2) {
        if (operand2 != 0) {
            return operand1 / operand2;
        } else {
            cout << "Error! Division by zero is not allowed." << endl;
            return 0;
        }
    }
};

int main(int argc, char** argv) {
    int selectedOperation;
    double number1, number2;

    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;

    cout << "1: +, 2: -, 3: *, 4: /" << endl;
    cout << "Select Operation: ";
    cin >> selectedOperation;

    switch (selectedOperation) {
        case 1:
            cout << "The addition of numbers is: " << BasicCalculator::performAddition(number1, number2);
            break;
        case 2:
            cout << "The subtraction of numbers is: " << BasicCalculator::performSubtraction(number1, number2);
            break;
        case 3:
            cout << "The multiplication of numbers is: " << BasicCalculator::performMultiplication(number1, number2);
            break;
        case 4:
            cout << "The division of numbers is: " << BasicCalculator::performDivision(number1, number2);
            break;
        default:
            cout << "Invalid Input!" << endl;
            break;
    }

    return 0;
}
