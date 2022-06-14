/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstVectorIterators.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:46:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/14 19:53:44 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_VECTOR_ITERATTOR_HPP
#define CONST_VECTOR_ITERATTOR_HPP

#include "RandomAccessIterator.hpp"

namespace ft
{

	template <class T>
	class const_vectorIterator : public RandomAccessIterator<T>
	{

	public:
		typedef T value_type;
		typedef T *pointer_type;
		typedef T &reference_type;
		typedef std::ptrdiff_t difference_type;

	public:
		const_vectorIterator(void) : RandomAccessIterator<T>() {};
		const_vectorIterator(const const_vectorIterator &x) : RandomAccessIterator<T>(x) {};
		const_vectorIterator(pointer_type x) : RandomAccessIterator<T>(x) {};

		
	};
}
#endif