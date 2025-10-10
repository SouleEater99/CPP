#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;    
public:
    BitcoinExchange(/* args */);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadData(const std::string &filename);
    bool getExchangeRate(const std::string &date, float &rate) const;
    bool isValidDate(const std::string &date) const;
    bool isValidFloat(const std::string &value, float &result) const;

};



#endif