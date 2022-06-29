/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:44 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/29 12:34:46 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {

template<class T, class container_type = ft::vector<T>>
class	stack {

	public:

	typedef	T		value_type;
	typedef size_t	size_type;

	explicit stack (const container_type& ctnr = container_type()) : _tmp(ctnr) {};



	bool	empty() const {
		return(_tmp.empty());
	}

	size_type	size(void) const {
		return(_tmp.size());
	}

	value_type&	top() {
		return(*(_tmp.end() - 1));
	}

	void push (const value_type& val) {
		_tmp.push_back(val);
	}


	private:

	protected:

		container_type	_tmp;

};

}

#endif