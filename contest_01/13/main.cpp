#include <iostream>
#include <math.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int len, o = 1, j, k=1, i=1;
    cin >> len;
    if (len!=1) {for (k = 1; k < len+1; k++) {
        for (i; i <= k && o-1 < len; i++) {

            for (j = 0; j < i && o-1 < len; j++) {
                cout << o << " ";
                o++;
                if (o == len+1) { break; }
            }
            if (o == len+1) { break; }
            cout << "\n";
        }
        for (i; i > 1 && o-1 < len; i--) {
            for (j = 0; j < i && o-1 < len; j++) {
                cout << o << " ";
                o++;
                if (o == len+1) { break; }
            }
            if (o == len+1) { break; }
            cout << "\n";
        }
        if (o == len+1) { break; }
    }
    } else {cout << 1;}
}

