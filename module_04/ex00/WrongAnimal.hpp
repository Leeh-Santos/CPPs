
#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const &copy);
    ~WrongAnimal(void);

    WrongAnimal &operator=(WrongAnimal const &rhs);
    void        makeSound(void) const;
    std::string getType(void) const;
};

#endif