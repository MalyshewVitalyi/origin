#include <iostream>
#include <string>
#include <fstream>


enum Month                       /*определяем перечисление  Month */
{
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};    /*приравниваем в перечислении первый элемент( January = 1) к единице т.к. 0 будет выводить  "До свидания"*/ 


int main(int argc, char** argv)

{
    setlocale(LC_ALL, "rus");

    int monthNumber;  /*объявляем переменную monthNumber (базовый целочисленный тип)*/

    do                /*Оператор do-while позволяет повторять выполнение оператора или составного оператора до тех пор, пока указанное выражение не станет ложным
                        считываем у пользователя до тех пор, пока он не введёт 0 или ещё какую дичь не прописанную в перечислении Month  */
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> monthNumber;    /*ввод пользователем номера месяца*/

        if (monthNumber == 0)       /*если номер месяца (monthNumber) равен 0 тогда "До свидания"*/
        {
            std::cout << "До свидания" << std::endl;
            break;                 /*оператор break завершает выполнение ближайшего заключенного do for оператора или while оператора.*/
        }

        switch (static_cast<Month>(monthNumber))  /* в  множественном условном операторе меняем тип данных у переменной monthNumber с помощью static_cast .
                                                     Если кейс совпадает с выражением switch, то выполняются инструкции под соответствующим кейсом*/
        {
        case January:
            std::cout << "Январь" << std::endl;
            break;
        case February:
            std::cout << "Февраль" << std::endl;
            break;
        case March:
            std::cout << "Март" << std::endl;
            break;
        case April:
            std::cout << "Апрель" << std::endl;
            break;
        case May:
            std::cout << "Май" << std::endl;
            break;
        case June:
            std::cout << "Июнь" << std::endl;
            break;
        case July:
            std::cout << "Июль" << std::endl;
            break;
        case August:
            std::cout << "Август" << std::endl;
            break;
        case September:
            std::cout << "Сентябрь" << std::endl;
            break;
        case October:
            std::cout << "Октябрь" << std::endl;
            break;
        case November:
            std::cout << "Ноябрь" << std::endl;
            break;
        case December:
            std::cout << "Декабрь" << std::endl;
            break;
        default:
            std::cout << "Неправильный номер!" << std::endl; /* Если кейс не совпадает с выражением switch,
                                                                то вводится "Неправильный номер!"*/
            break;
        }
    } while (true);

      return 0;   //  программа закончилась
}

/*Напишите программу, которая спрашивает у пользователя номер месяца и выводит на экран название месяца, введённого пользователем.

Если пользователь ввёл некорректный номер месяца, сообщите ему об этом.

Спрашивайте пользователя до тех пор, пока он не введёт 0.

Для решения задачи воспользуйтесь перечислением.

Пример работы программы
Введите номер месяца : 1
Январь
Введите номер месяца : 7
Июль
Введите номер месяца : 13
Неправильный номер!
Введите номер месяца : 0
До свидания

Используйте перечисление для обработки пользовательского ввода.Не забудьте привести пользовательский ввод к типу перечисления с помощью static_cast.

Обрабатывайте пользовательский ввод с помощью switch case.

Для ввода значений с консоли используйте std::cin.

Для вывода на консоль используйте std::cout.*/
