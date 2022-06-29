/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_iterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:36:35 by ladawi            #+#    #+#             */
/*   Updated: 2022/06/23 10:07:04 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR__HPP
# define FT_ITERATOR__HPP

namespace ft {

	struct input_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct bidirectional_iterator_tag : forward_iterator_tag {};
	struct random_access_iterator_tag : bidirectional_iterator_tag {};

	template <class T>
	struct is_input_iterator
	{
		typedef char yes[1];
		typedef char no[2];

		template <typename C>
		static yes &test(typename C::iterator_category *);

		template <typename>
		static no &test(...);

		static const bool value = sizeof(test<T>(NULL)) == sizeof(yes);
	};

	template <class T>
	struct iterator_traits
	{
		typedef typename T::value_type			value_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
	};

	template <class it>
	struct iterator_traits<it *>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef it								value_type;
		typedef it								*pointer;
		typedef it								&reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};


	template <class It>
	void do_advance(It &it, typename ft::iterator_traits<It>::difference_type n,
		ft::random_access_iterator_tag)
	{
		it += n;
	}

	template <class It, class Distance>
	void advance(It &it, Distance n)
	{
		ft::do_advance(it, typename ft::iterator_traits<It>::difference_type(n),
					   typename ft::iterator_traits<It>::iterator_category());
	}

	template <class BidirIt>
	BidirIt prev(BidirIt it, typename ft::iterator_traits<BidirIt>::difference_type n = 1)
	{
		ft::advance(it, -n);
		return (it);
	}

	template <class BidirIt>
	BidirIt next(BidirIt it, typename ft::iterator_traits<BidirIt>::difference_type n = 1)
	{
		ft::advance(it, n);
		return (it);
	}

}

#endif