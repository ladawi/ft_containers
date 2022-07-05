/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:44 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/05 16:29:06 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {

template<class T, class container_type = ft::vector<T> >
class	Stack {

	public:

	typedef	T		value_type;
	
	private:

	protected:

		container_type	_c;

};

}

#endif