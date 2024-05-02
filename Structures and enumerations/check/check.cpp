
#include <iostream>
#include <string>
#include <fstream>
#include<Windows.h>


struct BankAccount            
 {
    int accountNumber;               // номер счёта
    std::string ownerName;          // имя владельца 
    double balance;                // баланс счёта

 };

 void changeBalance(BankAccount &account, double newBalance)
 {
    account.balance = newBalance;
 }

int main(int argc, char** argv)

{
    setlocale(LC_ALL, "rus");

    SetConsoleCP(1251);
   
    BankAccount account;
    std::cout << "Введите номер счёта: ";

    std::cin >> account.accountNumber;

    std::cout << "Введите имя владельца: ";

    std::cin >> account.ownerName;

    std::cout << "Введите баланс: ";

    std::cin >> account.balance;

    double newBalance;

    std::cout << "Введите новый баланс: ";

    std::cin >> newBalance;

    changeBalance(account, newBalance);

    std::cout << "Ваш счёт: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return 0;
}

/*Создайте структуру для хранения информации о банковском счёте. Она должна хранить номер счёта (целое число), имя владельца (строка) и количество денег на счету (дробное число).

Создайте функцию для изменения баланса счёта. Функция должна принимать экземпляр структуры банковского счёта и новую сумму.

Попросите пользователя заполнить поля экземпляра структуры, сообщить новый баланс счёта и выведите обновлённый экземпляр структуры на консоль.

Пример работы программы
Введите номер счёта: 123456789
Введите имя владельца: Андрей
Введите баланс: 5000
Введите новый баланс: 6000
Ваш счёт: Андрей, 123456789, 6000

Не забудьте, что для изменения экземпляра структуры внутри функции нужно передавать его по ссылке или через указатель.

Для объявления структуры используйте ключевое слово struct.

Для ввода значений с консоли используйте std::cin.

Для вывода на консоль используйте std::cout.*/