#include <iostream>
#include <stack>
using namespace std;
const string highPrior = "^";
const string midPrior = "*/%";
const string lowPrior = "+-";
const string operators = highPrior + midPrior + lowPrior;
const string numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

enum Prior {LOW, MID, HIGH};
int getPriority(char oper) {
    if (lowPrior.find_first_of(oper) != string::npos) {
        return LOW;
    } else if (midPrior.find_first_of(oper) != string::npos) {
        return MID;
    } else {
        return HIGH;
    }
}
int main() {
    string input;
    getline(cin, input);
    stack<char> pending;
    for (int i = 0; i < input.length(); i++) {
        if (numbers.find_first_of(input[i]) != string::npos) {
            int stopPos = input.find_first_of(operators + "()", i);
            int itemLen = stopPos - i;
            string item = input.substr(i, itemLen);
            i += itemLen - 1;
            std::cout << item << " ";
        } else if (operators.find_first_of(input[i]) != string::npos) {
            char curOper = input[i];
            int curPrior = getPriority(curOper);
            if (curPrior != HIGH) {
                while (pending.size() > 0) {
                    char pendOper = pending.top();
                    if (pendOper == '(') {
                        break;
                    }
                    int pendPrior = getPriority(pendOper);
                    if (pendPrior >= curPrior) {
                        cout << pendOper << " ";
                        pending.pop();
                    } else {
                        break;
                    }
                }
            }
            pending.push(curOper);
        } else if (input[i] == '(') {
            pending.push(input[i]);
        } else if (input[i] == ')') {
            while (pending.size() > 0) {
                char pendOper = pending.top();
                pending.pop();
                if (pendOper == '(') {
                    break;
                }
                cout << pendOper << " ";
            }
        }
    }
    while (pending.size() > 0) {
        char pendOper = pending.top();
        pending.pop();
        cout << pendOper << " ";
    }
    cout << "\n";
}
