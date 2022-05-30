#include "Vector.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Vector::Vector() : _size(0), _array(NULL)
{
	std::cout << "Default vector constructor\n";
}

Vector::Vector( const Vector & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Vector::~Vector()
{
	std::cout << "Default vector destructor" << std::endl;
	delete [] _array;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Vector &				Vector::operator=( Vector const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Vector const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int			Vector::size(void) const
{
	return(this->_size);
}

/* ************************************************************************** */