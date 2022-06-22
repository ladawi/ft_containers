/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:03:37 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/22 11:35:49 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATTOR_HPP
# define VECTOR_ITERATTOR_HPP

# include "RandomAccessIterator.hpp"

namespace ft {

	template<class T>
	class vectorIterator : public RandomAccessIterator<T> {

	public:
		typedef T value_type;
		typedef T* pointer_type;
		typedef T& reference_type;
		typedef std::ptrdiff_t difference_type;


	public:
		vectorIterator(void) : RandomAccessIterator<T>() {};
		vectorIterator(const vectorIterator &x) : RandomAccessIterator<T>(x) {};
		vectorIterator(pointer_type x) : RandomAccessIterator<T>(x) {};
		~vectorIterator() {};

		vectorIterator &operator+=(difference_type n);
		vectorIterator &operator-=(difference_type n);
		
	};

	template <class T>
	vectorIterator<T> &vectorIterator<T>::operator+=(vectorIterator<T>::difference_type n)
	{
		this->_ptr += n;
		return *this;
	}

	template <class T>
	vectorIterator<T> &vectorIterator<T>::operator-=(vectorIterator<T>::difference_type n)
	{
		this->_ptr -= n;
		return *this;
	}
}
#endif