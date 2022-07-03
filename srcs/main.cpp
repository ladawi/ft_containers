/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/01 15:42:43 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"
#include "stack.hpp"
#include "pair.hpp"


int	main()
{
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	// ft::vector<int> third (second.begin(),second.end());

	// first.push_back(99);
	// first.push_back(34);
	// first.push_back(1);
	// first.push_back(123);
	// first.push_back(42);
	// first.push_back(41);
	// first.reserve(17);
	// first.push_back(43);
	// first.push_back(44);
	
	// std::cout << "non." << std::endl;
	// auto i = first.end();
	// int count = 0;
	// for (auto z = first.begin(); z != i; z++)
	// {
	// 	std::cout << "issou = " << *z << std::endl;
	// 	if (count == 3)
	// 		first.insert(z ,420);
	// 	count++;
	// }
	// std::cout << "=============" << std::endl;

	// for (auto& i : first)
	// {
	// 	std::cout << "__ : " << i << std::endl;
	// }

	// first.insert(first.begin(), second.begin(), second.end());
	// std::cout << "=============" << std::endl;
	// bool v1;
	// ft::vectorIterator<int> it;
	// std::cout << "-> " << (ft::is_input_iterator<ft::vectorIterator<int>>::value) << std::endl;
	// std::cout << "" << std::endl;
	// for (auto& i : first)
	// {
	// 	std::cout << "-> : " << i << std::endl;
	// }
	// std::cout << "=============" << std::endl;
	// std::cout << "removing : " << *(first.begin() + 5) << std::endl;
	// first.erase(first.begin(), first.begin() + 5);
	std::cout << "===================" << std::endl;

	ft::stack<int> Monaks;
	// Monaks.push_back(12);
		std::cout << "empty? -> " << Monaks.empty() << std::endl;
		std::cout << "_size -> " << Monaks.size() << std::endl;
		std::cout << "top -> " << Monaks.top() << std::endl;
		std::cout << "push" << std::endl;
		Monaks.push(42);
		Monaks.push(21);
		Monaks.pop();
		Monaks.push(29);
		Monaks.pop();

	ft::stack<int> Lulw(Monaks);

	std::cout << "Monaks == Lulw -> " << (Monaks == Lulw) << std::endl;
	Monaks.push(27);
	std::cout << "Monaks == Lulw -> " << (Monaks == Lulw) << std::endl;
	std::cout << "Monaks != Lulw -> " << (Monaks != Lulw) << std::endl;

	std::cout << "top -> " << Monaks.top() << std::endl;
	return (0);
}