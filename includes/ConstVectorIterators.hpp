/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstVectorIterators.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:46:25 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/14 11:23:44 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_VECTOR_ITERATTOR_HPP
#define CONST_VECTOR_ITERATTOR_HPP

#include "RandomAccessIterator.hpp"

namespace ft
{

	template <class T>
	class constVectorIterator : public RandomAccessIterator<T>
	{

	public:
		typedef T value_type;
		typedef const T *pointer_type;
		typedef const T &reference_type;
		typedef std::ptrdiff_t difference_type;

	public:
		constVectorIterator(void) : RandomAccessIterator<T>() {};
		constVectorIterator(const constVectorIterator &x) : RandomAccessIterator<T>(x) {};
		constVectorIterator(T* x) : RandomAccessIterator<T>(x) {};
		constVectorIterator(const RandomAccessIterator<T> &src) : RandomAccessIterator<T>(src){};
		~constVectorIterator() {};


		constVectorIterator &operator+=(difference_type n);
		constVectorIterator &operator-=(difference_type n);

		constVectorIterator operator+(difference_type n) const	{
			return (constVectorIterator(RandomAccessIterator<T>::operator+(n)));
		};
		difference_type operator-(const RandomAccessIterator<T> &rhs) const	{
			return (RandomAccessIterator<T>::operator-(rhs));
		};
		constVectorIterator operator-(difference_type n) const	{
			return (constVectorIterator(RandomAccessIterator<T>::operator-(n)));
		};

		constVectorIterator &operator++() {
			this->_ptr++;
			return (*this);
		}

		constVectorIterator operator++(int) {
			constVectorIterator iterator = *this;
			++(*this);
			return (iterator);
		}
		
		constVectorIterator &operator--() {
			this->_ptr--;
			return (*this);
		}
		constVectorIterator operator--(int) {
			constVectorIterator iterator = *this;
			--(*this);
			return (iterator);
		}

		friend constVectorIterator	operator+(difference_type n, const constVectorIterator &rhs) {
				return rhs.operator+(n);
		};

		pointer_type operator->(void) {
			return (this->_ptr);
		}
		reference_type	operator*(void) {
			return (*this->_ptr);
		}
		reference_type operator[](size_t index)
		{
			return *(this->_ptr + index);
		}
	};

	template <class T>
	constVectorIterator<T> &constVectorIterator<T>::operator+=(constVectorIterator<T>::difference_type n)
	{
		this->_ptr += n;
		return *this;
	}

	template <class T>
	constVectorIterator<T> &constVectorIterator<T>::operator-=(constVectorIterator<T>::difference_type n)
	{
		this->_ptr -= n;
		return *this;
	}
}
#endif