#include <cmath>

class Shape {
public:
    virtual double getPerimeter() = 0;
};

class Rectangle : public Shape {
private:
    int length;
    int width;
public:
    Rectangle(int a, int b) : length(a), width(b) {}

    double getPerimeter() override {
        return 2 * (length + width);
    }
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int r) : radius(r) {}

    double getPerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Triangle : public Shape {
private:
    int side1;
    int side2;
    int side3;
public:
    Triangle(int a, int b, int c) : side1(a), side2(b), side3(c) {}

    double getPerimeter() override {
        if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
            return side1 + side2 + side3;
        }
        return 0;
    }
};
