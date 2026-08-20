/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:28 by etorun            #+#    #+#             */
/*   Updated: 2026/08/20 06:25:13 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Usage = ./btc \"input file name\"" << std::endl;
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