# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice& obj) : AMateria("ice"){
    *this = obj;
}

Ice& Ice::operator=(const Ice& obj){
    (void)obj;
    _type = obj._type;
    return *this;
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria* Ice::clone() const{
    AMateria *tmp = new Ice();
    return tmp;
}