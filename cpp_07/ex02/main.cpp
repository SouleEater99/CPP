#include "./Array.hpp"

int main() 
{
    try 
    {
        // Test default constructor
        Array<int> a;
        std::cout << "size of a: " << a.size() << "\n"; // should be 0

        // Test parameterized constructor
        Array<int> b(5);
        std::cout << "size of b: " << b.size() << "\n"; // should be 5

        // Fill array b
        for (unsigned int i = 0; i < b.size(); i++) 
            b[i] = i * 10;

        // Print array b
        for (unsigned int i = 0; i < b.size(); i++) 
            std::cout << "b[" << i << "] = " << b[i] << "\n";

        // Test copy constructor
        Array<int> c(b);
        std::cout << "Copied c from b:\n";
        for (unsigned int i = 0; i < c.size(); i++) 
            std::cout << "c[" << i << "] = " << c[i] << "\n";

        // Modify c and check b is unchanged
        c[0] = 999;
        std::cout << "After modifying c[0]:\n";
        std::cout << "c[0] = " << c[0] << ", b[0] = " << b[0] << "\n";

        // Test assignment operator
        a = c;
        std::cout << "After assigning a = c:\n";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << "a[" << i << "] = " << a[i] << "\n";

        // Test out-of-bounds
        std::cout << "Trying to access a[100]...\n";
        std::cout << a[100] << "\n"; // should throw
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }
}
