#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

template<typename T>
class Vector
{

	public:

		Vector< T >();
		Vector< T >( Vector const & src );
		~Vector< T >();

		Vector &		operator=( Vector const & rhs );

		unsigned int size(void) const;

	private:

		unsigned int	_size;
		T*				_array;

};

std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */