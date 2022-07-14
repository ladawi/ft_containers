/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:24:20 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/14 13:17:12 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "Ft_iterators.hpp"

namespace ft {
template<class T>
	class RandomAccessIterator {

		public:
			typedef T value;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef ft::random_access_iterator_tag iterator_category;

		public:
			RandomAccessIterator() : _ptr(NULL) {};
			RandomAccessIterator(pointer x) : _ptr(x) {};
			RandomAccessIterator(const RandomAccessIterator &x) { *this = x; };
			virtual ~RandomAccessIterator() {};

			bool	operator==(const RandomAccessIterator& rhs) const {
				return (_ptr == rhs._ptr);
			}

			bool	operator!=(const RandomAccessIterator& rhs) const {
				return !(*this == rhs);
			}

			bool	operator>(const RandomAccessIterator& rhs) const {
				return (_ptr > rhs._ptr);
			}

			bool	operator>=(const RandomAccessIterator& rhs) const {
				return (_ptr >= rhs._ptr);
			}

			bool	operator<(const RandomAccessIterator& rhs) const {
				return (_ptr < rhs._ptr);
			}

			bool	operator<=(const RandomAccessIterator& rhs) const {
				return (_ptr <= rhs._ptr);
			}

			reference	operator*() {
				return (*_ptr);
			}

			pointer	operator->() {
				return (_ptr);
			}

			RandomAccessIterator&	operator=(const RandomAccessIterator &rhs) {
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			}
			
			RandomAccessIterator&	operator++() {
				_ptr++;
				return (*this);
			}
			
			RandomAccessIterator	operator++(int) {
				RandomAccessIterator iterator = *this;
				++(*this);
				return (iterator);
			}

			RandomAccessIterator&	operator--() {
				_ptr--;
				return (*this);
			}
			RandomAccessIterator	operator--(int) {
				RandomAccessIterator iterator = *this;
				--(*this);
				return (iterator);
			}

			reference	operator[](size_t index) {
				return *(_ptr + index);
			}

			difference_type	operator-(const RandomAccessIterator &rhs) const {
				return (_ptr - rhs._ptr);
			}

			RandomAccessIterator<value>	operator+(difference_type n) const {
				return (RandomAccessIterator(_ptr + n));
			}

			RandomAccessIterator<value>	operator-(difference_type n) const {
				return (RandomAccessIterator(_ptr - n));
			}
			friend RandomAccessIterator<value>	operator+(difference_type n, const RandomAccessIterator &rhs)
				{ return rhs.operator+(n); };


		protected:
			pointer _ptr;

	};
}


#endif