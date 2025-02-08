#include "./Point.hpp"


Point::Point(): x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float& a, const float& b): x(a), y(b) {}

Point::Point(const Point& other): x(other.x), y(other.y) {}

Point&  Point::operator = (const Point& other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::get_triangle_area(Point const a, Point const b, Point const c) const 
{
    Fixed area = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / Fixed(2);
    return (area < Fixed(0)) ? area * Fixed(-1) : area; // Take absolute value
}



bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   abc;
    Fixed   pab;
    Fixed   pac;
    Fixed   pbc;
    Fixed   epsilon;

    epsilon.setRawBits(1);
    abc = a.get_triangle_area(a, b, c);
    pab = point.get_triangle_area(point, a, b);
    pac = point.get_triangle_area(point, a, c);
    pbc = point.get_triangle_area(point, b, c);
    std::cout << "abc : "<< abc << std::endl;
    std::cout << "pab : "<< pab << std::endl;
    std::cout << "pac : "<< pac << std::endl;
    std::cout << "pbc : "<< pbc << std::endl;
    Fixed res = pab  + pbc + pac;
    std::cout << "all = " << res << std::endl;
    std::cout << "epsilon = " << epsilon << std::endl;
    if (pab < epsilon || pbc < epsilon || pac < epsilon)
        return false;
    return ((pab + pac + pbc) == abc);
}