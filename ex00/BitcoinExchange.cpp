/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:13 by etorun            #+#    #+#             */
/*   Updated: 2026/08/20 07:22:27 by etorun           ###   ########.fr       */
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
	if (line != "date,exchange_rate")
		throw DataFormatExc();
	do
	{
		std::cout << "deneme"<< std::endl;
	}while(std::getline(dataFile, line));
	
}
static bool controlDate(const std::string &date)
{
	unsigned int				year;
	unsigned int				month;
	unsigned int				day;
	char						*end;
	bool						isLeap;
	unsigned int				dayLimit;
	static const unsigned int	daysInMonth[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.empty() || date.size() != 10
		|| date[4] != '-' || date[7] != '-')
		return (false);

	year = static_cast<unsigned int>(std::strtoul(date.substr(0, 4).c_str(), &end, 10));
	if (*end != '\0')
		return (false);

	month = static_cast<unsigned int>(std::strtoul(date.substr(5, 2).c_str(), &end, 10));
	if (*end != '\0')
		return (false);

	day = static_cast<unsigned int>(std::strtoul(date.substr(8, 2).c_str(), &end, 10));
	if (*end != '\0')
		return (false);

	if (year == 0 || month == 0 || month > 12 || day == 0 || day > 31)
		return (false);

	isLeap = (year % 400 == 0|| (year % 4 == 0 && year % 100 != 0));

	dayLimit = daysInMonth[month - 1];

	if (month == 2 && isLeap)
		dayLimit = 29;

	if (day > dayLimit)
		return (false);

	return (true);
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
	return "ERROR : Input file format ain't correct!";
}

const char *BitcoinExchange::DataFormatExc::what() const throw()
{
	return "ERROR : Database format ain't correct!";
}