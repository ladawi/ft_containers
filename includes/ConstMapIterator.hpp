/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstMapIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:55:34 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 19:08:54 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_MAP_ITERATOR_HPP
# define CONST_MAP_ITERATOR_HPP

# include "Bidirectional_Iterator.hpp"
# include "node.hpp"

namespace	ft {

	template<class T>
	class ConstMapIterator {

	public:
		typedef T value_type;
		typedef T* pointer_type;
		typedef T& reference_type;
		typedef std::ptrdiff_t difference_type;

		typedef ft::bidirectional_iterator_tag	iterator_category;
		
		typedef ft::node<value_type>			node;
		typedef node*							node_pointer;
		typedef node&							node_reference;

	protected:

		node_pointer	_node;


	public:
		ConstMapIterator(void) : _node() {};
		ConstMapIterator(const ConstMapIterator &x) : _node(x._node) {};
		ConstMapIterator(const node_pointer x) : _node(x) {};
		~ConstMapIterator() {};
		ConstMapIterator		operator=(const ConstMapIterator &x) { this->_node = x.node(); }

		ConstMapIterator operator++(int) {
			
		};
		ConstMapIterator &operator++() {};
		ConstMapIterator operator--(int) {};
		ConstMapIterator &operator--() {};



		reference_type operator*() const {
			return (this->node->value);
		};

		node_pointer	operator->() {
			return &(this->_node->value);
		};

		bool operator==(const ConstMapIterator &rhs) const;
	};
}

#endif