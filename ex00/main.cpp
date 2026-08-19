/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:28 by etorun            #+#    #+#             */
/*   Updated: 2026/08/19 12:04:19 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange transaction;
		transaction.Database();
		//transaction.InputFile(argv[1]);
		//transaction.Run();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}