#include <iostream>
#include <fstream>
#include <string>

class address                     
{
 private:
	std::string city;
	std::string street;           
	int house_number;
	int flat_number;              
 public:
	address(std::string c, std::string s, int h, int f) : city(c), street(s), house_number(h), flat_number(f) {}

	std::string get_output_address() 
	{
		return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(flat_number);
	}
};

int main(int argc, char** argv) 
{
	std::ifstream input_file("in.txt");
	std::ofstream output_file("out.txt");

	int N;
	input_file >> N;

	address** addresses = new address * [N];

	for (int i = 0; i < N; i++) 
	{
		std::string city, street;
		int house_number, flat_number;

		input_file >> city >> street >> house_number >> flat_number;
		addresses[i] = new address(city, street, house_number, flat_number);
	}

	output_file << N << std::endl;

	for (int i = N - 1; i >= 0; i--)
	{
		output_file << addresses[i]->get_output_address() << std::endl;
	}

	return 0;
}
/*В этом задании вы будете читать адреса из файла и выводить их в другой файл в другом формате.

Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле.
После числа N располагаются N блоков по 4 строки в каждом. Каждый блок состоит из следующих строк: 
название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt 
и вывести их в файл out.txt в другом формате и в обратном порядке.

Не забудьте вывести количество адресов в начале.

Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.

Пример работы программы
in.txt
3
Москва
Строителей
34
12
Омск
Пушкина
2
13
Новосибирск
Мира
85
64
out.txt
3
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
Москва, Строителей, 34, 12

Для хранения адреса создайте класс, например address. 
В нём будут поля для хранения названий города и улицы (std::string), а также номеров дома и квартиры (int).

Создайте в вашем классе конструктор с параметрами, чтобы нельзя было создать пустой адрес.

Создайте в вашем классе метод, который собирает строку для вывода в файл. 
Можно назвать его, например get_output_address. Метод будет возвращать значение типа std::string.

Не забудьте сделать ваши поля приватными. 
Так инкапсуляция вашего класса станет лучше, потому что будет меньше потенциальных связей с внешним кодом.

Для хранения всех адресов, экземпляров вашего класса, заведите динамический массив типа address*.

Для считывания адресов используйте цикл for.

Для работы с файлом в режиме чтения используйте класс std::ifstream.

Для работы с файлом в режиме записи используйте класс std::ofstream.*/