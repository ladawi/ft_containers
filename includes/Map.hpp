/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:11:05 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/02 16:59:57 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
# define MAP_HPP

# include "MapIterator.hpp"
# include "Ft_iterators.hpp"
# include "sfinae_template.hpp"
# include "RevIterator.hpp"
# include "stdexcept"
# include "ft_utils.hpp"
# include <cmath>

namespace ft {

	template < class Key,                                     // map::key_type
				class T,                                       // map::mapped_type
				class Compare = std::less<Key>,                     // map::key_compare
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
			
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			typedef ft::MapIterator<T>							iterator;

		public:
	/*
		=========================== Member functions ===========================
	*/
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			
			
	
	/*
		=============================== Iterator ===============================
	*/

	/*
		=============================== Capacity ===============================
	*/

	/*
		============================ Element access ============================
	*/

	/*
		=============================== Modifiers ==============================
	*/

	/*
		=============================== Overload ===============================
	*/

	/*
		============================== End public ==============================
	*/
};

}

#endif