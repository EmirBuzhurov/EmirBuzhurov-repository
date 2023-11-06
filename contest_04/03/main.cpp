#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
using namespace std;

int main() {
    int pclass;
    double age;
    cin >> pclass >> age;
    set<pair<int, string>> Psngr;
    ifstream file("train.csv");
    file.ignore(100, '\r');
    string line;
    while (getline(file, line, '\r')) {
        istringstream ss(line);
        ss.ignore(10, ',');
        ss.ignore(10, ',');
        string Pclass;
        getline(ss, Pclass, ',');
        int pclass1 = stoi(Pclass);
        if (pclass1 != pclass) {
            continue;
        }
        ss.ignore(1);
        string Name = "";
        getline(ss, Name, '"');
        while (ss.peek() == '"') {
            ss.ignore(1);
            string name;
            getline(ss, name, '"');
            Name += '"' + name + '"';
            ss.ignore(1);
            getline(ss, name, '"');
            Name += name;
        }
        ss.ignore(1);
        string Sex;
        getline(ss, Sex, ',');
        if (Sex != "female") {
            continue;
        }
        string Age;
        getline(ss, Age, ',');
        int age1;
        if (Age == "") {
            age1 = 0;
        }
        else {
            age1 = stoi(Age);
        }
        if (age1 <= age) {
            continue;
        }
        Psngr.insert({ age, Name });
    }

    for (auto& element : Psngr) {
        cout << element.second << "\n";
    }
}
