#include <iostream>
using namespace std;

class Calculator
{
private:
    int num1, num2;

public:
    void setValues(int a, int b)
    {
        num1 = a;
        num2 = b;
    }

    void sum()
    {
        cout << "Sum = " << num1 + num2 << endl;
    }

    void subtract()
    {
        cout << "Subtraction = " << num1 - num2 << endl;
    }
};

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    Calculator c;

    c.setValues(a, b);

    c.sum();
    c.subtract();

    return 0;
}