#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, d=0;
    cin >> a;
    string* s1{ new string[a] };
    for (int i=0; i < a; i++) {
        cin >> s1[i];
    }
    cin >> b;
    string* s2{ new string[b] };
    for (int i=0; i < b; i++) {
        cin >> s2[i];
    }
    int c = a + b;
    int* num{ new int[c] };
    for (int i = 0; i < a; i++) {
        num[i] = stoi(s1[i]);
    }
    for (int i = a; i < c; i++) {
        num[i] = stoi(s2[d]);
        d++;
    }
    sort(num, num + c);
    for (int i = 0; i < c; i++) {
        cout << num[i];
        if (i != c - 1) {
            cout << " ";
        }
    }
}
