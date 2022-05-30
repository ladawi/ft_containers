/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:42:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/05/30 16:25:58 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"

int	main()
{
	std::vector<int> V1;
	Vector <int>V2;
	for (int i = 0; i < 10; i++)
		V1.push_back(i + 1);
	for (int& i : V1)
		std::cout << "V1 = " << i << " ." << std::endl;
	return (0);
}