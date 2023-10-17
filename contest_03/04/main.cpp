#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin.ignore();
    set<string> words1;
    string word;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        words1.insert(word);
    }
    cin >> m;
    cin.ignore();
    set<string> words2;
    for (int i = 0; i < m; ++i) {
        cin >> word;
        words2.insert(word);
    }
    set<string> common_words;
    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(),
                          inserter(common_words, common_words.begin()));
    if (common_words.empty()) 
        cout << -1;
    else {
        for (const auto& word : common_words){
            cout << word << " ";
        }
    }
}
