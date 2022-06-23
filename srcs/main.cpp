/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/23 10:33:34 by ladawi           ###   ########.fr       */
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

	first.push_back(99);
	first.push_back(34);
	first.push_back(1);
	first.push_back(123);
	first.push_back(42);
	first.push_back(41);
	first.reserve(17);
	first.push_back(43);
	first.push_back(44);
	
	std::cout << "non." << std::endl;
	auto i = first.end();
	int count = 0;
	for (auto z = first.begin(); z != i; z++)
	{
		std::cout << "issou = " << *z << std::endl;
		if (count == 3)
			first.insert(z ,420);
		count++;
	}
	std::cout << "=============" << std::endl;

	for (auto& i : first)
	{
		std::cout << "__ : " << i << std::endl;
	}

	first.insert(first.begin(), second.begin(), second.end());
	std::cout << "=============" << std::endl;
	bool v1;
	ft::vectorIterator<int> it;
	std::cout << "-> " << (ft::is_input_iterator<ft::vectorIterator<int>>::value) << std::endl;
	std::cout << "" << std::endl;
	for (auto& i : first)
	{
		std::cout << "-> : " << i << std::endl;
	}
	return (0);
}