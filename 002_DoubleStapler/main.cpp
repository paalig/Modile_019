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

int main() {
    int integer;
    std::string strFraction;

    std::cout << "Input integer: ";
    std::cin >> integer;

    std::cout << "Input fraction: ";
    std::cin >> strFraction;
    int fraction = std::stoi(strFraction);
    int count = strFraction.size();

    while (!Check(fraction)) {
        std::cout << "Incorrect value. Try again: ";
        std::cin >> strFraction;
        fraction = std::stoi(strFraction);
        count = strFraction.size();
    }
    double result = integer;
    if (result >= 0) {
        result += fraction / pow(10, count);
    } else {
        result -= fraction / pow(10, count);
    }
    std::cout << result;
}
