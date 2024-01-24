# include "Fixed.hpp"

Fixed::Fixed(){  
    _fixedPoint = 0;
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed& copy ){
    *this = copy;
}

Fixed& Fixed::operator=( const Fixed& copy ){
    std::cout << "Copy assignment operator Called" << std::endl;
    _fixedPoint = copy.getRawBits();
    return *this;
}

Fixed::Fixed( const float& value ){
    std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(value * (1 << _bits));
}

Fixed::Fixed( const int& value ){
    std::cout << "Int constructor called" << std::endl;
	_fixedPoint = value << _bits;
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

bool    Fixed::operator>(Fixed const &obj) const{
    return _fixedPoint > obj._fixedPoint;
}

bool    Fixed::operator<(Fixed const &obj) const{
    return _fixedPoint < obj._fixedPoint;
}

bool    Fixed::operator<=(Fixed const &obj) const{
    return _fixedPoint <= obj._fixedPoint;
}

bool    Fixed::operator>=(Fixed const &obj) const{
    return _fixedPoint >= obj._fixedPoint;
}

bool    Fixed::operator!=(Fixed const &obj) const{
    return _fixedPoint != obj._fixedPoint;
}

bool    Fixed::operator==(Fixed const &obj) const{
    return _fixedPoint == obj._fixedPoint;
}

Fixed   Fixed::operator+(Fixed const &obj){
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed   Fixed::operator-(Fixed const &obj){
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed   Fixed::operator*(Fixed const &obj){
	return Fixed(this->toFloat() * obj.toFloat());
}
Fixed   Fixed::operator/(Fixed const &obj){
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed   &Fixed::operator++(void){ //++i - pre returns the ref
    this->_fixedPoint += 1;
    return *this;
}

Fixed   &Fixed::operator--(void){ //--i - pre returns the ref and no param
    this->_fixedPoint -= 1;
    return *this;
}

Fixed   Fixed::operator++(int){ //i++ - copy obj and receive int
    Fixed   temp(this->toFloat());
	this->_fixedPoint += 1;
	return temp;
}

Fixed   Fixed::operator--(int){ //i-- - copy obj and receive int
    Fixed   temp(this->toFloat());
	this->_fixedPoint -= 1;
	return temp;
}

Fixed   &Fixed::min(Fixed &obj1, Fixed &obj2){
    if (obj1.getRawBits() < obj2.getRawBits())
        return obj1;
    else
        return obj2;
}

Fixed       &Fixed::max(Fixed &obj1, Fixed &obj2){
    if (obj1.getRawBits() > obj2.getRawBits())
        return obj1;
    else
        return obj2;
}

const Fixed&    Fixed::max(Fixed const &obj1, Fixed  const &obj2){
    if (obj1.getRawBits() > obj2.getRawBits())
        return obj1;
    else
        return obj2;
}

const Fixed&    Fixed::min(Fixed const &obj1, Fixed  const &obj2){
    if (obj1.getRawBits() < obj2.getRawBits())
        return obj1;
    else
        return obj2;

}

std::ostream& operator<<( std::ostream& os, const Fixed& obj ){

    os << obj.toFloat();
    return os;
}

