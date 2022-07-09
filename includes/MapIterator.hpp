/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:18:58 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/09 16:11:36 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "CoreMapIterator.hpp"

namespace	ft {

	template<class T, class Comp>
	class MapIterator : public CoreMapIterator<T, Comp> {

	private:

		typedef	CoreMapIterator<T, Comp>	_it;

	public:

		typedef typename _it::value_type 				value_type;
		typedef typename _it::pointer_type				pointer_type;
		typedef typename _it::reference_type				reference_type;
		typedef typename _it::difference_type			difference_type;
		typedef typename _it::iterator_category			iterator_category;

	private:

		typedef ft::node<value_type>			__node;
		typedef	__node*							_node_pointer;
		typedef	__node&							_node_reference;
		typedef Comp							value_compare;

	public:

		MapIterator() : CoreMapIterator<T, Comp>() {};
		MapIterator(const _node_pointer x) : CoreMapIterator<T, Comp>(x) {};
		MapIterator(const MapIterator &x) : CoreMapIterator<T, Comp>(x) {};
		~MapIterator() {};

		MapIterator		&operator++() {_it::operator++(); return *this; }
		MapIterator		&operator--() {_it::operator--(); return *this; }
		MapIterator		operator++(int) {
			MapIterator tmp(*this);
			operator++();
			return tmp;
		}
		MapIterator		operator--(int) {
			MapIterator tmp(*this);
			operator--();
			return tmp;
		}

		reference_type operator*() const {
			return (this->_node->value);
		};

		pointer_type operator->() const {
			return &(this->_node->value);
		};


	};
}


#endif