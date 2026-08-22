/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:14:58 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 17:11:21 by etorun           ###   ########.fr       */
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
    if (matExpression.empty())
        throw std::runtime_error("Empty  Mathematical Expression");

    int i = 0;

    while (matExpression[i])
    {
        if (matExpression[i] == ' ')
        {
            i++;
            continue;
        }

        if ((std::isdigit(matExpression[i]) ||
             matExpression[i] == '*' ||
             matExpression[i] == '/' ||
             matExpression[i] == '+' ||
             matExpression[i] == '-') &&
            !(matExpression[i + 1] != ' ' && matExpression[i + 1] != '\0'))
        {
            if (std::isdigit(matExpression[i]))
                storage.push(matExpression[i] - '0');
            else
            {
                if (storage.size() < 2)
                    throw std::runtime_error("Not enough operands.");

                int number1 = storage.top();
                storage.pop();

                int number2 = storage.top();
                storage.pop();

                if (matExpression[i] == '*')
                    storage.push(number2 * number1);
                else if (matExpression[i] == '+')
                    storage.push(number2 + number1);
                else if (matExpression[i] == '-')
                    storage.push(number2 - number1);
                else if (matExpression[i] == '/')
                {
                    if (number1 == 0)
                        throw std::runtime_error("Dividing by zero is impossible.");

                    storage.push(number2 / number1);
                }
            }
            i++;
        }
        else
            throw std::runtime_error("Invalid character in expression.");
    }

    if (storage.size() != 1)
        throw std::runtime_error("Expression fault.");

    std::cout << storage.top() << std::endl;
}
