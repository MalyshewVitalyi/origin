#include <iostream>
#include <string>
#include<Windows.h>


class bad_length {};

int function(std::string str, int forbidden_length) 
{
	int length = str.length();
	if (length == forbidden_length) 
	{
		throw bad_length();
	}
	return length;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	SetConsoleCP(1251);

	int forbidden_length;

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	std::string input;

	try {
		while (true)
		{
			std::cout << "Введите слово: ";
			std::cin >> input;

			int length = function(input, forbidden_length);
			std::cout << "Длина слова \" " << input << "\" равна " << length << std::endl;
		}
	}
	catch (bad_length) 
	{
		std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
	}

	return 0;
}
/*В этом задании вы попробуете выбросить и обработать исключение.

Создайте функцию int function(std::string str, int forbidden_length).
Эта функция должна возвращать длину переданной строки,
если эта длина не равна значению переданного параметра forbidden_length. 
В противном случае она должна выбрасывать исключение bad_length.

Для проверки функции организуйте работу с пользователем. 
В начале задайте запретную длину, а затем считывайте пользовательские строки и выводите их длину до тех пор, 
пока пользователь не введёт строку запретной длины. После этого сообщите ему, что он ввёл строку запретной длины, 
и завершите программу.

Пример работы программы
Консоль
Введите запретную длину: 5
Введите слово: Привет
Длина слова "Привет" равна 6
Введите слово: мир
Длина слова "мир" равна 3
Введите слово: пирог
Вы ввели слово запретной длины! До свидания

Что использовать для решения.
Для вычисления длины строки используйте метод класса std::string — length.

Для создания исключения используйте ключевое слово throw.

Для ожидания исключения используйте ключевое слово try.

Для обработки исключения используйте ключевое слово catch.*/