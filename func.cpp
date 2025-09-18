#include "func.h"
#include <math.h>

void read_point(Points &point){
    int in_x, in_y;
    std::cout << "Enter x: ";
    std::cin >> in_x;
    std::cout << "Enter y: ";
    std::cin >> in_y;
    point.x = in_x;
    point.y = in_y;
}

void show_point(Points &point){
    std::cout << "Coordinates-->  x: " << point.x << " y: " << point.y << std::endl;
}

void read_center_radius(Circle &circle){
    std::cout << "Enter x: ";
    std::cin >> circle.center.x;
    std::cout << "Enter y: ";
    std::cin >> circle.center.y;
    std::cout << "Enter r: ";
    std::cin >> circle.r;

}
void show_circle(Circle &circle){
    std::cout << "x:" <<circle.center.x << " y:" << circle.center.y << " r:"<< circle.r << std::endl;
}

double long_circle(Circle &circle){
    return 2 * M_PI * circle.r;

}

double area_cicrcle(Circle &circle){
    return M_PI * circle.r * circle.r;
}

void read_square(Square &square){
    std::cout << "Enter x: ";
    std::cin >> square.angle.x;
    std::cout << "Enter y: ";
    std::cin >> square.angle.y;
    std::cout << "Enter r: ";
    std::cin >> square.long_side;
}

void show_square(Square &square){
    std::cout << "x:" <<square.angle.x << " y:" << square.angle.y << " long_side:"<< square.long_side << std::endl;
}

double perimetr_square(Square &square){
    return square.long_side * 4;
}
double square_square(Square &square){
    return square.long_side * square.long_side;
}

bool point_in_circle(Points &point, Circle &circle){
    return sqrt((point.x - circle.center.x)*(point.x -circle.center.x) + (point.y - circle.center.y)*(point.x -circle.center.x)) < circle.r;
}

bool point_in_square(Points &point, Square &square){
    return ((point.x > square.angle.x) and (point.x < square.angle.x+square.long_side)) and ((point.y < square.angle.y) and (point.y > square.angle.y-square.long_side));
}

bool point_on_circle(Points &point, Circle &circle){
    return sqrt((point.x - circle.center.x)*(point.x -circle.center.x) + (point.y - circle.center.y)*(point.x -circle.center.x)) == circle.r;
}

bool point_on_square(Points &point, Square &square){
    return (((point.x > square.angle.x) and (point.x < square.angle.x+square.long_side)) and (point.y == square.angle.y or point.y == square.angle.y-square.long_side)) and (((point.y < square.angle.y) and (point.y > square.angle.y-square.long_side)) and (point.x == square.angle.x or point.x == square.angle.x+square.long_side));
}

bool cross_cicrcles(Circle &circle_1, Circle &circle_2){
    return sqrt((circle_1.center.x - circle_2.center.x)*(circle_1.center.x -circle_2.center.x) + (circle_1.center.y - circle_2.center.y)*(circle_1.center.x -circle_2.center.x)) < (circle_1.r+circle_2.r);
}
bool cross_squares(Square &square_1, Square &square_2){
    Points right_up_1;
    Points right_down_1;
    Points left_down_1;
    Points right_up_2;
    Points right_down_2;
    Points left_down_2;

    right_up_1.x = square_1.angle.x + square_1.long_side;
    right_up_1.x = square_1.angle.y;

    right_down_1.x = square_1.angle.x + square_1.long_side;
    right_down_1.y = square_1.angle.y - square_1.long_side;

    left_down_1.x = square_1.angle.x;
    left_down_1.y = square_1.angle.y - square_1.long_side;


    right_up_2.x = square_2.angle.x + square_2.long_side;
    right_up_2.x = square_2.angle.y;

    right_down_2.x = square_2.angle.x + square_2.long_side;
    right_down_2.y = square_2.angle.y - square_2.long_side;

    left_down_2.x = square_2.angle.x;
    left_down_2.y = square_2.angle.y - square_2.long_side;


    return (point_in_square(square_1.angle, square_2) or point_in_square(right_up_1, square_2) or point_in_square(right_down_1, square_2) or point_in_square(left_down_1, square_2) or //Любой угол 1 квадрата лежит внутри 2 квадрата
    point_in_square(square_2.angle, square_1) or point_in_square(right_down_2, square_1) or point_in_square(left_down_2, square_1) or point_in_square(left_down_2, square_1)) and //Любой угол 2 квадрата лежит внутри 1 квадрата
    !(point_in_square(square_1.angle, square_2) and point_in_square(right_up_1, square_2) and point_in_square(right_down_1, square_2) and point_in_square(left_down_1, square_2)) and //Все углы 1 квадрата не лежат внутри 2 квадрата
    !(point_in_square(square_2.angle, square_1) and point_in_square(right_down_2, square_1) and point_in_square(left_down_2, square_1) and point_in_square(left_down_2, square_1)); //Все углы 2 квадрата не лежат внутри 1 квадрата
}