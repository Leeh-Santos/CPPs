# include "Animal.hpp"

Animal::Animal()
{
    std::cout << "animal constructor called" << std::endl;
    type = "your mother in law";
   
}

Animal::~Animal()
{
    std::cout << "animal destructor called" << std::endl;
}

Animal::Animal(const Animal& obj){
    std::cout << "animal copy constructor called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj){
    type = obj.type;
    return *this;
}

std::string Animal::getType() const{
    return(this->type);
}

void Animal::makeSound() const{
    std::cout << "noooooo sound" << std::endl;
}