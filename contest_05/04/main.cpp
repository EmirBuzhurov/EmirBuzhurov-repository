class Point {
private:
double x;
double y;
double r;
double a;

public:
Point(double x, double y) {
this->x = x;
this->y = y;
updatePolarCoordinates();
}

double get_x() {
    return x;
}

double get_y() {
    return y;
}

double get_r() {
    return r;
}

double get_a() {
    return a;
}

void set_x(double x) {
    this->x = x;
    updatePolarCoordinates();
}

void set_y(double y) {
    this->y = y;
    updatePolarCoordinates();
}

void set_r(double r) {
    this->r = r;
    updateCartesianCoordinates();
}

void set_a(double a) {
    this->a = a;
    updateCartesianCoordinates();
}
private:
void updatePolarCoordinates() {
r = sqrt(x * x + y * y);
a = atan2(y, x);
}

void updateCartesianCoordinates() {
    x = r * cos(a);
    y = r * sin(a);
}
};
