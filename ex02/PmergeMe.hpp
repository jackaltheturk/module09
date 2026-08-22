/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:31:47 by etorun            #+#    #+#             */
/*   Updated: 2026/08/22 17:31:47 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sys/time.h>

class PmergeMe
{
    private:    

        std::vector<std::pair<int, int> > _vect;
        std::deque<std::pair<int, int> > _deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& other);

        

       
};

#endif

