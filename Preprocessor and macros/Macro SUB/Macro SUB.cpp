#include <iostream>

#define SUB(x, y) ((x) - (y))

int main(int argc, char** argv)
{
    int a = 6;
    int b = 5;
    int c = 2;
    std::cout << SUB(a, b) << std::endl;
    std::cout << SUB(a, b) * c << std::endl;
    std::cout << SUB(a, b + c) * c << std::endl;

    return 0;
}
/*В этом задании вы создадите простой макрос.
Ваша задача — определить макрос SUB, 
который должен вычитать числа друг из друга и использовать следующим образом:

int main (int argc, char** argv)
{
	int a = 6;
	int b = 5;
	int c = 2;
	std::cout << SUB(a, b) << std::endl;
	std::cout << SUB(a, b) * c << std::endl;
	std::cout << SUB(a, b + c) * c << std::endl;
}
Программа должна вывести результат, указанный ниже:

Пример работы программы
Консоль
1
2
-2
Что использовать для решений.
Для определения макроса воспользуйтесь директивой #define.

Для получения результата не забудьте взять макрос и его аргументы в скобках.*/