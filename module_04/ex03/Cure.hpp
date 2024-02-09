#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();
    Cure(const Cure& obj);
    Cure& operator=(const Cure& obj);
    void use(ICharacter& target);
    AMateria* clone() const;
};




#endif