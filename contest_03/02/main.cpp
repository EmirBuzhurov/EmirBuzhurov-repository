#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(const string& text) {
    stack<char> brackets;
    for (char ch : text) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty()) {
                return false;
            }
            char openBracket = brackets.top();
            brackets.pop();
            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                return false;
            }
        }
    }
    return brackets.empty();
}
int main() {
    string text;
    getline(cin, text, '!');

    if (isBalanced(text)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
