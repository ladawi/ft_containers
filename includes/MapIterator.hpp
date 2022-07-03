/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:55:34 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/02 16:48:19 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Bidirectional_Iterator.hpp"


namespace	ft {

	template<class T>
	class MapIterator : public Bidirectional_iterator<T> {

	public:
		typedef T value_type;
		typedef T* pointer_type;
		typedef T& reference_type;
		typedef std::ptrdiff_t difference_type;

	private:
		MapIterator(const Bidirectional_iterator<T> src) : Bidirectional_iterator<T>(src) {};

	public:
		MapIterator(void) : Bidirectional_iterator<T>() {};
		MapIterator(const MapIterator &x) : Bidirectional_iterator<T>(x) {};
		MapIterator(pointer_type x) : Bidirectional_iterator<T>(x) {};
		~MapIterator() {};

		// MapIterator &operator+=(difference_type n);
		// MapIterator &operator-=(difference_type n);

		// MapIterator operator+(difference_type n) const
		// {
		// 	return (MapIterator(Bidirectional_iterator<T>::operator+(n)));
		// };
		// difference_type operator-(const Bidirectional_iterator<T> &rhs) const
		// {
		// 	return (Bidirectional_iterator<T>::operator-(rhs));
		// };
		// MapIterator operator-(difference_type n) const
		// {
		// 	return (MapIterator(Bidirectional_iterator<T>::operator-(n)));
		// };

		MapIterator &operator++()
		{
			this->_ptr++;
			return (*this);
		}

		MapIterator operator++(int)
		{
			MapIterator iterator = *this;
			++(*this);
			return (iterator);
		}
		
		MapIterator &operator--()
		{
			this->_ptr--;
			return (*this);
		}
		MapIterator operator--(int)
		{
			MapIterator iterator = *this;
			--(*this);
			return (iterator);
		}

		// friend MapIterator	operator+(difference_type n, const MapIterator &rhs) {
		// 		return rhs.operator+(n);
		// };

		pointer_type operator->(void)
		{
			return (this->_ptr);
		}
		reference_type operator*(void)
		{
			return (*this->_ptr);
		}

	};

	// template <class T>
	// MapIterator<T> &MapIterator<T>::operator+=(MapIterator<T>::difference_type n)
	// {
	// 	this->_ptr += n;
	// 	return *this;
	// }

	// template <class T>
	// MapIterator<T> &MapIterator<T>::operator-=(MapIterator<T>::difference_type n)
	// {
	// 	this->_ptr -= n;
	// 	return *this;
	// }
	
}

#endif