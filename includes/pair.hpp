/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:12:18 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/01 16:12:18 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template< class T1, class T2 >
struct pair {

public:
	typedef	T1				first_type;
	typedef	T2				second_type;
	

	pair();
	template<class U, class V> pair (const pair<U,V>& pr) : _first(pr._first), _second(pr._second) {};
	pair (const first_type& a, const second_type& b) : _first(a), _second(b) {} ;
	~pair();
	
protected:
	first_type	_first;
	second_type	_second;


};


}

#endif