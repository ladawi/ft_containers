/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:55:34 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 19:08:56 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Bidirectional_Iterator.hpp"
# include "node.hpp"

namespace	ft {

	template<class T>
	class MapIterator {

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
		MapIterator(void) : _node() {};
		MapIterator(const MapIterator &x) : _node(x._node) {};
		MapIterator(const node_pointer x) : _node(x) {};
		~MapIterator() {};
		MapIterator		operator=(const MapIterator &x) { this->_node = x.node(); }

		MapIterator operator++(int) {
			
		};
		MapIterator &operator++() {};
		MapIterator operator--(int) {};
		MapIterator &operator--() {};



		reference_type operator*() const {
			return (this->node->value);
		};

		node_pointer	operator->() {
			return &(this->_node->value);
		};

		bool operator==(const MapIterator &rhs) const;
	};
}

#endif