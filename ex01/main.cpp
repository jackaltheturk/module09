/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 06:17:28 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 13:36:15 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
   	if (argc != 2)
	{
		std::cout << "Usage = ./RPN \"Mathematical expression\"" << std::endl;
		return (1);
	}
	
	return 0;
}