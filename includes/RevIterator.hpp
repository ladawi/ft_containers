/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RevIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:14:38 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/25 12:05:57 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERATOR_HPP
# define REV_ITERATOR_HPP

namespace ft {

	template <class Iterator>
	class reverse_iterator {

	protected:
		Iterator	_it;
		
	public:
		typedef Iterator value_type;
		typedef typename Iterator::pointer_type pointer_type;
		typedef typename Iterator::reference_type reference_type;
		typedef typename Iterator::difference_type difference_type;

		reverse_iterator(void) : _it() { } ;
		reverse_iterator(Iterator x) : _it(x) { } ;
		template <class U> reverse_iterator(const reverse_iterator<U> &x) : _it(x.base()) { };

		Iterator base(void) const { return this->_it; };

		reference_type operator*(void) { return ((--Iterator(this->_it)).operator*()); }
		pointer_type operator->(void) { return &this->operator*(); }

		reference_type	operator[](difference_type index) const { return *this->operator+(index); }
		
		reverse_iterator&	operator++() { this->_it.operator--(); return *this; }
		reverse_iterator	operator++(int) { return reverse_iterator(this->_it.operator--(0)); }
		reverse_iterator&	operator--() { this->_it.operator++();return *this; }
		reverse_iterator	operator--(int) {return reverse_iterator(this->_it.operator++(0)); }
		
		reverse_iterator	operator+=(difference_type n) { return this->_it.operator-=(n); }
		reverse_iterator	operator-=(difference_type n) { return this->_it.operator+=(n); }
		reverse_iterator	operator!=(difference_type n) { return this->_it.operator!=(n); }

		template <class U> bool	operator==(const reverse_iterator< U > &rhs) const { return (this->_it.operator==(rhs.base())); }
		template <class U> bool	operator!=(const reverse_iterator< U > &rhs) const { return (this->_it.operator!=(rhs.base())); }
		template <class U> bool	operator>(const reverse_iterator<U> &rhs) const { return(this->_it.operator<(rhs.base())); };
		template <class U> bool	operator<(const reverse_iterator<U> &rhs) const { return(this->_it.operator>(rhs.base())); };
		template <class U> bool	operator<=(const reverse_iterator<U> &rhs) const { return(this->_it.operator>=(rhs.base())); };
		template <class U> bool	operator>=(const reverse_iterator<U> &rhs) const { return(this->_it.operator<=(rhs.base())); };

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs) { return rhs.operator+(n); };


		reverse_iterator	operator+(difference_type n) const { return this->_it.operator-(n); };
		reverse_iterator	operator-(difference_type n) const { return (this->_it.operator+(n)); }

		template <class U>
		difference_type		operator-(reverse_iterator<U> &rhs) const { return (rhs.base().operator-(this->base())); };
		
	
	
	private:

	};
}


#endif