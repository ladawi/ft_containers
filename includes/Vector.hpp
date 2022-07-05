#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "VectorIterators.hpp"
# include "ConstVectorIterators.hpp"
# include "Ft_iterators.hpp"
# include "sfinae_template.hpp"
# include "RevIterator.hpp"
# include "stdexcept"
# include "ft_utils.hpp"
# include <cmath>

namespace ft {


	template<class T, class allocator_type = std::allocator<T> >
	class	vector
	{

		public:
			typedef size_t									size_type;
			typedef T										value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef value_type&								const_reference;
			typedef typename allocator_type::pointer		pointer;

			typedef ft::vectorIterator<T>					iterator;
			typedef ft::constVectorIterator<T>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:

			size_t			_size;
			size_t			_capacity;
			T*				_array;
			allocator_type	_alloc;

		public:
	/*
		=========================== Member functions ===========================
	*/
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
			vector(typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type())
				: _size(0), _capacity(0), _array(NULL), _alloc(alloc)
			{
				assign(first, last);
				// alloc = 0; // to remove
			}

			vector &		operator=( vector const & rhs ) {
				assign(rhs.begin(), rhs.end());
				return *this;
			};
	/*
		=============================== Iterator ===============================
	*/

			iterator	begin() { return (_array); }

			iterator	end() { return (_array + _size); }

			const_iterator	begin() const { return (_array); }

			const_iterator	end() const { return (_array + _size); }

			reverse_iterator	rbegin() { return (end()); }

			reverse_iterator	rend() { return (begin()); }




	/*
		=============================== Capacity ===============================
	*/

			size_type	size(void) const {
				return(_size);
			}

			void	resize(size_type n, value_type val = value_type()) {
				if (_size > n)
				{
					while (_size > n)
					{
						erase(this->begin() + n, this->end());
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
				return (allocator_type().max_size());
			}

			bool	empty() const {
				return(_size == 0);
			}

			size_type	capacity() const {
				return(_capacity);
			}

	/*
		============================ Element access ============================
	*/

		T&	operator[](unsigned int i) {
			return (_array[i]);
		};

		T& at(size_t n) {
			if (n < 0 || n >= _size)
				throw std::out_of_range("OOR acces : n >= .size()");
			return (_array[n]);
		};

		const_reference at(size_type n) const {
			if (n < 0 || n >= _size)
				throw std::out_of_range("OOR acces : n >= .size()");
			return (_array[n]);
		};

		T& front() const {
			return _array[0];
		}

		T& back() const {
			return _array[_size - 1];
		}



	/*
		=============================== Modifiers ==============================
	*/
		void	push_back(const value_type &val) {
			this->insert(this->end(), val);
		};

		void	pop_back()
		{
			if (_size > 0)
				_size--;
		}

		iterator insert(iterator position, const value_type &val)
		{
			difference_type n = position - this->begin();
			this->insert(position, 1, val);
			return (this->begin() + n);
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
		void insert(iterator position, InputIterator first, typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type last)
		{
			size_type delta = position - this->begin();
			size_type n = 0;

			for (InputIterator it = first; it != last; it++)
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
			for (iterator it = position; it != position + n; ++it)
				*it = *first++;
		}


		iterator erase(iterator position) {
			return (erase(position, position + 1));
		};

		iterator erase(iterator first, iterator last) {
			size_type	delta = last - first;
			size_type	offset = first - this->begin();

			for (size_type i = 0; i < _size - delta - offset; i++)
			{
				*first = *ft::next(first, delta);
				first++;
			}
			_size = _size - delta;
			return (this->begin() + offset);
		};

		template <class InputIterator>
		void assign(typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			this->clear();
			this->insert(this->begin(), first, last);
		};

		void assign (size_type n, const value_type& val) {
			this->clear();
			this->reserve(n);
			this->insert(this->begin(), n, val);
		};

		template <class vector>
		void swap (vector& x) {
			pointer		tmp_array = this->_array;
			size_type	tmp_size = this->_size;
			size_type	tmp_capacity = this->_capacity;

			this->_array = x._array;
			this->_size = x._size;
			this->_capacity = x._capacity;

			x._array = tmp_array;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		};

		void	clear() {
			erase(this->begin(), this->end());
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

		bool	operator<(const vector &rhs) const {
			return(std::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end()));
		}

		bool	operator>(const vector &rhs) const {
			return (!(std::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())) && this->operator!=(rhs));
		}

		bool	operator>=(const vector &rhs) const {
			return (!(std::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())));
		}

		bool	operator<=(const vector &rhs) const {
			return ((std::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())) || this->operator==(rhs));
		}

	/*
		============================== End public ==============================
	*/
	};

}

#endif /* ********************************************************** vector_H */