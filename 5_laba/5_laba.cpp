#include <iostream>
using namespace std;

double calculate(double x, int n)
{
    double y;
    if (x <= 0) {
        y = 0;
        for (int i = 0; i <= n; i++)
        {
            y += (x - i) * (x - i);
        }
    }
    else {
        y = 1;
        double prod = 1;
        for (int i = 1; i <= n; i++) {
            prod = 1;
            for (int j = 0; j <= n; j++)
            {
                prod *= (x - i - j);
            }
            y *= prod;
        }
    }
    return y;
}

void CheckValidInput()
{
    if (cin.fail())
    {
        throw "Incorrect input!";
    }
}

void CheckValidParams(int n, double h)
{
    if (n < 4)
    {
        throw "Input correct data!";
    }
    if (h <= 0)
    {
        throw "Input correct data!";
    }
}

int main()
{
    double a, b, h;
    int n;

    try
    {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        cout << "Enter h: ";
        cin >> h;
        cout << "Enter n: ";
        cin >> n;

        cout << endl;

        CheckValidInput();
        CheckValidParams(n, h);
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown error!" << endl;
        return -2;
    }
    for (double x = a; x <= b; x += h)
    {
        double y = calculate(x, n);
        cout << "x = " << x << "; y = " << y << endl;
    }
    return 0;
}