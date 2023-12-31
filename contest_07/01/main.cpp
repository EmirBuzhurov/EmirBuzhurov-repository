#include <queue>
using namespace std;

class OSUpdater : public IRunnable {
public:
    void run() {
        cout << "OSUpdater\n";
    }
};

class Alarm : public IRunnable {
public:
    void run() {
        cout << "Alarm\n";
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() {
        cout << "ActivityChecker\n";
    }
};

class Clock : public IRunnable, public IClock {
private:
    queue<pair<Time, IRunnable*>> ts;
public:
    void add(IRunnable* cl, Time t) {
        ts.push({t, cl});
    }
    bool next() {
        if (ts.empty()) {
            return false;
        }
        auto c = ts.front();
        ts.pop();
        string hours, minutes, seconds;
        if (c.first.hours < 10) {
            hours = "0";
        }
        hours += to_string(c.first.hours);
        if (c.first.minutes < 10) {
            minutes = "0";
        }
        minutes += to_string(c.first.minutes);
        if (c.first.seconds < 10) {
            seconds = "0";
        }
        seconds += to_string(c.first.seconds);
        cout << hours << ":" << minutes << ":" << seconds << " ";
        c.second->run();
        return true;
    }
    void run() {
        while(next());
    }
};
