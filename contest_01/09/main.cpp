#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, c;
    cin >> a;
    cin >> b;
    c = sqrt(a*a + b*b);
    cout << c;
}
