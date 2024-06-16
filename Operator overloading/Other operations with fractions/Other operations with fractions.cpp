#include <iostream>
#include <string>
#include<Windows.h>

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

    void reduceFraction() 
    {
        int commonFactor = gcd(numerator_, denominator_);
        numerator_ /= commonFactor;
        denominator_ /= commonFactor;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    Fraction operator+(const Fraction& other) const 
    {
        int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const 
    {
        int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const 
    {
        int newNumerator = numerator_ * other.numerator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        int newNumerator = numerator_ * other.denominator_;
        int newDenominator = denominator_ * other.numerator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-() const 
    {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++() 
    {
        numerator_ += denominator_;
        reduceFraction();
        return *this;
    }

    Fraction operator++(int) 
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() 
    {
        numerator_ -= denominator_;
        reduceFraction();
        return *this;
    }

    Fraction operator--(int) 
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) 
{
    out << fraction.numerator_ << "/" << fraction.denominator_;
    return out;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    SetConsoleCP(1251);
    int num1, den1, num2, den2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    Fraction resultAdd = f1 + f2;
    std::cout << f1 << " + " << f2 << " = " << resultAdd << std::endl;

    Fraction resultSubtract = f1 - f2;
    std::cout << f1 << " - " << f2 << " = " << resultSubtract << std::endl;

    Fraction resultMultiply = f1 * f2;
    std::cout << f1 << " * " << f2 << " = " << resultMultiply << std::endl;

    Fraction resultDivide = f1 / f2;
    std::cout << f1 << " / " << f2 << " = " << resultDivide << std::endl;

    ++f1;
    Fraction resultInc = f1 * f2;
    std::cout << "++" << f1 << " * " << f2 << " = " << resultInc << std::endl;

    std::cout << "Значение дроби 1 = " << f1 << std::endl;

    f1--;
    Fraction resultDec = f1 * f2;
    std::cout << f1 << "-- * " << f2 << " = " << resultDec << std::endl;

    std::cout << "Значение дроби 1 = " << f1 << std::endl;

    return 0;
}

/*В этом задании вы переопределите остальные операторы для класса дроби.

Необходимо переопределить операторы для класса Fraction из предыдущего задания:

сложение;
вычитание;
умножение;
деление;
унарный минус;
инкремент постфиксный и префиксный;
декремент постфиксный и префиксный.
Продемонстрируйте работу ваших операторов.
Попросите пользователя ввести две дроби и покажите результат каждой операции. 
Операции декремента и инкремента отнимают и прибавляют к дроби 1 соответственно.

Составьте выражения, содержащие постфиксный и префиксный инкремент и декремент,
чтобы продемонстрировать разницу между постфиксной и префиксной версиями.

Пример работы программы
Консоль
Введите числитель дроби 1: 3
Введите знаменатель дроби 1: 4
Введите числитель дроби 2: 4
Введите знаменатель дроби 2: 5
3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
Значение дроби 1 = 7/4
3/4-- * 4/5 = 12/20
Значение дроби 1 = 3/4

Что использовать для решения.
Префиксная и постфиксная версии различаются фальшивым аргументом в постфиксной версии.

Не забудьте, что две версии ведут себя по-разному.

Не забудьте написать код, сокращающий дроби.*/