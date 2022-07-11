/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/11 17:03:36 by ladawi           ###   ########.fr       */
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
#include <list>


#define _pair ft::pair

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

int	main()
{
	std::cout << "===================" << std::endl;

	ft::map<int, int> second;
	// ft::map<char, int> mymap;

	// std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	std::cout << "is second empty ? " << second.empty() << std::endl;

	std::cout << "------" << std::endl;

	second.insert(ft::pair<int,int>(1, 42));
	second.insert(ft::pair<int,int>(2, 12));
	second.insert(ft::pair<int,int>(3, 1));
	second.insert(ft::pair<int,int>(4, 1));
	second.insert(ft::pair<int,int>(5, 123));
	second.insert(ft::pair<int,int>(6, 123123));
	second.insert(ft::pair<int,int>(7, 312));
	second.insert(ft::pair<int,int>(8, 312));
	second.insert(ft::pair<int,int>(9, 312));
	// second.insert(ft::pair<int,int>(9, 1717));


	// mymap.insert(ft::pair<char,int>('a', 42));
	// mymap.insert(ft::pair<char,int>('b', 12));
	// mymap.insert(ft::pair<char,int>('c', 1));
	// mymap.insert(ft::pair<char,int>('r', 123));
	// mymap.insert(ft::pair<char,int>('y', 312));
	// mymap.insert(ft::pair<char,int>('d', 123123));
	ft::map<int, int> mymap(second.begin(), second.end());
	
	std::cout << "------" << std::endl;
	
	std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	std::cout << "is second empty ? " << second.empty() << std::endl;

	std::cout << "------" << std::endl;
	std::cout << "===================" << std::endl;

	// std::cout << "node val mymap -> " << mymap._head << std::endl;
	// std::cout << "node val mymap R -> " << mymap._head->right << std::endl;
	// std::cout << "node val mymap L -> " << mymap._head->left << std::endl;
	std::cout << "===================" << std::endl;
	
	// mymap.printTree(mymap._head, NULL, 1);
	std::cout << "===================" << std::endl;

	// auto it = second.begin();

	// for(auto it : second){
	// 	std::cout << "Test 1: " << (it).first << std::endl;
	// }

	// std::cout << "------" << std::endl;

	// for(auto it2 : mymap) {
	// 	std::cout << "Test 2: " << (it2).first << std::endl;
	// }
	// std::cout << "------" << std::endl;

	auto ite = mymap.end();
	std::cout << "Frog -> " << (second.equal_range('z')).second->first << std::endl;
	std::cout << "Frog -> " << (mymap.equal_range('z')).second->first << std::endl;


	std::cout << "===================" << std::endl;
	// mymap.printTree(mymap._head, NULL, 1);
	std::cout << "===================" << std::endl;

	auto iter = mymap.find(8);

	mymap.erase(iter);

	iter = mymap.find(9);
	mymap.erase(iter);

	iter = mymap.find(6);
	mymap.erase(iter);

	iter = mymap.find(5);
	mymap.erase(iter);
	std::cout << "===================" << std::endl;

	// mymap.printTree(mymap._head, NULL, 1);

	ft::map<int, int> third(mymap);

	std::cout << "===================" << std::endl;

	// std::cout << "mymap == second ? " << (mymap == second) << std::endl;
	if (mymap == second)
		std::cout << "mymap == second" << std::endl;
	else
		std::cout << "mymap != second" << std::endl;
	std::cout << "===================" << std::endl;

	mymap.swap(second);
	return (0);
}