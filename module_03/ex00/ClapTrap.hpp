#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream> 

class ClapTrap
{
private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& obj);
    ClapTrap &operator=(const ClapTrap &obj);
    ~ClapTrap();
};


#endif