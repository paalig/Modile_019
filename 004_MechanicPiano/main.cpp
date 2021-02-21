#include <iostream>
#include <string>
#include <sstream>

/*
 * Создать упрощённую модель механического пианино. Всего у данного пианино - 7 клавиш, соответствуют они семи нотам.
 * Каждая клавиша кодируется уникальной битовой маской, которая записывается в enum.
 * Вначале программы пользователь вводит мелодию.
 * Ввод осуществляется с помощью цифр на клавиатуре, от 1 до 7 включительно (от ноты “до” до ноты “си”).
 * В результате из чисел может быть составлена любая комбинация нот. К примеру 512 или 154.
 * После ввода комбинации, вводится следующая. Всего таких комбинаций нот - 12.
 * Как только все комбинации были введены пользователем, мелодия проигрывается.
 * Для этого каждая комбинация нот последовательно выводится на экран.
 * Однако, на этот раз она печатается “красиво”, т.е. все ноты указываются словами, а не цифрами.
 * При этом слова разделяются пробелами.
 *
 * Советы и рекомендации
 * Для вычленения отдельных символов-цифр из строки с нотами используйте оператор индексации строки.
 * Для дальнейшей конвертации символа в строку используйте соответствующий конструктор.
 * Для простоты, чтобы из индекса ноты получить саму ноту-флаг из enum, используйте оператор сдвига.
 * Общая формула такова: 1 << индекс ноты (начинается с нуля).
 * К примеру 1 << 0 - битовый флаг ноты до, 1 << 6 битовая маска ноты си.
 */

bool CheckCombination(std::string str) {
    if (str.size() != 3) {
        return false;
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < '1' || str[i] > '7') {
            return false;
        }
    }
    return true;
}

enum Keys {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    TI = 64
};

std::string PrintKeys(int key) {
    if (key & DO) {
        return "DO ";
    } else if (key & RE) {
        return "RE ";
    } else if (key & MI) {
        return "MI ";
    } else if (key & FA) {
        return "FA ";
    } else if (key & SOL) {
        return "SOL ";
    } else if (key & LA) {
        return "LA ";
    } else {
        return "TI ";
    }
}

void PrintMelody(int arr[12][3]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << PrintKeys(arr[i][j]);
        }
        std::cout << std::endl;
    }
}

int main() {
    int array[12][3];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = 0;
        }
    }
    std::string combination;
    for (int i = 0; i < 12; i++) {
        std::cout << "Enter " << i + 1 << " combination: ";
        std::cin >> combination;
        while (!CheckCombination(combination)) {
            std::cout << "Wrong input. Enter " << i + 1 << " combination: ";
            std::cin >> combination;
        }
        for (int j = 0; j < 3; j++) {
            int index = combination[j] - '1';
            array[i][j] |= 1 << index;
        }
    }
    PrintMelody(array);
}
