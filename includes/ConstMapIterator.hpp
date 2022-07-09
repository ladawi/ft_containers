/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstMapIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:55:34 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/09 16:15:50 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_MAP_ITERATOR_HPP
# define CONST_MAP_ITERATOR_HPP

# include "Bidirectional_Iterator.hpp"
# include "node.hpp"
# include "CoreMapIterator.hpp"

namespace	ft {

	template<class T, class Comp>
	class ConstMapIterator : public CoreMapIterator<T, Comp> {

	private:

		typedef	CoreMapIterator<T, Comp>	_it;

	public:

		typedef typename _it::value_type 				value_type;
		typedef const value_type *						pointer_type;
		typedef const value_type &						reference_type;
		typedef typename _it::difference_type			difference_type;
		typedef typename _it::iterator_category			iterator_category;

	private:

		typedef ft::node<value_type>			__node;
		typedef	__node*							_node_pointer;
		typedef	__node&							_node_reference;
		typedef Comp							value_compare;

	public:

		ConstMapIterator() : CoreMapIterator<T, Comp>() {};
		ConstMapIterator(const ConstMapIterator &x) : CoreMapIterator<T, Comp>(x) {};
		ConstMapIterator(const _it &x) : CoreMapIterator<T, Comp>(x) {};
		ConstMapIterator(const _node_pointer x) : CoreMapIterator<T, Comp>(x) {};
		~ConstMapIterator() {};

		ConstMapIterator		&operator++() {_it::operator++(); return *this; }
		ConstMapIterator		&operator--() {_it::operator--(); return *this; }
		ConstMapIterator		operator++(int) { return _it::operator++(0); }
		ConstMapIterator		operator--(int) { return _it::operator--(0); }

		reference_type operator*() const {
			return (this->_node->value);
		};

		pointer_type operator->() const {
			return &(this->_node->value);
		};


	};
}

#endif