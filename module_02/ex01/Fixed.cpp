# include "Fixed.hpp"

Fixed::Fixed(){  
    std::cout << "Default Constructor Called" << std::endl;
    _fixedPoint = 0;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;

}

Fixed::Fixed(const Fixed& copy ){
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=( const Fixed& copy ){
    std::cout << "Copy assignment operator Called" << std::endl;
    _fixedPoint = copy.getRawBits();
    return *this;
}

Fixed::Fixed( const int& value ){
    std::cout << "Int constructor called" << std::endl;
	_fixedPoint = value << _bits;
}

Fixed::Fixed( const float& value ){
    std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(value * (1 << _bits));
}

void Fixed::setRawBits( int const raw ){
    this->_fixedPoint = raw;
}

int Fixed::getRawBits( void ) const{
    return _fixedPoint;
}


float	Fixed::toFloat( void ) const{
    return (((float)_fixedPoint) / (float)(1 << _bits));
}

int		Fixed::toInt( void ) const{
    return (_fixedPoint >> _bits);
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj ){

    os << obj.toFloat();
    return os;
}

