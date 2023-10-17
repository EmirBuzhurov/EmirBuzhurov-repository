#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> word_count;
    int n;
    cin >> n;
    cin.ignore();
    string text;
    getline(cin, text);
    string word;
    for (char& c : text) {
        if (isalpha(c)) {
            word += c;
        }
        else if (!word.empty()) {
            word_count[word]++;
            word = "";
        }
    }
    if (!word.empty()) {
        word_count[word]++;
    }
    int max_count = 0;
    for (const auto& pair : word_count) {
        max_count = max(max_count, pair.second);
    }
    vector<string> most_common_words;
    for (const auto& pair : word_count) {
        if (pair.second == max_count) {
            most_common_words.push_back(pair.first);
        }
    }
    sort(most_common_words.begin(), most_common_words.end());
    for (const string& word : most_common_words) {
        cout << word << " ";
    }
}
