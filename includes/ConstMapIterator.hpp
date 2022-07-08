/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstMapIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:55:34 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/08 12:14:41 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_MAP_ITERATOR_HPP
# define CONST_MAP_ITERATOR_HPP

# include "Bidirectional_Iterator.hpp"
# include "node.hpp"

namespace	ft {

	template<class T, class Comp>
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

		typedef Comp							value_compare;

	protected:

		node_pointer	_node;


	public:
		ConstMapIterator(void) : _node() {};
		ConstMapIterator(const ConstMapIterator &x) : _node(x._node) {};
		ConstMapIterator(const node_pointer x) : _node(x) {};
		~ConstMapIterator() {};
		ConstMapIterator		operator=(const ConstMapIterator &x) { this->_node = x._node; return *this; }

		ConstMapIterator &operator++() {
			if (!_node->right && _node->parent && value_compare()(_node->value, _node->parent->value)) {
				_node = _node->parent;
			}
			else if (!_node->right && _node->parent && value_compare()(_node->value, _node->parent->value)) {
				node_pointer	tmp = _node->parent;
				while (value_compare()(tmp->value, _node->value) && tmp->parent) {
					tmp = tmp->parent;
				}
				_node = tmp;
			}
			else
				_node = _find_min(_node->right);
			return *this;
		};
		ConstMapIterator operator++(int) {
			ConstMapIterator iterator = *this;
			++(*this);
			return (iterator);
		};
		ConstMapIterator &operator--() {
			if ((!_node->left && _node->parent && value_compare()(_node->parent->value, _node->value)) || (_node->left == _node->parent)) {
				_node = _node->parent;
			}
			else if (!_node->left && _node->parent && value_compare()(_node->value, _node->parent->value)) {
				node_pointer	tmp = _node->parent;
				while (value_compare()(_node->value, tmp->value) && tmp->parent) {
					tmp = tmp->parent;
				}
				_node = tmp;
			}
			else {
				_node = _find_max(_node->left);}
			return *this;
		};
		ConstMapIterator operator--(int) {
			ConstMapIterator iterator = *this;
			--(*this);
			return (iterator);
		};


		reference_type operator*() const {
			return (this->_node->value);
		};

		pointer_type	operator->() {
			return &(this->_node->value);
		};

		node_pointer	_find_min(node_pointer node) {
			if (!node || (node->parent == node->left))
				return (node);
			while (node->left)
				node = node->left;
			return (node);
		}

		node_pointer	_find_max(node_pointer node) {
			if (!node || (node->parent == node->right))
				return (node);
			while (node->right)
				node = node->right;
			return (node);
		}

		bool operator==(const ConstMapIterator &rhs) const {
			return (_node==(rhs._node));
		};
		bool operator!=(const ConstMapIterator &rhs) const {
			return (_node!=(rhs._node));
		};
	};
}

#endif