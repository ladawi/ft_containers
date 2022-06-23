/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:03:37 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/23 11:39:27 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "RandomAccessIterator.hpp"

namespace ft {

	template<class T>
	class vectorIterator : public RandomAccessIterator<T> {

	protected:
		vectorIterator(RandomAccessIterator<T> src) : RandomAccessIterator<T>(src){};
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

		vectorIterator operator+(difference_type n) const {
			return (vectorIterator(RandomAccessIterator<T>::operator+(n)));
		};
		difference_type operator-(const RandomAccessIterator<T> &rhs) const {
			return (RandomAccessIterator<T>::operator-(rhs));
		};
		vectorIterator operator-(difference_type n) const {
			return (vectorIterator(RandomAccessIterator<T>::operator-(n)));
		};
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