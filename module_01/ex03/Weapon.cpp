#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    _type = name;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType(void){
    return _type;
}

void    Weapon::setType(std::string thing){
    _type = thing;
}
