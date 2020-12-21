#include <iostream>
#include <sstream>
#include <cmath>

/*
 * Надо реализовать цифровой спидометр автомобиля. Сама модель автомобиля, которую нужно будет воссоздать весьма проста.
 * Начальная скорость - 0 км/ч. Пользователь вводит в стандартный ввод разницу (дельту) в скорости и результирующая скорость
 *  показывается на спидометре в стандартный вывод. Так происходит до той поры, пока машина снова не остановится,
 *  т.е. пока скорость не станет меньше или равна нулю (сравнение должно происходить с дельтой в 0.01).
 * Диапазон возможных значений скорости машины от 0 до 150 км/ч.
 * Сам показатель спидометра, вместе с единицами измерения, требуется записывать в отдельную строку-буфер,
 *  которая потом и будет показываться на экране. Точность отображения скорость до 0.1 км/ч.
 */

bool checkSpeed(double speed, double delta) {
    return ((speed + delta) >= 0 && (speed + delta) <= 150);
}

int main() {
    std::stringstream text;
    double speed = 0.0;
    double delta;

    do {
        std::cout << "Input speed change: ";
        std::cin >> delta;
        while (!checkSpeed(speed, delta)) {
            std::cout << "New speed out of limits. Input speed change: ";
            std::cin >> delta;
        }
        text << round((speed += delta) * 10) / 10 << "km/h ";
        std::cout << "Current speed: " << speed << "km/h" << std::endl;
    } while (speed >= 0.01);

    std::cout << text.str() << std::endl;
    std::cout << "Car stopped" << std::endl;
}
