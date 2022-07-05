/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/05 18:56:00 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "Pair.hpp"
#include "node.hpp"
#include <map>
int	main()
{
	std::cout << "===================" << std::endl;

	ft::map<char, int> mymap;
	std::map<char, int> second;

	std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	std::cout << "is second empty ? " << second.empty() << std::endl;

	std::cout << "------" << std::endl;

	second.insert(std::pair<char,int>('a', 100));
	mymap.insert(ft::pair<char,int>('b', 12));
	mymap.insert(ft::pair<char,int>('*', 42));
	
	std::cout << "------" << std::endl;
	
	std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	std::cout << "is second empty ? " << second.empty() << std::endl;

	std::cout << "------" << std::endl;
	std::cout << "===================" << std::endl;

	std::cout << "node val mymap -> " << mymap._head->_value.second << std::endl;
	
	std::cout << "===================" << std::endl;
	return (0);
}