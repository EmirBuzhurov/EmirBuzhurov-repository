class Vector;

class Point {
public:
    int x;
    int y;
    Point(int a, int b) {
        x = a;
        y = b;
    };
    void move(Vector vector);

};

class Vector {
public:
    int x;
    int y;
    Vector(Point p1, Point p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
};

void Point::move(Vector vector) {
    x = vector.x + x;
    y = vector.y + y;
};
