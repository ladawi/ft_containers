/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_Iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:14:27 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/02 16:27:13 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATTOR_HPP
# define BIDIRECTIONAL_ITERATTOR_HPP

# include "Ft_iterators.hpp"


namespace	ft	{

template<class T>
	class Bidirectional_iterator {

		public:
			typedef T value;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef ft::random_access_iterator_tag iterator_category;

		public:
			Bidirectional_iterator() : _ptr(NULL) {};
			Bidirectional_iterator(pointer x) : _ptr(x) {};
			Bidirectional_iterator(const Bidirectional_iterator &x) { *this = x; };
			virtual ~Bidirectional_iterator() {};

			bool	operator==(const Bidirectional_iterator& rhs) const {
				return (_ptr == rhs._ptr);
			}

			bool	operator!=(const Bidirectional_iterator& rhs) const {
				return !(*this == rhs);
			}

			reference	operator*() {
				return (*_ptr);
			}

			pointer	operator->() {
				return (_ptr);
			}

			Bidirectional_iterator&	operator=(const Bidirectional_iterator &rhs) {
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			}

			Bidirectional_iterator&	operator++() {
				_ptr++;
				return (*this);
			}
			
			Bidirectional_iterator	operator++(int) {
				Bidirectional_iterator iterator = *this;
				++(*this);
				return (iterator);
			}

			Bidirectional_iterator&	operator--() {
				_ptr--;
				return (*this);
			}
			Bidirectional_iterator	operator--(int) {
				Bidirectional_iterator iterator = *this;
				--(*this);
				return (iterator);
			}

		protected:
			pointer _ptr;

	};

}

#endif