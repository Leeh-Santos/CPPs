# include "Animal.hpp"

Animal::Animal()
{
    std::cout << "animal constructor called" << std::endl;
    type = "your mother in law";
}

Animal::~Animal()
{
    std::cout << "animal constructor called" << std::endl;
}

Animal::Animal(const Animal& obj){
    std::cout << "animal copy constructor called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj){
    type = obj.type;
}