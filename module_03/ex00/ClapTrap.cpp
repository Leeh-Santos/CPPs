# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "default construct called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called " << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "string cunstructor called" << std::endl;
}
