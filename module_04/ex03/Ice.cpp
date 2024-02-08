# include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice& obj) : AMateria("Ice"){
    *this = obj;
}

Ice& Ice::operator=(const Ice& obj){
    (void)obj;
    return *this;
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria* Ice::clone() const{
    AMateria *tmp = new Ice();
    return tmp;
}