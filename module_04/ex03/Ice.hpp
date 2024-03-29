#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(const Ice& obj);
    Ice& operator=(const Ice& obj);

    void use(ICharacter& target);
    AMateria* clone() const;
};




#endif