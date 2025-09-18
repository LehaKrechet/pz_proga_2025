#include "structs.h"

void read_point(Points &point);
void show_point(Points &point);

void read_center_radius(Circle &circle);
void show_circle(Circle &circle);
double long_circle(Circle &circle);
double area_cicrlce(Circle &circle);

void read_square(Square &square);
void show_square(Square &square);
double perimetr_square(Square &square);
double square_square(Square &square);

bool point_in_circle(Points &point, Circle &circle);
bool point_in_square(Points &point, Square &square);

bool point_on_circle(Points &point, Circle &circle);
bool point_on_square(Points &point, Square &square);

bool cross_cicrcles(Circle &circle_1, Circle &circle_2);
bool cross_squares(Square &square_1, Square &square_2);