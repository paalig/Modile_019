#include <iostream>
#include <string>

/*
 * Надо написать небольшую программу.
 * Из целой и дробной частей числа, которые в отдельности вводит пользователь
 *  надо составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки.
 * Целая часть - это та часть числа, которая находится до точки (запятой), дробная - после.
 */

int main() {
    std::string strInteger;
    std::string strFraction;

    std::cout << "Input integer: ";
    std::cin >> strInteger;

    std::cout << "Input fraction: ";
    std::cin >> strFraction;

    std::string result = strInteger + "." + strFraction;

    std::cout << "Result: " << std::stod(result) << std::endl;
}
