# include "AMateria.hpp" 

AMateria::AMateria(){

}

AMateria::~AMateria(){
    
}

AMateria::AMateria( const AMateria& obj){
    *this = obj;
}

AMateria& AMateria::operator=( const AMateria& obj){
    _type = obj._type;
    return *this;
}

std::string const & AMateria::getType() const{
    return _type;
}

void AMateria::use(ICharacter& target){
    (void)target;
}

AMateria::AMateria(std::string const & type) : _type(type){}
