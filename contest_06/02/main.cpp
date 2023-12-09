using namespace std;

class Employee {
public:
    string N, P;
    int B_M;
    Employee(string n, string p, int b_m) {
        N = n;
        P = p;
        B_M = b_m;
    }
    virtual int bonus(double perc) const {
        return (int)(B_M * perc + 0.5);
    }
    friend ostream& operator<<(ostream& o, const Employee& e) {
        o << e.N << " (" << e.P << "): " << e.B_M + e.bonus(bonuses[e.P]);
        return o;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int b_m = 16242)
        :Employee(n, "manager", b_m) {}

    int bonus(double perc) const {
        if (perc < 0.1) {
            perc = 0.1;
        }
        return (int)(B_M * perc + 0.5);
    }
};
