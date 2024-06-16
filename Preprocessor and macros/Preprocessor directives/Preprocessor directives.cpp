#include <iostream>
#include <string>
#include <fstream>

#define MODE 1

#ifdef MODE
#if MODE == 0

#elif MODE == 1
int add(int num1, int num2) 
{
    return num1 + num2;
}

int main(int argc, char** argv)

{
    setlocale(LC_ALL, "rus");
    std::cout << "Работаю в боевом режиме" << std::endl;
    int num1, num2;
    std::cout << "Введите число 1: ";
    std::cin >> num1;
    std::cout << "Введите число 2: ";
    std::cin >> num2;
    std::cout << "Результат сложения: " << add(num1, num2) << std::endl;
    return 0;
}
#else
int main() 
{
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
    return 0;
}
#endif
#else

#endif

