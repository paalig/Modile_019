#include <iostream>
#include <sstream>
#include <cmath>

/*
 * Надо написать небольшую программу.
 * Из целой и дробной частей числа, которые в отдельности вводит пользователь
 *  надо составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки.
 * Целая часть - это та часть числа, которая находится до точки (запятой), дробная - после.
 */

//TO DO: Нет перевода 001 в .001!! Возможно, переделать на string to double

bool Check(int number) {
    return number > 0;
}

double Divider(int number) {
    int count = 0;
    while (number >= 1) {
        number /= 10;
        count++;
    }
    return pow(10, count);
}

int main() {
    std::stringstream text;
    int integer;
    int fraction;
    std::cout << "Input integer: ";
    std::cin >> integer;
    std::cout << "Input fraction: ";
    std::cin >> fraction;
    while (!Check(fraction)) {
        std::cout << "Incorrect value. Try again: ";
        std::cin >> fraction;
    }

    double result = integer;
    if (result >= 0) {
        result += fraction / Divider(fraction);
    } else {
        result -= fraction / Divider(fraction);
    }
    std::cout << result;
}
