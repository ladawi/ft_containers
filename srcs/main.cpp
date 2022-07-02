/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/02 15:27:26 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"
#include "Stack.hpp"
#include "Pair.hpp"

int	main()
{
	std::cout << "===================" << std::endl;

	std::pair <std::string,int> planet, homeplanet;
	
	planet = std::make_pair("Earth",6371);

	homeplanet = planet;

	std::cout << "Home planet: " << homeplanet.first << '\n';
	std::cout << "Planet size: " << homeplanet.second << '\n';

	std::cout << "===================" << std::endl;

	ft::pair<int,char> foo (10,'z');
	ft::pair<int,char> bar (90,'a');
	
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	std::cout << "===================" << std::endl;

	ft::pair <int,int> foo2;
	ft::pair <int,int> bar2;

	foo2 = ft::make_pair (10,20);
	bar2 = ft::make_pair (10.5,'A');

	std::cout << "foo2: " << foo2.first << ", " << foo2.second << '\n';
	std::cout << "bar2: " << bar2.first << ", " << bar2.second << '\n';
	std::cout << "===================" << std::endl;
	return (0);
}