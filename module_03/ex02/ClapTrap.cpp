# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << " ClapTrap default construct called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called " << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap&  ClapTrap::operator=(const ClapTrap &obj){
    std::cout << "ClapTrap copy assignement called" << std::endl;
    _name = obj._name;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;
    return *this;
}


void ClapTrap::attack(const std::string& target){
    if (_energyPoints == 0){
        std::cout << "out of energy bro, get me a monster of coffee to hit this ****" << std::endl;
        return ;
    }
    if (_hitPoints < 1)
        std::cout << "no life left bro, can not attack, I am dead" << std::endl;    
    else{
        _energyPoints--;
        std::cout << "Claptrap " << _name << " attacks : " << target << " causing " << _attackDamage << " damage" << std::endl;
        std::cout << "energy points left : " << _energyPoints << std::endl; 
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints < 1){
        std::cout << _name << " is already dead, give him a break" << std::endl;
    }
    else{
        std::cout << _name << " has taken :" << amount << " of damage." << std::endl;
        _hitPoints = _hitPoints - amount;
        if (_hitPoints < 1)
            std::cout << _name << " died is this attack." << std::endl;
        else
            std::cout << "has " << _hitPoints << " energy left." << std::endl;
    }
    
}

void ClapTrap::beRepaired(unsigned int amount){
    if (!_energyPoints){
        std::cout << _name << " has no energy to repair" << std::endl;
        return;
    }
    if (_hitPoints < 1){
        std::cout << _name << " is already dead, not able to repair" << std::endl;
        return;
    }
    else{
        _energyPoints--;
        _hitPoints += amount;
        std::cout << _name << " has been healed by " << amount << " total health : " << _hitPoints << std::endl;
    }
}