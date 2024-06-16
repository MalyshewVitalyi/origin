#include "math_functions.h"

int addition(int a, int b) 
{
    return a + b;
}

int subtraction(int a, int b) 
{
    return a - b;
}

int multiplication(int a, int b) 
{
    return a * b;
}

int division(int a, int b) {
    if (b == 0) {
        return 0; 
    }
    return a / b;
}

int exponentiation(int a, int b) 
{
    int result = 1;
    for (int i = 0; i < b; i++) 
    {
        result *= a;
    }
    return result;
}