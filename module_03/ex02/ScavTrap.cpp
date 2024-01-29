# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << " ScavTrap default construct called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){

    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << " ScavTrap string construct called" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap& obj){
    std::cout << " ScavTrap copy constructor construct called" << std::endl;
    *this = obj;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called " << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj){
    std::cout << "ScavTrap copy assignement called" << std::endl;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;
    return *this;
}

void	ScavTrap::attack( const std::string& target ){
    if (_energyPoints == 0){
        std::cout << "Scavtrap is out of energy bro, get me a monster of coffee to hit this ****" << std::endl;
        return ;
    }
    if (_hitPoints < 1)
        std::cout << "scavtrap has no life left bro, can not attack, I am dead" << std::endl;    
    else{
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks : " << target << " causing " << _attackDamage << " damage" << std::endl;
        std::cout << "energy points left : " << _energyPoints << std::endl; 
    }
}

void        ScavTrap::guardGate(void){
    if (this->_hitPoints > 0)
        std::cout << "ScavTrap " << this->_name << " is guarding the gate" << std::endl;
    else
        std::cout << this->_name << " is dead !" << std::endl;
}

