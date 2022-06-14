/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/14 21:13:42 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"


#define TESTED_TYPE int

void	is_empty(ft::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

int	main()
{
	// std::vector<int> V1;
	// Vector <int>V2(7, 42);
	// for (int i = 97; i < 123; i++)
	// {
	// 	V1.push_back(i + 1);
	// }
	// for (auto& w : V1)
	// 	std::cout << "V1 = " << V1[w] << " ." << std::endl;
	// std::cout << "----" << std::endl;
	// for (int i = 0; i < 7; i++)
	// {
	// 	std::cout << "V2 = " << V2[i] << " ." << std::endl;
	// }
	// std::cout << std::endl << "===========================" << std::endl << std::endl;

	// std::vector<char> V1bis;
	// // Vector <int>V2;
	// for (int i = 97; i < 123; i++)
	// {
	// 	V1bis.push_back(i);
	// }
	// for (auto& w : V1bis)
	// 	std::cout << "V1bis = " << w << " ." << std::endl;
	// std::cout << std::endl << "===========================" << std::endl << std::endl;
	
	ft::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());
	for (int i = 0; i < 4; i++)
	{
		std::cout << third[i] << std::endl;
	}

	first.push_back(99);
	first.push_back(34);
	first.push_back(1);
	first.push_back(123);
	first.push_back(42);

	for (auto& i : first)
	{
		std::cout << "issou = " << i << std::endl;
	}
	return (0);
}