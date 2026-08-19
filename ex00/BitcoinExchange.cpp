/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:13 by etorun            #+#    #+#             */
/*   Updated: 2026/08/19 12:06:47 by etorun           ###   ########.fr       */
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



const char *BitcoinExchange::NoDataExc::what() const throw()
{
	return "ERROR : There is no \"data.csv\" file!";
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