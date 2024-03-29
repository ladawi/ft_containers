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


	template<class T, class Alloc = std::allocator<T> >
	class	vector
	{

		public:
			typedef size_t										size_type;
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::vectorIterator<T>						iterator;
			typedef ft::constVectorIterator<T>					const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;


		private:

			size_t					_size;
			size_t					_capacity;
			value_type*				_array;
			allocator_type			_alloc;

		public:
	/*
		=========================== Member functions ===========================
	*/
		explicit vector< T >(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc) {
			// _array = new value_type[0];
			_array = _alloc.allocate(0);
			// value_type_alloc.construct(_array);
		};

		explicit vector< T >(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
			// _array = new value_type[n];
			_array = _alloc.allocate(n);

			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(&_array[i], val);
				// _array[i] = val;
			}
		};

		vector< T >( vector const &x ) : _size(0), _capacity(0), _array(NULL), _alloc() {
			*this = x;
		};

		~vector() {
			this->clear();
			_alloc.deallocate(_array, _capacity);
		};

		template <class InputIterator>
		vector(typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type())
			: _size(0), _capacity(0), _array(NULL), _alloc(alloc)
		{
			assign(first, last);
		}

		vector &		operator=( vector const & x ) {
			assign(x.begin(), x.end());
			return *this;
		};


	/*
		=============================== Iterator ===============================
	*/


		iterator	begin() { return (_array); }
		iterator	end() { return (_array + _size); }
		reverse_iterator	rbegin() { return (end()); }
		reverse_iterator	rend() { return (begin()); }

		const_iterator	begin() const { return (_array); }
		const_iterator	end() const { return (_array + _size); }
		const_reverse_iterator	rbegin() const { return (end()); }
		const_reverse_iterator	rend() const { return (begin()); }

	/*
		=============================== Capacity ===============================
	*/

		size_type	size(void) const {
			return(_size);
		}

		void	resize(size_type n, value_type val = value_type()) {
			if (_size > n)
			{
				erase(this->begin() + n, this->end());
			}
			else
			{
				if (_capacity < n) {
					if (_size * 2 < n)
						this->reserve(n);
					else
						this->reserve(_size * 2);
				}
				while (_size < n)
					push_back(val);
			}
		}

		void	reserve (size_type n) {
			if (n > _capacity)
			{
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				// value_type	*newarray = new value_type[n];
				value_type	*newarray = _alloc.allocate(n);
				// _alloc.construct(&newarray[0], _array[0]);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&newarray[i], _array[i]);
					// newarray[i] = _array[i];
					_alloc.destroy(_array + i);
				}
				// newarray[_size] = val;
				// delete[] _array;
				_alloc.deallocate(_array, size());
				_array = newarray;

				_capacity = n;
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

		reference at(size_type n) const {
			if (n < 0 || n >= _size)
				throw std::out_of_range("OOR acces : n >= .size()");
			return (_array[n]);
		};

		reference front() { return _array[0]; }

		const_reference front() const { return _array[0]; };

		reference	back() { return *ft::prev(this->end()); };

		const_reference	back() const { return (*ft::prev(this->end())); };


	/*
		=============================== Modifiers ==============================
	*/
		void	push_back(const value_type &val) {
			this->insert(this->end(), val);
		};

		void	pop_back()
		{
			if (_size > 0) {
				_alloc.destroy(&_array[--_size]); }
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
				if (this->_size * 2 < this->_size + n)
					this->reserve(this->_size + n);
				else {
					this->reserve(this->_size * 2 + !this->_capacity); };
			}
			for (size_type i = 0 ; i < n ; i++)
				_alloc.construct(_array + _size + i, val);

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
				if (this->_size * 2 < this->_size + n)
					this->reserve(this->_size + n);
				else
					this->reserve(this->_size * 2 + !this->_capacity);
			}
			for (size_type i = 0 ; i < n ; i++)
				_alloc.construct(_array + _size + i, *first);
			position = this->begin();
			for (size_type i = 0; i < delta; i++)
				position++;
			_size += n;
			for (iterator it = ft::prev(this->end()); it != ft::next(position, n - 1); --it)
				*it = *ft::prev(it, n);
			for (iterator it = position; it != position + n; ++it)
				*it = *first++;
			// for(iterator it = position + n; it != end(); it++)
			// 	_alloc.destroy(&*it);
		}


		iterator erase(iterator position) {
			return (erase(position, position + 1));
		};

		iterator erase(iterator first, iterator last) {
			size_type	offset = first - this->begin();
			size_type	delta = last - first;

			for (size_type i = 0; i < _size - delta - offset; i++)
			{
				*first = *ft::next(first, delta);
				first++;
			}
			// _size = _size - delta;
			while (delta-- > 0) {
				_alloc.destroy(&_array[--_size]);
			}
			return (this->begin() + offset);
		};

		template <class InputIterator>
		void assign(typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			this->erase(this->begin(), this->end());
			this->insert(this->begin(), first, last);
		};

		void assign (size_type n, const value_type& val) {
			this->erase(this->begin(), this->end());
			this->reserve(n);
			this->insert(this->begin(), n, val);
		};

		template <class vector>
		void swap (vector& x) {
			ft::ftswap(_alloc, x._alloc);
			ft::ftswap(_size, x._size);
			ft::ftswap(_capacity, x._capacity);
			ft::ftswap(_array, x._array);
		};

		void	clear() {
			// erase(this->begin(), this->end());
			for (iterator it = begin(); it != end(); it++)
				_alloc.destroy(&*it);
			this->_size = 0;
		};
	/*
		=============================== Allocator ===============================
	*/
		allocator_type	get_allocator() const {
			return (_alloc);
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
			return(ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end()));
		}

		bool	operator>(const vector &rhs) const {
			return (!(ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())) && this->operator!=(rhs));
		}

		bool	operator>=(const vector &rhs) const {
			return (!(ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())));
		}

		bool	operator<=(const vector &rhs) const {
			return ((ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())) || this->operator==(rhs));
		}

	/*
		============================== End public ==============================
	*/
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	};

}

#endif /* ********************************************************** vector_H */