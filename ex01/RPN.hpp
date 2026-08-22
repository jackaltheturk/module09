/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:14:49 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 17:22:39 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cctype>

class RPN
{
    private:
        std::stack<int> storage;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& source);
        RPN& operator=(const RPN& other);

        void run(const std::string& matExpression);
};
#endif