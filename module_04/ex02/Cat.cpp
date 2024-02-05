# include "Cat.hpp"
# include "Animal.hpp"

Cat::Cat( void ) {
	this->type = "Cat";
	brain = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat( void ) {
	delete brain;
	std::cout << "Cat Default destructor called" << std::endl;
}

Cat::Cat ( const Cat& obj) : Animal(){
	std::cout << "Cat copy constructor called" << std::endl;
	type = obj.type;
	brain = new Brain(*(obj.brain)); 
}	

Cat& Cat::operator=( const Cat& obj ) {
	std::cout << "Cat assignment overload called" << std::endl;
	if (brain)
		delete brain;
	type = obj.type;
	brain = new Brain(*(obj.brain));
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "miiiiiiiiaaauuuuuu " << std::endl;
}

std::string Cat::getType() const{
    return(this->type);
}

void Cat::print_idea() const{
	std::string *get = brain->inside_brain();
	std::cout << type << " firts str in my brain is : " << get[0] << std::endl;
}