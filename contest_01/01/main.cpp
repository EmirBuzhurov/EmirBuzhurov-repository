#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float a;
    a = sqrt(12) * (1.0 - (1.0 / (3.0 * 3.0)) + (1.0 / (5.0 * 3.0 * 3.0)) - (1.0 / (7.0 * 3.0 * 3.0 * 3.0)) + (1.0 / (9.0 * 3.0 * 3.0 * 3.0 * 3.0)) - (1.0 / (11.0 * 3.0 * 3.0 * 3.0 * 3.0 * 3.0)) );
    cout << a;
}
