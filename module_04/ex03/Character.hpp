# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *slots[4];
public:
    Character();
    ~Character();
    Character(const Character& obj);
    Character& operator=(const Character& obj);
    
    Character(std::string name);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif