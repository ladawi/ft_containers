/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/14 15:32:28 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "Pair.hpp"
#include "node.hpp"
#include <map>
#include <list>
#include <vector>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

#define _pair ft::pair
using namespace NAMESPACE;

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';


		for (map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
		std::cout << it->first << " => " << it->second << '\n';

		map<char, int>::const_reverse_iterator it = mymap.rbegin();
		map<char, int>::const_reverse_iterator ti = mymap.rend();

		it++;
		++it;
		it--;
		--it;

		ti--;
		--ti;
		++ti;
		ti++;

		ti = it;

		map<char, int>::reverse_iterator end = mymap.rend();
		while(it != end)
		{
			std::cout << it->first << " => " << it->second << '\n';
			it++;
		}


	return 0;
	// std::cout << "===================" << std::endl;

	// ft::map<int, int> second;
	// // ft::map<char, int> mymap;

	// // std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	// std::cout << "is second empty ? " << second.empty() << std::endl;

	// std::cout << "------" << std::endl;

	// second.insert(ft::pair<int,int>(1, 42));
	// second.insert(ft::pair<int,int>(2, 12));
	// second.insert(ft::pair<int,int>(3, 1));
	// second.insert(ft::pair<int,int>(4, 1));
	// second.insert(ft::pair<int,int>(5, 123));
	// second.insert(ft::pair<int,int>(6, 123123));
	// second.insert(ft::pair<int,int>(7, 312));
	// second.insert(ft::pair<int,int>(8, 312));
	// second.insert(ft::pair<int,int>(9, 312));
	// second.insert(ft::pair<int,int>(9, 1717));


	// ft::map<int, int> mymap(second.begin(), second.end());
	
	// std::cout << "------" << std::endl;
	
	// std::cout << "is mymap empty ? " << mymap.empty() << std::endl;
	// std::cout << "is second empty ? " << second.empty() << std::endl;

	// std::cout << "------" << std::endl;
	// std::cout << "===================" << std::endl;

	// // std::cout << "node val mymap -> " << mymap._head << std::endl;
	// // std::cout << "node val mymap R -> " << mymap._head->right << std::endl;
	// // std::cout << "node val mymap L -> " << mymap._head->left << std::endl;
	// std::cout << "===================" << std::endl;
	
	// // mymap.printTree(mymap._head, NULL, 1);
	// std::cout << "===================" << std::endl;

	// // auto it = second.begin();

	// // for(auto it : second){
	// // 	std::cout << "Test 1: " << (it).first << std::endl;
	// // }

	// // std::cout << "------" << std::endl;

	// // for(auto it2 : mymap) {
	// // 	std::cout << "Test 2: " << (it2).first << std::endl;
	// // }
	// // std::cout << "------" << std::endl;

	// auto ite = mymap.end();
	// std::cout << "Frog -> " << (second.equal_range('z')).second->first << std::endl;
	// std::cout << "Frog -> " << (mymap.equal_range('z')).second->first << std::endl;


	// std::cout << "===================" << std::endl;
	// // mymap.printTree(mymap._head, NULL, 1);
	// std::cout << "===================" << std::endl;

	// auto iter = mymap.find(8);

	// mymap.erase(iter);

	// iter = mymap.find(9);
	// mymap.erase(iter);

	// iter = mymap.find(6);
	// mymap.erase(iter);

	// iter = mymap.find(5);
	// mymap.erase(iter);
	// std::cout << "===================" << std::endl;

	// // mymap.printTree(mymap._head, NULL, 1);

	// ft::map<int, int> third(mymap);

	// std::cout << "===================" << std::endl;

	// // std::cout << "mymap == second ? " << (mymap == second) << std::endl;
	// if (mymap == second)
	// 	std::cout << "mymap == second" << std::endl;
	// else
	// 	std::cout << "mymap != second" << std::endl;
	// std::cout << "===================" << std::endl;

	// mymap.swap(second);
	return (0);
}