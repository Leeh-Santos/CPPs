#include "WrongCat.hpp"


WrongCat::WrongCat( void ) {
	type = "WrongCat";
	std::cout <<  "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout <<  "WrongCat Default destructor called" << std::endl;
}

WrongCat::WrongCat ( const WrongCat& obj) : WrongAnimal() {
	std:: cout <<  "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=( const WrongCat& obj) {
	std::cout <<  "WrongCat assignment overload called" << std::endl;
	type = obj.type;
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout <<  "VRAAAAAAU" << std::endl;
}