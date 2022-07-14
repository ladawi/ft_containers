/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:05:11 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/14 14:22:37 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

namespace ft {

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2) {
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	};

	template <class T>
	struct less {
		bool operator()(const T &lhs, const T &rhs) const {
			return (lhs < rhs);
		}
	};

	template <class T> const T& max (const T& a, const T& b) {
	return ((a < b) ? b : a);	// or: return comp(a,b)?b:a; for version (2)
	}

	template <class T> void ftswap ( T& a, T& b )
	{
		T c(a); a=b; b=c;
	}
}

#endif