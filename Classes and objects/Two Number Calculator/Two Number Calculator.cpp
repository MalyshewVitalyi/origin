#include <iostream>
#include <string>
#include<Windows.h>

class Calculator {                            //класс Calculator
public:
    double num1;
    double num2;                               //два поля num1 и num2 для хранения дробных чисел 
public:                                       //методы 
    double add() {
        return num1 + num2;
    }
    double multiply() {
        return num1 * num2;
    }
    double subtract_1_2() {
        return num1 - num2;                             
    }
    double subtract_2_1() {
        return num2 - num1;
    }
    double divide_1_2() {
        return num1 / num2;  
    }
    double divide_2_1()
    {
        return num2 / num1;
    }

    bool set_num1(double num) 
    {
        if (num != 0) {
            this->num1 = num;          //this для обращения к полям num1 и num2
            return true;
        }
        return false;
    }

    bool set_num2(double num) 
    {
        if (num != 0) 
        {
            this->num2 = num;
            return true;
        }
        return false;
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    SetConsoleCP(1251);

    Calculator calc;
    double num1, num2;

    while (true) 
    {
        std::cout << "Введите num1: ";                        //просим ввести два числа
        std::cin >> num1;
        std::cout << "Введите num2: ";
        std::cin >> num2;

        if (calc.set_num1(num1) && calc.set_num2(num2))          /*условное выражение, которое используется для проверки
                                          успешной установки значений num1 и num2 в экземпляр класса Calculator `calc`*/
        {
            std::cout << "num1 + num2 = " << calc.add() << std::endl;
            std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
            std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
            std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
            std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
            std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
        }
        else 
        {
            std::cout << "Неверный ввод!" << std::endl;
        }
    }
    return 0;
}

/*В этом задании вам нужно будет создать класс, выполняющий простые арифметические операции для двух чисел, и продемонстрировать его работу

Создайте класс Calculator. Класс должен содержать два поля num1 и num2 для хранения дробных чисел. Также класс должен содержать следующие методы:

double add() - метод должен возвращать результат сложения num1 и num2
double multiply() - метод должен возвращать результат перемножения num1 и num2
double subtract_1_2() - метод должен возвращать результат вычитания num2 из num1
double subtract_2_1() - метод должен возвращать результат вычитания num1 из num2
double divide_1_2() - метод должен возвращать результат деления num1 на num2
double divide_2_1() - метод должен возвращать результат деления num2 на num1
bool set_num1(double num1) - метод должен установить значение поля num1 равное значению аргумента num1 в случае,
если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
bool set_num2(double num2) - метод должен установить значение поля num2 равное значению аргумента num2 в случае,
если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
Напишите код, демонстрирующий работу класса Calculator. Попросите пользователя ввести два числа.
После этого выведите пользователю результаты всех операций или попросите его ввести значение ещё раз, если предыдущий ввод был некорректен

Программа спрашивает пользователя бесконечно, пока он сам не закроет консоль

Пример работы программы
Консоль
Введите num1: 3
Введите num2: 6
num1 + num2 = 9
num1 - num2 = -3
num2 - num1 = 3
num1 * num2 = 18
num1 / num2 = 0.5
num2 / num1 = 2
Введите num1: 5
Введите num2: 0
Неверный ввод!
Введите num2: 5
num1 + num2 = 10
num1 - num2 = 0
num2 - num1 = 0
num1 * num2 = 25
num1 / num2 = 1
num2 / num1 = 1

Подумайте, какой должен быть тип у полей num1 и num2

Чтобы создать экземпляр класса Calculator, напишите Calculator <имя переменной>;

В методах set_num1 и set_num2 потребуется условный оператор и ключевое слово this

Для вывода на консоль используйте std::cout

Для ввода с консоли используйте std::cin*/