#include <iostream>
#include <string>
#include <Windows.h>

class Figure
{
public:
	virtual void print_info() = 0;
};

class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C) {}

	void print_info() override
	{
		std::cout << "Треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	}
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b) : Triangle(a, b, sqrt(a* a + b * b), atan((double)a / b), atan((double)b / a), 90) {}

	void print_info() override
	{
		std::cout << "Прямоугольный треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

	void print_info() override
	{
		std::cout << "Равносторонний треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	}
};

class Quadrilateral : public Figure
{
protected:
	int a, b, c, d;
public:
	Quadrilateral(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}

	void print_info() override
	{
		std::cout << "Четырёхугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	}
};

class Rectangle : public Quadrilateral
{
public:
	Rectangle(int a, int b) : Quadrilateral(a, b, a, b) {}

	void print_info() override
	{
		std::cout << "Прямоугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	}
};

class Square : public Quadrilateral
{
public:
	Square(int a) : Quadrilateral(a, a, a, a) {}

	void print_info() override
	{
		std::cout << "Квадрат:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	int angleA, angleB;
public:
	Parallelogram(int a, int b, int angleA, int angleB) : Quadrilateral(a, b, a, b), angleA(angleA), angleB(angleB) {}

	void print_info() override
	{
		std::cout << "Параллелограмм:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: A=" << angleA << " B=" << angleB << " C=" << 180 - angleA << " D=" << 180 - angleB << std::endl;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(int a, int angle) : Parallelogram(a, a, angle, 180 - angle) {}

	void print_info() override
	{
		std::cout << "Ромб:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: A=" << angleA << " B=" << angleB << " C=" << 180 - angleA << " D=" << 180 - angleB << std::endl;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	SetConsoleCP(1251);

	Triangle triangle(10, 20, 30, 50, 60, 70);
	triangle.print_info();

	RightTriangle right_triangle(10, 20);
	right_triangle.print_info();

	EquilateralTriangle equilateral_triangle(20);
	equilateral_triangle.print_info();

	Quadrilateral quadrilateral(10, 20, 30, 40);
	quadrilateral.print_info();

	Square square(20);
	square.print_info();

	Parallelogram parallelogram(20, 30, 20, 30);
	parallelogram.print_info();

	Rhombus rhombus(30, 30);
	rhombus.print_info();

	return 0;
}

/*В этом задании вы усложните иерархию классов для сложной предметной области.

У вас появляется информация о длинных сторонах и углах вашей фигуры, а также о нескольких более конкретных фигурах. 
Теперь в треугольнике вы должны сохранить информацию о длине всех его трёх сторон ( a, b, c) и значениях его трёх углов ( A, B, C). 
В четырехугольнике вы сохраните информацию о длине его четырех сторон ( a, b, c, d) и значениях его четырех углов ( A, B, C, D).

Также у вас есть более конкретные фигуры:

прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равные, углы A и C равные);
равносторонний треугольник (все стороны равны, все стороны равны 60);
сторона (стороны a, c и b, d попарно равные, все равные углы 90);
квадрат (все стороны равны, все стороны равны 90);
параллелограммы (стороны a, c и b, d попарно условие, углы A, C и B, D попарно условие);
ромб (все стороны равны, углы A, Cи B, D попарно равны).
У вас должна быть возможность узнать длину каждой фигуры, длину ее стороны и значение ее угла, 
но снаружи у вас не должно быть возможности изменить длину стороны и угла.

Не должно быть возможности создавать фигуры, не выполняющие перечисленные условия. Например, 
нельзя создать квадрат с внешними углами. Геометрические измерения проверять не нужно. 
Например, длинный угол треугольника может быть не равен 180.

Задача: спроектировать и реализовать классы, описывающие предметную область. 
Продемонстрируйте их работу на экране: создайте по одному экземпляру каждой фигуры и 
выведите информацию о длине ее стороны и величине ее угла. Значения викор произвольные.

Инициализацию длины стороны и величины угла нужно калибровать с помощью вызова базовых конструкторов.

Для получения информации о фигуре создайте функцию print_info, которая будет в качестве аргумента указатель на базовый класс фигур.

Пример работы программы
Консоль
Треугольник:
Стороны: a=10 b=20 c=30
Углы: A=50 B=60 C=70

Прямоугольный треугольник:
Стороны: a=10 b=20 c=30
Углы: A=50 B=60 C=90

Равнобедренный треугольник:
Стороны: a=10 b=20 c=10
Углы: A=50 B=60 C=50

Равносторонний треугольник:
Стороны: a=30 b=30 c=30
Углы: A=60 B=60 C=60

Четырёхугольник:
Стороны: a=10 b=20 c=30 d=40
Углы: A=50 B=60 C=70 D=80

Прямоугольник:
Стороны: a=10 b=20 c=10 d=20
Углы: A=90 B=90 C=90 D=90

Квадрат:
Стороны: a=20 b=20 c=20 d=20
Углы: A=90 B=90 C=90 D=90

Параллелограмм:
Стороны: a=20 b=30 c=20 d=30
Углы: A=30 B=40 C=30 D=40

Ромб:
Стороны: a=30 b=30 c=30 d=30
Углы: A=30 B=40 C=30 D=40

Нужно создать класс для каждой фигуры.

Иерархия наследования для более конкретных фигур может существовать.
Например, параллелограмма будет наследоваться от четырехугольника, прямоугольник и ромб — от параллелограммы. 
Было бы логично, что квадрат уна следует соблюдать от ромба и контура, ведь он и тем, и другим.
Но вы помните, что стоит соблюдать множественное наследование, поэтому следите за ним 
либо со стороны, либо со стороны ромба во время вашего осмотра.

Для хранения информации о длине сторон и больших углах создайте поля a, b, c и A, B, C в классе треугольника 
и соответствующие им get_методы, а в классе четырехугольник создайте поля a, b, c, d и A, B, C, D и соответствующие им get_методы.

У вас появятся разные конструкторы.
Например, у конструктора класса треугольника будет 6 параметров — три для длинной стороны и три для угловых. 
В конструкторе класса прямоугольного треугольника будет 5 параметров — угол C у него всегда равен 90.
В конструкторе класса равностороннего треугольника конструктор будет принимать только один параметр — это длину его стороны.*/