# include "Cat.hpp"
# include "Animal.hpp"

Cat::Cat( void ) {
	this->type = "Cat";
	brain = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "Cat Default destructor called" << std::endl;
}

Cat::Cat ( const Cat& obj) : Animal(){
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	*this = obj;
}	

Cat& Cat::operator=( const Cat& obj ) {
	std::cout << "Cat assignment overload called" << std::endl;
	type = obj.type;
	brain = obj.brain;
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "miiiiiiiiaaauuuuuu " << std::endl;
}

std::string Cat::getType() const{
	brain->giveidea();
    return(this->type);
}
