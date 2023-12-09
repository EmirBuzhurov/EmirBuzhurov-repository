class Cat {
    public:
    bool alive;
    Cat(bool is_alived) {
        alive = is_alived;
    }
    bool is_alive() {
        return alive;
    }
};

class Box {
    public:
    Cat open() {
        double random = (double)rand() / RAND_MAX;
        bool is_alive = (random > 0.5);
        return Cat(is_alive);
    }
};
