#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    cin >> a >> b;
    if (a > b) { cout << a; }
    else { cout << b; }
}
