#include <iostream>

/*
 * Надо разработать упрощённую модель умного дома для дачи.
 * Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома.
 * В доме расположен электронный “умный” щиток с автоматами.
 * Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств.
 * Первый автомат - это отключение и включение питания всего дома,
 * второй - основные розетки дома,
 * третий - свет внутри дома,
 * четвёртый - наружный свет в саду,
 * пятый - отопление в помещении,
 * шестой - отопление водопровода идущего из скважины с насосом,
 * седьмой - кондиционер в помещении.

 * Есть несколько условий по включению/отключению техники в доме и вне его.

 * Как только температура снаружи падает ниже 0, надо включить систему обогрева водопровода
 *  и отключить её, если температура снаружи поднялась выше 5 градусов.

 * Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение,
 *  то необходимо включить садовое освещение. Если движения нет или время не вечернее - света снаружи быть не должно.

 * При условии, что температура в помещении упала ниже 22 градусов, должно включится отопление.
 * Как только температура поднимается выше или равно 25-и градусам, отопление автоматически отключается.

 * Если температура в помещении поднялась до 30 градусов, включается кондиционер.
 * Как только температура становится 25 градусов - кондиционер отключается.

 * Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры для комфортного нахождения.
 * Каждый день начиная с 16:00 и до 20:00, температура цвета должна плавно изменяться с 5000K до 2700К.
 * Разумеется, это изменение должно происходить в случае, если свет сейчас включен. В 0:00 температура сбрасывается до 5000К.

 * Все события по отключению и включению устройств должны выводится в консоль явным образом.
 * Если устройство не изменило своего состояния (осталось включенным или выключенным) события генерироваться не должно!
 * Если свет в доме включен, должна отображаться текущая цветовая температура.

 * Программа выполняется следующим образом.
 * Каждый час пользователь сообщает состояние всех основных датчиков и света:
 *  температура снаружи, температура внутри, есть ли движение снаружи, включен ли свет в доме.
 * Данные параметры вводятся разом в одну строку, через пробел, а потом парсятся в переменные из строкового буфера stringstream.
 * Информация о движении выводится в формате yes/no. Включение и отключение света происходит с помощью on/off.
 * Стартовое время для симуляции умного дома - это 0:00. Требуется осуществить симуляцию на протяжении двух дней.
 */

int state = 0;
int tempOutdoor;
int tempIndoor;
int currentTime = 0;
int currentDay = 1;
int colorTemperature = 5000;
bool actionOutdoor;
bool lightIndoor;

enum Switches {
    HOUSE_INPUT = 1,
    OUTLETS = 2,
    LIGHT_INDOOR = 4,
    LIGHT_OUTDOOR = 8,
    BOILER_INDOOR = 16,
    BOILER_OUTDOOR = 32,
    CONDITIONER = 64
};

//Освещение в доме
void CheckIndoorLight() {
    if (lightIndoor && !(state & LIGHT_INDOOR)) {
        state |= LIGHT_INDOOR;
        std::cout << "Indoor light switched on." << std::endl;
    }
    if (!lightIndoor && (state & LIGHT_INDOOR)) {
        state &= ~LIGHT_INDOOR;
        std::cout << "Indoor light switched off." << std::endl;
    }
    if ((currentTime >= 16 && currentTime <= 20) && (state & LIGHT_INDOOR)) {
        colorTemperature -= 460;
    }
    if (state & LIGHT_INDOOR) {
        std::cout << "Light temperature: " << colorTemperature << "K" << std::endl;
    }
}

//Наружный свет
void CheckOutdoorLight() {
    if ((currentTime >= 16 || currentTime < 5) && actionOutdoor && !(state & LIGHT_OUTDOOR)) {
        state |= LIGHT_OUTDOOR;
        std::cout << "Outdoor light switched on." << std::endl;
    }
    if (((currentTime >= 5 && currentTime < 16) || !actionOutdoor) && (state & LIGHT_OUTDOOR)) {
        state &= ~LIGHT_OUTDOOR;
        std::cout << "Outdoor light switched off." << std::endl;
    }
}

//Отопление водопровода
void CheckOutdoorBoiler() {
    if (tempOutdoor < 0 && !(state & BOILER_OUTDOOR)) {
        state |= BOILER_OUTDOOR;
        std::cout << "Outdoor boiler switched on." << std::endl;
    }
    if (tempOutdoor > 5 && (state & BOILER_OUTDOOR)) {
        state &= ~BOILER_OUTDOOR;
        std::cout << "Outdoor boiler switched off." << std::endl;
    }
}

//Отопление в доме
void CheckIndoorBoiler() {
    if (tempIndoor < 22 &&  !(state & BOILER_INDOOR)) {
        state |= BOILER_INDOOR;
        std::cout << "Indoor boiler switched on." << std::endl;
    }
    if (tempIndoor >= 25 && (state & BOILER_INDOOR)) {
        state &= ~BOILER_INDOOR;
        std::cout << "Indoor boiler switched off." << std::endl;
    }
}

//Кондиционер
void CheckAirConditioning() {
    if (tempIndoor >= 30 &&  !(state & CONDITIONER)) {
        state |= CONDITIONER;
        std::cout << "Air conditioning switched on." << std::endl;
    }
    if (tempIndoor <= 25 && (state & CONDITIONER)) {
        state &= ~CONDITIONER;
        std::cout << "Air conditioning switched off." << std::endl;
    }
}

int main() {

    state |= HOUSE_INPUT;
    state |= OUTLETS;

    while (currentDay < 3) {

        std::cout << "Day " << currentDay << ". Current time: " << currentTime << ":00" << std::endl;

        CheckIndoorLight();
        CheckOutdoorLight();
        CheckOutdoorBoiler();
        CheckIndoorBoiler();
        CheckAirConditioning();

        if (currentTime == 0) {
            colorTemperature = 5000;
        }

        if (currentTime = 23) {
            currentTime = 0;
            currentDay++;
        } else {
            currentTime++;
        }
    }
    return 0;
}
