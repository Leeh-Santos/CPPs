# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& obj) : AMateria("cure"){
    *this = obj;
}

Cure& Cure::operator=(const Cure& obj){
    (void)obj;
    return *this;
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const{
    AMateria *tmp = new Cure();
    return tmp;
}