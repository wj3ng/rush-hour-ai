#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:

    int ind;
    int row;
    int col;
    int len;
    int ori;

    Car(Car const& a);
    Car(int a, int b, int c, int d, int e);

};

#endif