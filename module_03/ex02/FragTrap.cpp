# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("")
{
    std::cout << "Default FragTrap Constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap String Constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap()
{
    std::cout << "Copy FragTrap Constructor called" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap    &FragTrap::operator=(FragTrap const &rhs)
{
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " give me a high fiiiiiiiiiive" << std::endl;
}
