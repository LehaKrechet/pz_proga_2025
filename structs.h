#include <iostream>
struct Points{
    double x = 0, y = 0;
};


struct Circle{
    double r = 0;
    Points center;
};


struct Square{
    Points angle;
    double long_side = 0;
};