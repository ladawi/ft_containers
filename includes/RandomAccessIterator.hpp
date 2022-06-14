/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:24:20 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/14 19:27:19 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {
template<class T>
	class RandomAccessIterator {

		public:
			typedef T value_type;
			typedef T* pointer_type;
			typedef T& reference_type;
			typedef std::ptrdiff_t difference_type;

		public:
			RandomAccessIterator() : _ptr(NULL) {};
			RandomAccessIterator(pointer_type x) : _ptr(x) {};
			RandomAccessIterator(const RandomAccessIterator &x) { *this = x; };
			~RandomAccessIterator() {};

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

			reference_type	operator*() {
				return (*_ptr);
			}

			pointer_type	operator->() {
				return (_ptr);
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

			reference_type	operator[](size_t index) {
				return *(_ptr + index);
			}

			difference_type	operator-(const RandomAccessIterator &rhs) const {
				return (_ptr - rhs->_ptr);
			}

			RandomAccessIterator<value_type>	operator+(difference_type n) const {
				return (random_access_iterator(_ptr + n));
			}

			RandomAccessIterator<value_type>	operator-(difference_type n) const {
				return (random_access_iterator(_ptr - n));
			}


		protected:
			pointer_type _ptr;

	};
}


#endif