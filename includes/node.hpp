/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:42:24 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 18:23:11 by ladawi           ###   ########.fr       */
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
		typedef node&			reference;
		typedef node*			pointer;

	public:

		node< T >() : parent(0), left(0), right(0), value(), height(1) {};
		node< T >(value_type const &x) : value(x), parent(0), left(0), right(0), height(1) {};
		node< T >(const node &x) : value(x.value), parent(x.parent), left(x.left), right(x.right), height(x.height) {};
		~node< T >() {};

		node &	operator=(node const &rhs) {
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			value = rhs.value;
			height = rhs.height;
			return (*this);
		}

		value_type	value;

		pointer		parent;
		pointer		left;
		pointer		right;

		int			height;

	};

}

#endif