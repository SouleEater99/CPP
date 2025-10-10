#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}



bool BitcoinExchange::getExchangeRate(const std::string &date, float &rate) const
{
    std::map<std::string, float>::const_iterator it = _data.find(date);
    if (it != _data.end())
    {
        rate = it->second;
        return true;
    }
    return false;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::istringstream iss(date.substr(0, 4) + " " + date.substr(5, 2) + " " + date.substr(8, 2));
    int year, month, day;
    if (!(iss >> year >> month >> day))
        return false;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Check days in month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    return true;
}

bool BitcoinExchange::isValidFloat(const std::string &value, float &result) const
{
    char *endptr;

    result = std::strtof(value.c_str(), &endptr);
    if (*endptr != '\0' || endptr == value.c_str())
        return false;
    return true;

}

void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw  std::runtime_error("Error: Could not open file " + filename);
    }
    std::string line;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line))
    {
        // Skip empty lines
        if (line.empty())
        continue;
        
        // Find comma separator
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            throw std::runtime_error("Error: Invalid line format (no comma)");
            continue;
        }
        
        // Extract and trim fields
        std::string date = line.substr(0, commaPos);
        std::string rate = line.substr(commaPos + 1);
        
        // Validate and insert data
        if (isValidDate(date))
        {
            float rateValue;
            if (!isValidFloat(rate, rateValue))
            throw std::runtime_error("Error: Invalid rate value");
            _data[date] = rateValue;
        }
        else
        {
            throw std::runtime_error("Error: Invalid date format in date: " + date);
        }
    }
    file.close();
}