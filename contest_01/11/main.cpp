#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B && A > C) {
        if (B > C) { cout << "B " << abs(A-B); }
        else { cout << "C " << abs(A-C); }
    }
    if (A < B && A < C) {
        if (B < C) { cout << "B " << abs(A-B); }
        else { cout << "C " << abs(A-C); }
    }
    if ((A > B && A < C) || (A < B && A > C)) {
        if (abs(A - B) < abs(A - C)) { cout << "B " << abs(A-B); }
        else { cout << "C " << abs(A-C); }
        }

    }
