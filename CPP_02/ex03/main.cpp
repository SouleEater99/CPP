#include "./Point.hpp"

int main(void)
{
    Point   a(1, 1);
    Point   b(2, 3);
    Point   c(3, 1);
    Point   point(2, 1.1);

    if (point.bsp(a,b,c,point))
    {
        std::cout << "is the point inside the triangle : " ;
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "is the point inside the triangle : " ;
        std::cout << "false" << std::endl;
    }
}