#include <iostream>
#include <sstream>

/*
 * Требуется создать небольшую программу для вычисления простых действий с числами.
 * При запуске программа ожидает пользовательского ввода во временную переменную строку.
 * После ввода строки, она распарсивается на отдельные члены.
 * Строка записывается в форме “<число-1><действие><число-2>” (без пробелов).
 * Оба числа - это значения с плавающей точкой, повышенной точности (double).
 * Действие может быть одним из: +, -, /, *. Результат действия выводится в стандартный вывод.
 */

int main() {
    std::stringstream text;
    std::string input;
    double number1;
    double number2;
    char action;

    std::cout << "Input calculation:";
    std::cin >> input;
    text << input;
    text >> number1 >> action >> number2;

    if (action == '+') {
        std::cout << number1 + number2 << std::endl;
    } else if (action == '-') {
        std::cout << number1 - number2 << std::endl;
    } else if (action == '*') {
        std::cout << number1 * number2 << std::endl;
    } else if (action == '/') {
        std::cout << number1 / number2 << std::endl;
    } else {
        std::cout << "Wrong input" << std::endl;
    }
}
