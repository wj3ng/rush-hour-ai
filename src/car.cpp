#include "car.hpp"

Car::Car(Car const& a)
    : ind(a.ind), row(a.row), col(a.col), len(a.len), ori(a.ori) { }

Car::Car(int a, int b, int c, int d, int e)
    : ind(a), row(b), col(c), len(d), ori(e) { }