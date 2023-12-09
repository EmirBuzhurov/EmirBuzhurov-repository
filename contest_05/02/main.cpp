class Water {
private:
int temperature;
public:
Water(int temp) : temperature(temp) {}

int get_temperature() {
    return temperature;
}
};

class Teapot {
private:
Water water;
public:
Teapot(Water& w) : water(w) {}

bool is_boiling() {
    return water.get_temperature() >= 100;
}

void heat_up(int degrees) {
    water = Water(water.get_temperature() + degrees);
}
};
