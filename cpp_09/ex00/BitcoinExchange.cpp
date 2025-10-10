#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _data(other._data)
{
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
    // Try exact match first
    std::map<std::string, float>::const_iterator it = _data.find(date);
    if (it != _data.end())
    {
        rate = it->second;
        return true;
    }

    // Find closest lower date
    it = _data.lower_bound(date);
    if (it == _data.begin())
    {
        // Requested date is before all available dates
        return false;
    }

    // Move to previous element (closest lower date)
    --it;
    rate = it->second;
    return true;
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
        throw std::runtime_error("Error: Could not open file " + filename);
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

bool BitcoinExchange::isFormatValid(const std::string &line, std::string &date, float &value) const
{
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos)
        return false;

    date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 1);

    // Trim whitespaces
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

    // Validate date and value
    if (!isValidDate(date))
        return false;

    if (!isValidFloat(valueStr, value))
        return false;

    return true;
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(inputFile, line); // Skip header line
    while (std::getline(inputFile, line))
    {
        // Process each line
        std::string date;
        float value;

        if (!isFormatValid(line, date, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Get exchange rate
        float rate;
        if (!getExchangeRate(date, rate))
        {
            std::cerr << "Error: no exchange rate available for date => " << date << std::endl;
            continue;
        }

        // Calculate and display result
        float result = rate * value;
        std::cout << date << " => " << value << " * " << rate << " = " << result << std::endl;
    }

    inputFile.close();
}