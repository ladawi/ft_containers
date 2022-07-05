/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:42:24 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/05 18:37:38 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "Pair.hpp"

namespace	ft {

	template<class T>
	class	node {

	public:

		typedef size_t				size_type;
		typedef T					value_type;
		typedef std::ptrdiff_t		difference_type;
		typedef value_type&			reference;
		typedef value_type*			pointer;

	public:

		node< T >() : _parent(0), _left(0), _right(0), _value() {};
		node< T >(value_type const &x) : _value(x), _parent(0), _left(0), _right(0) {};
		node< T >(const node &x) : _value(x._value), _parent(x._parent), _left(x._left), _right(x._right) {};
		~node< T >() {};

		node &	operator=(node const &rhs) {
			_parent = rhs._parent;
			_left = rhs._left;
			_right = rhs._right;
			_value = rhs._value;
			return (*this);
		}

		pointer		_parent;
		pointer		_right;
		pointer		_left;

		value_type	_value;

	};

}

#endif