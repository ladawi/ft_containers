/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/04 13:06:09 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"

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
	std::cout << std::endl << "===========================" << std::endl << std::endl;
	
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	Vector<int> third (second.begin(),second.end());
	for (int i = 0; i < 4; i++)
	{
		std::cout << third[i] << std::endl;
	}
	return (0);
}