#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int i = 0;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    for (i; i < a.length(); i++) {
        if (a[i] != b[i]){
            cout << "NO";
            break;
        }
    }
    if (i == a.length()) {
        cout << "YES";
    }
}
