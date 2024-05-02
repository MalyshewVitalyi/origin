#include <iostream>
#include <string>
#include<Windows.h>

    struct Address 
    {
        std::string city;
        std::string street;
        int houseNumber;
        int apartmentNumber;
        std::string zipCode;
    };

    void printAddress(const Address & addr) 
    {
        std::cout << "Город: " << addr.city << std::endl;
        std::cout << "Улица: " << addr.street << std::endl;
        std::cout << "Номер дома: " << addr.houseNumber << std::endl;
        std::cout << "Номер квартиры: " << addr.apartmentNumber << std::endl;
        std::cout << "Индекс: " << addr.zipCode << std::endl;
    }

    int main(int argc, char** argv) 
    {
        setlocale(LC_ALL, "rus");

        SetConsoleCP(1251);


        Address addr1, addr2;
        std::cout << " Введите город: ";
        std::cin >> addr1.city;
        std::cout << " Введите улицу: ";
        std::cin >> addr1.street;
        std::cout << " Введите номер дома: ";
        std::cin >> addr1.houseNumber;
        std::cout << " Введите номер квартиры: ";
        std::cin >> addr1.apartmentNumber;
        std::cout << " Введите индекс: ";
        std::cin >> addr1.zipCode;

        printAddress(addr1);

        return 0;
    }

/*Создайте структуру для хранения адреса. Структура должна содержать название города, улицы, номер дома, номер квартиры и индекс.

Создайте функцию для вывода структуры на консоль.

Протестируйте созданную функцию. Создайте в коде экземпляры структуры, передайте их в функцию и выведите на консоль получившиеся экземпляры структуры.

Пример работы программы
Город: Москва
Улица: Арбат
Номер дома: 12
Номер квартиры: 8
Индекс: 123456

Город: Ижевск
Улица: Пушкина
Номер дома: 59
Номер квартиры: 143
Индекс: 953769

Структура объявляется вне функций.

Чтобы создать экземпляр структуры, нужно указать её тип.

Для доступа к полям структуры используйте оператор ..

Для ввода значений с консоли используйте std::cin.

Для вывода на консоль используйте std::cout.*/