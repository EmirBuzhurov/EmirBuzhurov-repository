#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    ifstream file("data.json");
    json data = json::parse(file);
    int user_id, counter = 0;
    cin >> user_id;
    for(const auto&i:data) {
        for(const auto&j:i["tasks"]) {
            if (j["user_id"]==user_id && j["completed"]==true) {
                counter++;
            }
        }
    }
    cout << counter;
}
