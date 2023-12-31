#include <cstring>

struct Hacker {
int trash;
int secret;
};

int hack_it(Keeper keeper) {
Hacker hacker;
std::memcpy(&hacker, &keeper, sizeof(keeper));
return hacker.secret;
}
