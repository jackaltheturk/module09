/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:14:58 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 13:36:10 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& source)
{
    this->storage = source.storage;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
    {
        this->storage = other.storage;
    }
    return *this;
}

void RPN::run(const std::string& matExpression)
{
	
}