#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

class Point
{
private:
    Fixed   x;
    Fixed   y;

public:
    Point();
    Point(const float& a, const float& b);
    Point(const Point& other);
    Point&  operator = (const Point& other);
    ~Point();
    bool bsp( Point const a, Point const b, Point const c, Point const point);
    int get_triangle_area( Point const a, Point const b, Point const c );
};




#endif