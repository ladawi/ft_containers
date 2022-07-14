/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfinae_template.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 08:09:34 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/14 11:07:57 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFINAE_TEMPLATE_HPP
#define SFINAE_TEMPLATE_HPP

namespace ft {

	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <typename T, typename U>
	struct	is_same { static const bool value = false; };

	template <typename T>
	struct	is_same<T, T> { static const bool value = false; };
	
	template <typename T>
	struct	is_integral { static const bool value = false; };

	template <>
	struct	is_integral<bool> { static const bool value = true; };
	
	template <>
	struct	is_integral<char> { static const bool value = true; };

	// template <>
	// struct	is_integral<char16_t> { static const bool value = true; };
	
	// template <>
	// struct	is_integral<char32_t> { static const bool value = true; };

	template <>
	struct	is_integral<wchar_t> { static const bool value = true; };
	
	template <>
	struct	is_integral<signed char> { static const bool value = true; };

	template <>
	struct	is_integral<short int> { static const bool value = true; };
	
	template <>
	struct	is_integral<int> { static const bool value = true; };

	template <>
	struct	is_integral<long int> { static const bool value = true; };
	
	template <>
	struct	is_integral<long long int> { static const bool value = true; };

	template <>
	struct	is_integral<unsigned char> { static const bool value = true; };
	
	template <>
	struct	is_integral<unsigned short int> { static const bool value = true; };

	template <>
	struct	is_integral<unsigned int> { static const bool value = true; };
	
	template <>
	struct	is_integral<unsigned long int> { static const bool value = true; };

	template <>
	struct	is_integral<unsigned long long int> { static const bool value = true; };

	template <class T>
	struct is_input_iterator<T *> { static const bool value = true; };

}


#endif