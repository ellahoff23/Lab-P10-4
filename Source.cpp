#include <iostream>
#include <cctype>

bool isCardValid(int digits[], int size) {
    int sumStep1 = 0, sumStep2 = 0;

    for (int i = size - 1; i >= 0; i -= 2) {
        sumStep1 += digits[i];
    }

    for (int i = size - 2; i >= 0; i -= 2) {
        int doubled = digits[i] * 2;
        sumStep2 += (doubled % 10) + (doubled / 10);
    }

    int totalSum = sumStep1 + sumStep2;

    return (totalSum % 10 == 0);
}

int main() {
    const int SIZE = 8;
    int digits[SIZE];
    char input[SIZE + 1];

    while (true) {
        std::cout << "Enter 8-digit credit card # or Q to quit: ";
        std::cin.getline(input, SIZE + 1);

        if (toupper(input[0]) == 'Q')
            break;

        bool validInput = true;
        for (int i = 0; i < SIZE; i++) {
            if (!isdigit(input[i])) {
                validInput = false;
                break;
            }
            digits[i] = input[i] - '0';
        }

        if (validInput) {
            bool isValid = isCardValid(digits, SIZE);
            if (isValid)
                std::cout << "Card is valid." << std::endl;
            else
                std::cout << "Card is not valid." << std::endl;
        }
        else {
            std::cout << "Invalid input. Please enter a valid 8-digit number." << std::endl;
        }
    }

    return 0;
}