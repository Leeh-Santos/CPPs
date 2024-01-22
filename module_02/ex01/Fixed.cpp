# include "Fixed.hpp"

Fixed::Fixed(){  
    std::cout << "Default Constructor Called" << std::endl;
    _fixedPoint = 0;
}

Fixed::~Fixed(){
    std::cout << "Destructor calles" << std::endl;

}

Fixed::Fixed(const Fixed& copy ){
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=( const Fixed& copy ){
    std::cout << "Copy assignment operator Called" << std::endl;

}

Fixed::Fixed( const int& value ){

}

Fixed::Fixed( const float& value ){

}

void Fixed::setRawBits( int const raw ){
    this->_fixedPoint = raw;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}


float	Fixed::toFloat( void ) const{

}

int		Fixed::toInt( void ) const{

}

std::ostream& operator<<( std::ostream& os, const Fixed& obj ){

}
