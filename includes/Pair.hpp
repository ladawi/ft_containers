/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:24:02 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 15:29:32 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft {

	template <class T1, class T2>
	struct pair {

		typedef	T1		first_type;
		typedef	T2		second_type;

		pair() : first(), second() {};
		template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};
		~pair() {};

		pair&	operator=(const pair &rhs) {
			this->first = rhs.first;
			this->second = rhs.second;
			return (*this);
		}

		first_type		first;
		second_type		second;

	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1,T2>(x, y) );
	}
}

#endif