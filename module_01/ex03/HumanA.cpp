#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type)
{
    _name = name;
    _weapon = &type;

}

HumanA::~HumanA()
{
}

void  HumanA::attack(void){
    std::cout << _name << " attacks with their "<< _weapon->getType() << std::endl;
}