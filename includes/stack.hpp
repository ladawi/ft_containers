/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:44 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 13:21:29 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {

template<class T, class Container = ft::vector<T> >
class	stack {

	public:

	typedef	T			value_type;
	typedef size_t		size_type;
	typedef Container	container_type;
	public:

	explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {};

	bool empty() const { return(this->_c.empty()); };

	size_type size() const { return(this->_c.size()); };

	value_type& top() { return (this->_c.back()); };

	const value_type& top() const { return (this->_c.back()); };

	void push (const value_type& val) { this->_c.push_back(val); };

	void pop() { this->_c.pop_back(); };

	bool operator==(const stack& rhs) const { return (this->_c == rhs._c); };
	bool operator!=(const stack& rhs) const { return (this->_c != rhs._c); };
	bool operator>(const stack& rhs) const { return (this->_c > rhs._c); };
	bool operator>=(const stack& rhs) const { return (this->_c >= rhs._c); };
	bool operator<=(const stack& rhs) const { return (this->_c <= rhs._c); };
	bool operator<(const stack& rhs) const { return (this->_c < rhs._c); };

	

	protected:

		container_type	_c;

};

}

#endif