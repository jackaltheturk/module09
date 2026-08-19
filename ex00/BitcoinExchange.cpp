/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:13 by etorun            #+#    #+#             */
/*   Updated: 2026/08/19 12:42:26 by etorun           ###   ########.fr       */
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
		
	}while(std::getline(dataFile, line));
	
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