/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:09 by etorun            #+#    #+#             */
/*   Updated: 2026/08/19 12:05:50 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <fstream>
# include <exception>
# include <map>
# include <cctype>
#include <iostream>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &sample);
		BitcoinExchange &operator=(const BitcoinExchange &source);
		~BitcoinExchange();
		void Database();
		
		class NoDataExc : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NoInputExc : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class DataFormatExc : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class InputFormatExc : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif