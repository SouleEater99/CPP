#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange exchange;
    try
    {
        exchange.loadData("data.csv");
    
        float rate;
        if (exchange.getExchangeRate("2011-01-02", rate))
        {
            std::cout << "Exchange rate on 2011-01-01: " << rate << std::endl;
        }
        else
        {
            std::cout << "No data available for 2011-01-01." << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}