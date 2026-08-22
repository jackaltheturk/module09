/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:28 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 15:49:11 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
   	if (argc != 2)
	{
		std::cerr << "Usage = ./RPN \"Mathematical expression\"" << std::endl;
		return (1);
	}
    try
    {
		RPN sample;
        sample.run(argv[1]);        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	return 0;
}