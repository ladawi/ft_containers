#ifndef vector_HPP
# define vector_HPP

# include <iostream>
# include <string>

namespace ft {
	template<typename Vector>
	class vectorIterator {

		public:
			using value_type = typename Vector::value_type;
			using pointer_type = value_type*;
			using reference_type = value_type&;

		public:
		
			vectorIterator(pointer_type ptr) : _ptr(ptr) {};

			vectorIterator& operator++() {
				_ptr++;
				return (*this);
			}
			vectorIterator operator++(int) {
				vectorIterator iterator = *this;
				++(*this);
				return (iterator);
			}

			vectorIterator& operator--() {
				_ptr--;
				return (*this);
			}
			vectorIterator operator--(int) {
				vectorIterator iterator = *this;
				--(*this);
				return (iterator);
			}

			reference_type operator[](size_t index) {
				return *(_ptr + index);
			}

			pointer_type operator->() {
				return (_ptr);
			}

			reference_type operator*() {
				return (*_ptr);
			}

			bool operator==(const vectorIterator& rhs) const {
				return (_ptr == rhs._ptr);
			}

			bool operator!=(const vectorIterator& rhs) const {
				return !(*this == rhs);
			}

		private:
			pointer_type _ptr;

	};

	template<typename T, class Allocator = std::allocator<T> >
	class	vector
	{

		public:
			using value_type = T;
			using Iterator = vectorIterator<vector<T>>;
	/*
		=========================== Member functions ===========================
	*/
		public:
			vector< T >() : _size(0), _capacity(0), _array(NULL) { 
				std::cout << "vector constructor\n";
			};

			vector< T >(size_t n, const T& val = T()) : _size(n), _capacity(n), _array(new T[n]) {
				std::cout << "vector fill constructor\n";
				for (size_t i = 0; i < n; i++)
				{
					_array[i] = val;
				
				}
			};

			vector< T >( vector const &rhs ) : _size(rhs.size()), _capacity(rhs.capacity()), _array(new T[_capacity]) {
				std::cout << "vector copy constructor\n";
				for (size_t i = 0; i < rhs.size(); i++)
				{
					_array[i] = rhs._array[i];
				}

			};

			~vector< T >() {
				std::cout << "vector destructor" << std::endl;
				delete [] _array;
			};

			template <class InputIterator>
			vector (InputIterator first, InputIterator last) : _size(0) {
				std::cout << "vector range constructor\n";
				size_t	i = 0;
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

			Iterator	begin() {
				return (Iterator (_array));
			}

			Iterator	end() {
				return (Iterator (_array + _size));
			}

	/*
		=============================== Capacity ===============================
	*/

			size_t	size(void) const {
				return(_size);
			};

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
		void	push_back(const T& val) {
			//TODO : what if full ?
			if (_size < _capacity)
			{
				_array[_size] = val;
				_size++;
			}
			else
			{
				_capacity *= 2; // size of the realloc, change it mb ?
				T* newarray = new T[_capacity];
				for (size_t i = 0; i < _size; i++)
				{
					newarray[i] = _array[i];
				}
				newarray[_size] = val;
				++_size;
				delete [] _array;
				_array = newarray;
			}
		};

		void	pop_back()
		{
			if (_size > 0)
				_size--;
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