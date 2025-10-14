#include <iostream>
#include "func.h"


int main(){

    Points point;
    Circle circle;
    Square square;

    show_point(point);
    read_point(point);
    show_point(point);

    show_circle(circle);
    read_center_radius(circle);
    show_circle(circle);

    show_square(square);
    read_square(square);
    show_square(square);

    std::cout << point_in_circle(point, circle) << std::endl;

    std::cout << point_in_square(point, square) << std::endl;

    std::cout << point_on_circle(point, circle) << std::endl;

    std::cout << point_on_square(point, square) << std::endl;


}