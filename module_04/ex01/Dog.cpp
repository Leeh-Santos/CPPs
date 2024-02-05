# include "Dog.hpp"
# include "Animal.hpp"

Dog::Dog( void ) {
	this->type = "Dog";
	brain = new Brain();
	std::cout << "Dog Default Constructor Called" << std::endl;

}

Dog::~Dog( void ) {
	delete brain;
	std::cout << "Dog Default destructor called" << std::endl;
}

Dog::Dog ( const Dog& obj) : Animal(){
	std:: cout << "Dog copy constructor called" << std::endl;
	type = obj.type;
	brain = new Brain(*(obj.brain));
}

Dog& Dog::operator=( const Dog& obj ) {
	std::cout << "Dog assignment overload called" << std::endl;
	type = obj.type;
	if (brain)
		delete brain;
	brain = new Brain(*(obj.brain));
	return (*this);
}

void	Dog::makeSound( void ) const{
	std::cout << "auuu auuuuuu" << std::endl;
}

std::string Dog::getType() const{
    return(this->type);
}

std::string Dog::print_idea() const{


}
