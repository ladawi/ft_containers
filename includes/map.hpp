/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:11:05 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/05 18:58:21 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
# define MAP_HPP

# include "MapIterator.hpp"
# include "Ft_iterators.hpp"
# include "sfinae_template.hpp"
# include "RevIterator.hpp"
# include "Pair.hpp"
# include "stdexcept"
# include "ft_utils.hpp"
# include "node.hpp"
# include <cmath>

namespace ft {

	template < class Key,                                     // map::key_type
				class T,                                       // map::mapped_type
				class Compare = ft::less<Key>,                     // map::key_compare
				class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
				>
	class map {

		public:

			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef	pair<const key_type,mapped_type>			value_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef std::ptrdiff_t								difference_type;
			typedef size_t										size_type;

			typedef ft::node<value_type>						map_node;
			typedef map_node*									node_pointer;

			
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			typedef ft::MapIterator<T>							iterator;

		public:

			node_pointer	_head;
			allocator_type	_alloc;

		public:


	/*
		=========================== Member functions ===========================
	*/
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _head(0), _alloc(alloc)
			{
			};
			// map (const key_compare& kc, const allocator_type& alloc);
			// map< Key, T>();
			~map() {
				std::cout << "Destructor map called." << std::endl;
				delete _head;
			};
			
			
	
	/*
		=============================== Iterator ===============================
	*/

	/*
		=============================== Capacity ===============================
	*/
			bool empty() const {
				return(_head == 0 ? 1 : 0);
			};
	/*
		============================ Element access ============================
	*/

	/*
		=============================== Modifiers ==============================
	*/

			pair<iterator,bool> insert (const value_type& val) {
				if (!(_head)) {
					_head = new map_node(val);
				}
				else {
					
				}
				return (ft::pair<iterator,int>(NULL,1));
			};
	/*
		=============================== Overload ===============================
	*/

	/*
		============================== End public ==============================
	*/
};

}

#endif