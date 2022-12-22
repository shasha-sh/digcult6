#pragma once

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926535897932384626433832795;

struct Point {
    double x, y;
    Point(double x_ = 0, double y_ = 0) {
        x = x_;
        y = y_;
    }
};

istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

struct Vector {
    double x, y;
    Vector(double x_ = 0, double y_ = 0) {
        x = x_;
        y = y_;
    }
    Vector(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    double len() {
        return sqrt(x * x + y * y);
    }
};

bool operator==(Vector a, Vector b) {
    return (a.x == b.x) && (a.y == b.y);
}

Vector operator+(Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y);
}

double operator*(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double operator%(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

istream& operator>>(istream& in, Vector& v) {
    in >> v.x >> v.y;
    return in;
}

struct Line {
    double a, b, c;
    Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
};

bool operator==(Line x, Line y) {
    return (x.a == y.a) && (x.b == y.b) && (x.c == y.c);
}

istream& operator>>(istream& in, Line& line) {
    in >> line.a >> line.b >> line.c;
    return in;
}

double get_corner(Vector a, Vector b) {
    double ans = atan2(a % b, a * b);
    if (ans < 0) {
        ans += 2 * PI;
    }
    return ans;
}

Line get_line(Point n, Point m) {
    Line line;
    line.a = m.y - n.y;
    line.b = n.x - m.x;
    line.c = -line.a * n.x - line.b * n.y;
    return line;
}

