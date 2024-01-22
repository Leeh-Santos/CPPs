# include "Fixed.hpp"

Fixed::Fixed(){
    _fixedPoint = 0;
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj){
    std::cout << "copy constructor called" << std::endl;
    *this = obj; // copy assign being activated 
}

Fixed& Fixed::operator=(const Fixed &obj){
    std::cout << "copy assignment constructor called" << std::endl;
    this->_fixedPoint = obj.getRawBits(); // this->setRawBits(obj.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits( int const raw ){
    this->_fixedPoint = raw;
}