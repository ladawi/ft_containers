#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "VectorIterators.hpp"
# include "ConstVectorIterators.hpp"
# include "Ft_iterators.hpp"

# include <cmath>

namespace ft {


	template<class T, class Allocator = std::allocator<T> >
	class	vector
	{

		public:
			typedef size_t						size_type;
			typedef T							value_type;
			typedef vectorIterator<T>			iterator;
			typedef const_vectorIterator<T>		const_iterator;
			typedef std::ptrdiff_t				difference_type;
			// typedef vectorReverseIterator<vector<T>> RevIterator;
	/*
		=========================== Member functions ===========================
	*/
		public:
			vector< T >() : _size(0), _capacity(0), _array(NULL) {};

			vector< T >(size_t n, const T& val = T()) : _size(n), _capacity(n), _array(new T[n]) {
				for (size_t i = 0; i < n; i++)
				{
					_array[i] = val;
				}
			};

			vector< T >( vector const &rhs ) : _size(rhs.size()), _capacity(rhs.capacity()), _array(new T[_capacity]) {
				for (size_t i = 0; i < rhs.size(); i++)
				{
					_array[i] = rhs._array[i];
				}

			};

			~vector< T >() {
				delete [] _array;
			};

			template <class InputIterator>
			vector (InputIterator first, InputIterator last) : _size(0) {
				size_type	i = 0;
				InputIterator tmp = first;
				while (first != last)
				{
					i++;
					first++;
				}
				first = tmp;
				_capacity = i;
				_array = new T[_capacity];
				while (first != last)
				{
					_array[_size++] = *first;
					first++;
				}
			}

			vector &		operator=( vector const & rhs ) {
				if (rhs._size >= _size)
				{
					delete [] _array;
					_capacity = rhs._size;
					_array = new T[_capacity];
				}
				for (size_t i = 0; i < rhs._size; i++)
				{
					_array[i] = rhs._array[i];
				}

				_size = rhs._size;
				return *this;
			};
	/*
		=============================== Iterator ===============================
	*/

			iterator	begin() { return (_array); }

			iterator	end() { return (_array + _size); }

			const_iterator	begin() const { return (_array); }

			const_iterator	end() const { return (_array + _size); }

			// iterator	begin() {
			// 	return (iterator (_array));
			// }

			// iterator	end() {
			// 	return (iterator (_array + _size));
			// }

	/*
		=============================== Capacity ===============================
	*/

			size_t	size(void) const {
				return(_size);
			}

			void	resize(size_type n, value_type val = value_type()) {
				if (_size > n)
				{
					while (_size > n)
					{
						pop_back();
					}
				}
				else
				{
					while (_size < n)
						push_back(val);
				}
			}

			void	reserve (size_type n) {
				if (n > _capacity)
				{
					T *newarray = new T[n];
					// std::cout << "Reserve called : " << _size << " capa = " << _array[0] << std::endl;
					for (size_type i = 0; i < _size; i++)
					{
						newarray[i] = _array[i];
					}
					// newarray[_size] = val;
					// ++_size;
					delete[] _array;
					_array = newarray;
					_capacity = n; // size of the realloc, change it mb ?
				}
			}

			size_type	max_size() const {
				return (pow(2, 32)/sizeof(value_type) - 1);
			}

			bool	empty() const {
				return(_size == 0);
			}

			size_t	capacity() const {
				return(_capacity);
			}

	/*
		============================ Element access ============================
	*/

			T&	operator[](unsigned int i) {
				return (_array[i]);
			};

			T& At(size_t n) {
				if (n < 0 || n >= _size)
					throw vector::OOBindex();
				return (_array[n]);
			};

			T& Front() {
				return _array[0];
			}

			T& Back() {
				return _array[_size - 1];
			}


	/*
		=============================== Modifiers ==============================
	*/
		void	push_back(const value_type &val) {
			this->insert(this->end(), val);
			// T issou = val;
		};

		void	pop_back()
		{
			if (_size > 0)
				_size--;
		}

		iterator insert(iterator position, const value_type &val) {
			this->insert(position, 1, val);
			return (this->begin());
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type delta = position - this->begin();

			if (this->_capacity < this->_size + n)
			{
				if (this->_capacity * 2 < this->_size + n)
					this->reserve(this->_size + n);
				else
					this->reserve(this->_capacity * 2 + !this->_capacity);
			}
			position = this->begin();
			for (size_type i = 0; i < delta; i++)
				position++;
			_size += n;
			for (iterator it = ft::prev(this->end()); it != ft::next(position, n - 1); --it)
				*it = *ft::prev(it, n);
			for (iterator it = position; it != position + n; ++it)
				*it = val;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			std::cout << "Iterator Insert called\n";
			size_type delta = position - this->begin();
			size_type n;

			for (auto it = first; it != last; it++)
			{
				n++;
			}

			if (this->_capacity < this->_size + n)
			{
				if (this->_capacity * 2 < this->_size + n)
					this->reserve(this->_size + n);
				else
					this->reserve(this->_capacity * 2 + !this->_capacity);
			}
			position = this->begin();
			for (size_type i = 0; i < delta; i++)
				position++;
			_size += n;
			for (iterator it = ft::prev(this->end()); it != ft::next(position, n - 1); --it)
				*it = *ft::prev(it, n);
			// for (iterator it = position; it != position + n; ++it)
			// 	*it = val;
		}

		/*
			================================ Except ================================
		*/

		class OOBindex : public std::out_of_range
		{
			public:
				virtual const char* what() const throw()
				{
					return("vector::_M_range_check");
				}
		};

	/*
		=============================== Overload ===============================
	*/

		bool operator==(const vector& rhs) const {
			if (size() != rhs.size())
				return false;

			for (size_t i = 0; i < size(); i++ )
			{
				if (_array[i] != rhs._array[i])
					return false;
			}

			return true;
		}

		bool operator!=(const vector& rhs) const {
			return !(*this == rhs);
		}

	/*
		============================== End public ==============================
	*/
		private:

			size_t		_size;
			size_t		_capacity;
			T*			_array;

	};

}

#endif /* ********************************************************** vector_H */