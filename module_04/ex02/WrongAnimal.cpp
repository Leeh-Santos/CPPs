# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	type = "Wrong Animal"; 
	std::cout << "WrongAnimal Constructor Called"  << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& obj ) {
	std::cout << "WrongAnimal Copy Constructor Called"  << std::endl;
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& obj ) {
	std::cout << "WrongAnimal Assignment operator called"  << std::endl;
	type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called"  << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound"  << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}