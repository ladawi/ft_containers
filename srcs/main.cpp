/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 18:49:30 by ladawi           ###   ########.fr       */
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
	mymap.insert(ft::pair<char,int>('a', 42));
	mymap.insert(ft::pair<char,int>('b', 12));
	mymap.insert(ft::pair<char,int>('c', 1));
	mymap.insert(ft::pair<char,int>('r', 123));
	mymap.insert(ft::pair<char,int>('y', 312));
	mymap.insert(ft::pair<char,int>('d', 123123));
	
	std::cout << "------" << std::endl;
	
	std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	std::cout << "is second empty ? " << second.empty() << std::endl;

	std::cout << "------" << std::endl;
	std::cout << "===================" << std::endl;

	std::cout << "node val mymap -> " << mymap._head << std::endl;
	std::cout << "node val mymap R -> " << mymap._head->right << std::endl;
	std::cout << "node val mymap L -> " << mymap._head->left << std::endl;
	std::cout << "===================" << std::endl;
	
	mymap.printTree(mymap._head, NULL, 1);

	// std::cout << "Test : " << mymap.begin() << std::endl;
	
	auto it = second.begin();

	std::cout << "Test 1: " << it->first << std::endl;

	auto ite = mymap.begin();

	// std::cout << "Test 2: " << ite->first << std::endl;

	// std::cout << ite == _head << std::endl;

	std::cout << "===================" << std::endl;
	return (0);
}