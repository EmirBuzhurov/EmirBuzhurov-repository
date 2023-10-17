#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

int main() {
    ifstream file("data.txt");
    string target;
    cin >> target;
    map<string, int> answers;
    string temp;
    file >> temp;
    while (temp != "stopword") {
        if (temp == target) {
            file >> temp;
            if (temp == "stopword") {
                break;
            }
            answers[temp]++;
        }
        file >> temp;
    }
    if (answers.empty()) {
        cout << "-" << "\n";
        return 0;
    }
    map<int, set<string>> final;
    for (auto& [word, count] : answers) {
        final[count].insert(word);
    }
    int count = 0;
    for (auto it = final.rbegin(); it != final.rend(); ++it) {
        for (auto word : it->second) {
            cout << word << " ";
            if (++count >= 3) {
                break;
            }
        }
        if (count >= 3) {
            break;
        }
    }
    cout << "\n";
}
