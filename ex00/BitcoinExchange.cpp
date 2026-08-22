/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:13 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 13:01:19 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &sample): _data(sample._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
	if (this != &source)
		this->_data = source._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::Database()
{
	std::string		line;
	std::ifstream	dataFile;


	dataFile.open("data.csv");
	if (!dataFile.is_open())
		throw NoDataExc();
	if(!std::getline(dataFile, line))
		return;
	
	std::string date;
    std::string value;
	
	while (1){
    if (!std::getline(dataFile, date, ','))
        break;

    if (std::getline(dataFile, value))
    {
        double dValue = strtod(value.c_str(), NULL);
        _data[date] = dValue;
    }
	}
	dataFile.close();
}

 bool BitcoinExchange::controlDate(const std::string &date)
{
    static const unsigned int daysInMonth[12] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int dayLimit;
    bool isLeap;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    for (int i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return (false);
    }

    year = static_cast<unsigned int>(
        std::strtoul(date.substr(0, 4).c_str(), NULL, 10));

    month = static_cast<unsigned int>(
        std::strtoul(date.substr(5, 2).c_str(), NULL, 10));

    day = static_cast<unsigned int>(
        std::strtoul(date.substr(8, 2).c_str(), NULL, 10));

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);

    isLeap = (year % 400 == 0 ||
              (year % 4 == 0 && year % 100 != 0));

    dayLimit = daysInMonth[month - 1];

    if (month == 2 && isLeap)
        dayLimit = 29;

    if (day > dayLimit)
        return (false);

    return (true);
}
bool BitcoinExchange::controlAmount(const std::string& amountStr, double& amountd)
{
    char *endptr;
    double d_val = strtod(amountStr.c_str(), &endptr);

    if (amountStr.c_str() == endptr || *endptr != '\0')
        return true;

    if (d_val < 0){	
		return true;
	}

    if (d_val > 1000.0){
        return true;	
	}
	
	amountd = d_val;
    
	return false;
}

void BitcoinExchange::inputFileRun(std::string input)
{
	std::string line;
	double amountd;
	
    std::ifstream file(input.c_str());

    if (!file.is_open())
	    throw NoInputExc();

    std::getline(file, line);
	
	if(line != "date | value")
		throw InputFormatExc();
   
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t pipe_pos = line.find('|');

        if (pipe_pos == std::string::npos)
        {
            std::cout << "Error on line --> " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe_pos);
        std::string amount = line.substr(pipe_pos + 1);

        while (!date.empty() && date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);

        while (!date.empty() && date[0] == ' ')
            date.erase(0, 1);

        while (!amount.empty() && amount[amount.size() - 1] == ' ')
            amount.erase(amount.size() - 1);

        while (!amount.empty() && amount[0] == ' ')
            amount.erase(0, 1);

        if (!controlDate(date)){
			std::cout << "Date error on line --> "<< line << std::endl;
            continue;
		}

        if (controlAmount(amount, amountd)){
			std::cout << "Value error on line --> "<< line << std::endl;
			continue;
		}
			

        std::map<std::string, double>::iterator it = _data.upper_bound(date);

        if (it == _data.begin())
        {
            std::cout << "No data available for this date --> "
                      << date << std::endl;
            continue;
        }

        --it;

        double exchange_rate = it->second;

        std::cout << date << " --> " << amount << " = "
                  << (amountd * exchange_rate) << std::endl;
    }

    file.close();
}
const char *BitcoinExchange::NoDataExc::what() const throw()
{
	return "ERROR : No \"data.csv\" file or failed to open the file!!";
}

const char *BitcoinExchange::NoInputExc::what() const throw()
{
	return "ERROR : No input file provided or failed to open the file!";
}

const char *BitcoinExchange::InputFormatExc::what() const throw()
{
	return "ERROR : Input file format isnt't correct!";
}