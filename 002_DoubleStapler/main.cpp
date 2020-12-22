#include <iostream>
#include <cmath>
#include <string>

/*
 * Надо написать небольшую программу.
 * Из целой и дробной частей числа, которые в отдельности вводит пользователь
 *  надо составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки.
 * Целая часть - это та часть числа, которая находится до точки (запятой), дробная - после.
 */

bool Check(int number) {
    return number > 0;
}

int CountZero(std::string str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int CountSymbol(int number, int count) {
    while (number >= 1) {
        number /= 10;
        count++;
    }
    return count;
}

int main() {
    std::string strInteger;
    std::string strFraction;

    std::cout << "Input integer: ";
    std::cin >> strInteger;
    int integer = std::stoi(strInteger);

    std::cout << "Input fraction: ";
    std::cin >> strFraction;
    int countDivider = CountZero(strFraction);
    int fraction = std::stoi(strFraction);
    countDivider = CountSymbol(fraction, countDivider);

    while (!Check(fraction)) {
        std::cout << "Incorrect value. Try again: ";
        std::cin >> strFraction;
        countDivider = CountZero(strFraction);
        fraction = std::stoi(strFraction);
        countDivider = CountSymbol(fraction, countDivider);
    }

    double result = integer;
    if (result >= 0) {
        result += fraction / pow(10, countDivider);
    } else {
        result -= fraction / pow(10, countDivider);
    }
    std::cout << result;
}
