#include "./Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("debug");
    std::cout << "========================================\n";
    harl.complain("info");
    std::cout << "========================================\n";
    harl.complain("warning");
    std::cout << "========================================\n";
    harl.complain("error");
    std::cout << "========================================\n";
    harl.complain("");
    std::cout << "========================================\n";
    harl.complain("test");
    std::cout << "========================================\n";
    harl.complain("Error");
    std::cout << "========================================\n";
}