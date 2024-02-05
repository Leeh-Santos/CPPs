# include "Dog.hpp"
# include "Animal.hpp"

Dog::Dog( void ) {
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;

}

Dog::~Dog( void ) {
	std::cout << "Dog Default destructor called" << std::endl;
}

Dog::Dog ( const Dog& obj) : Animal(){
	std:: cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=( const Dog& obj ) {
	std::cout << "Dog assignment overload called" << std::endl;
	type = obj.type;
	brain = obj.brain;
	return (*this);
}

void	Dog::makeSound( void ) const{
	std::cout << "auuu auuuuuu" << std::endl;
}

std::string Dog::getType() const{
    return(this->type);
}
