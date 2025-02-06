#include "./Point.hpp"


Point::Point(): x(0), y(0) {}

Point::Point(const float& a, const float& b): x(a), y(b) {}

Point::Point(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
}

Point&  Point::operator = (const Point& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Point::~Point() {}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{

}

int Point::get_triangle_area( Point const a, Point const b, Point const c)
{
    int Area;

    Area = (a.x * b.y - a.x * c.y) + (b.x * c.y - b.x * a.y) + (c.x * a.y - c.x * b.y);
    Area = abs(Area) / 2;
    return (Area);
}