#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s1;
    string s2;
    int count = 1;
    char a;
    cin >> s1;
    for (int i = 0;i < s1.length();i++) {
        a = s1[i];
        if (s1[i] == s1[i+1]) {
                count++;
        }
        else if (s1[i]!=s1[i+1]) {
            s2+=a;
            if (count != 1 ) {s2+=to_string(count);}
            count=1;
        }
    }
    cout << s2;
}

