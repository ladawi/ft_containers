#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
// namespace ft {

	template<typename T>
	class	Vector
	{

		public:

			Vector< T >() : _size(0), _array(NULL) { 
				std::cout << "Vector constructor\n";
			};

			Vector< T >(size_t n, const T& val) : _size(n) , _array(new T[n]) {
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
			Vector (InputIterator first, InputIterator last) {
				std::cout << "Vector range constructor\n";
				size_t	i = 0;
				InputIterator tmp = first;
				while (first != last)
				{
					i++;
					first++;
				}
				first = tmp;
				_size = i;
				_array = new T[i];
				i = 0;
				while (first != last)
				{
					_array[i++] = *first; 
					first++;
				}
			}

			Vector &		operator=( Vector const & rhs ) {
				return *this;
			};

			unsigned int size(void) const ;
			
			void push_back (const T & val) {
				
			};

			T&	operator[](unsigned int i) {
				return (_array[i]);
			};


		private:

			unsigned int	_size;
			T*				_array;

	};
// }
// std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */