#include "Fixed.hpp"

int main( void ) {
	{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "Show max: " << Fixed::max( a, b ) << std::endl;


    a > b ? std::cout << "A is greater" << std::endl : std::cout << "B is greater" << std::endl;
    a < b ? std::cout << "A is smaller" << std::endl : std::cout << "B is smaller" << std::endl;
    a == b ? std::cout << "yeah" << std::endl : std::cout << "noup" << std::endl;
    a != b ? std::cout << "yeah" << std::endl : std::cout << "noup" << std::endl;
	}

    
	
}

