#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(const Fraction& other) const
	{
		return (numerator_ * other.denominator_ == other.numerator_ * denominator_);
	}

	bool operator!=(const Fraction & other) const
	{
		return !(*this == other);
	}

	bool operator<(const Fraction & other) const
	{
		return (numerator_ * other.denominator_ < other.numerator_ * denominator_);
	}

	bool operator>(const Fraction & other) const
	{
		return (numerator_ * other.denominator_ > other.numerator_ * denominator_);
	}

	bool operator<=(const Fraction & other) const
	{
		return (*this < other) || (*this == other);
	}

	bool operator>=(const Fraction & other) const
	{
		return ( *this > other) || (*this == other);
	}
};

int main(int argc, char** argv)

{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
/*В этом задании вы переопределите операторы сравнения для дробей.

Дан код на C++:

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
Ваша задача — дописать класс Fraction так, чтобы программа скомпилировалась и работала корректно.

Пример работы программы
Консоль
f1 not == f2
f1 != f2
f1 not < f2
f1 > f2
f1 not <= f2
f1 >= f2

Что использовать для решений.
Чтобы код скомпилировался, вам необходимо перегрузить операторы сравнения.

Не забывайте, что уникальный код можно записать всего для двух операторов сравнения, остальные можно определить через них.*/