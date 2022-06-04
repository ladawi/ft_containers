#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
// namespace ft {

template<typename T, class Allocator = std::allocator<T> >
class	Vector
{

	public:

/*
		Member functions
*/
		Vector< T >() : _size(0), _capacity(0), _array(NULL) { 
			std::cout << "Vector constructor\n";
		};

		Vector< T >(size_t n, const T& val) : _size(0), _capacity(n), _array(new T[n]) {
			std::cout << "Vector fill constructor\n";
			for (size_t i = 0; i < n; i++)
			{
				_array[i] = val;
			}
		};

		Vector< T >( Vector const & src ) {
			std::cout << "Vector copy constructor\n";
		};

		~Vector< T >() {
			std::cout << "Vector destructor" << std::endl;	
		};

		template <class InputIterator>
		Vector (InputIterator first, InputIterator last) : _size(0) {
			std::cout << "Vector range constructor\n";
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

		Vector &		operator=( Vector const & rhs ) {
			return *this;
		};

/*
		Capacity
*/

		size_t size(void) const;

/*
		Element access
*/

		T&	operator[](unsigned int i) {
			return (_array[i]);
		};


/*
		Modifiers
*/

/*
		Except
*/

	class OOBindex : public std::out_of_range
	{
		public:
			virtual const char* what() const throw()
			{
				return("vector::_M_range_check");
			}
	};

	private:

		size_t		_size;
		size_t		_capacity;
		T*			_array;

};
// }
// std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */