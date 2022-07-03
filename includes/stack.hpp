/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:44 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/01 14:48:53 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {

template<class T, class container_type = ft::vector<T> >
class	stack {

	public:

	typedef	T		value_type;
	typedef size_t	size_type;

	explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {};
	~stack() {};
	bool	empty() const	{ return(_c.empty()); }

	size_type	size(void) const	{ return(_c.size()); }

	value_type&	top()	{ return(*(_c.end() - 1)); }

	void	push (const value_type& val)	{ _c.push_back(val); }

	void	pop()	{ _c.pop_back(); }

	bool operator==(const stack& rhs) const	{ return (_c.operator==(rhs._c)); }
	bool operator!=(const stack& rhs) const	{ return (_c.operator!=(rhs._c)); }
	bool operator>=(const stack& rhs) const	{ return (_c.operator>=(rhs._c)); }
	bool operator<=(const stack& rhs) const	{ return (_c.operator<=(rhs._c)); }
	bool operator<(const stack& rhs) const	{ return (_c.operator<(rhs._c)); }
	bool operator>(const stack& rhs) const	{ return (_c.operator>(rhs._c)); }


	protected:

		container_type	_c;

};

}

#endif