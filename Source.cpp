#include <iostream>
#include <string>
#include <cctype>

bool isNumeric(const std::string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isCorrectLength(const std::string& s) {
    return (s.length() == 16);
}

bool isCardValid(const std::string& cardNumber) {
    int sumStep1 = 0, sumStep2 = 0;

    for (int i = cardNumber.length() - 1; i >= 0; i -= 2) {
        sumStep1 += cardNumber[i] - '0';
    }

    for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
        int doubled = (cardNumber[i] - '0') * 2;
        sumStep2 += (doubled % 10) + (doubled / 10);
    }

    int totalSum = sumStep1 + sumStep2;

    return (totalSum % 10 == 0);
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter 16-digit credit card # or Q to quit: ";
        std::getline(std::cin, input);

        if (input.size() == 1 && toupper(input[0]) == 'Q')
            break;

        if (!isNumeric(input)) {
            std::cout << "Error - card number must contain only digits." << std::endl;
            continue;
        }

        if (!isCorrectLength(input)) {
            std::cout << "Error - card number must contain 16 digits." << std::endl;
            continue;
        }

        if (isCardValid(input))
            std::cout << "Card is valid." << std::endl;
        else
            std::cout << "Card is not valid." << std::endl;
    }

    return 0;
}