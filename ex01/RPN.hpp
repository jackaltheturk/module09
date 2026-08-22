/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:14:49 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 19:36:32 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <iostream>
#include <cctype>
#include <string>

class RPN
{
    private:
        std::list<int> storage;

    public:
        RPN();
        ~RPN();
        RPN(const RPN& source);
        RPN& operator=(const RPN& other);

        void run(const std::string& matExpression);
};

#endif