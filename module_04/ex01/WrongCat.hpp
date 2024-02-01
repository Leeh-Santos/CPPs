#ifndef WRONG_CAT_H
# define WRONG_CAT_H

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(WrongCat const &copy);
    ~WrongCat(void);

    WrongCat    &operator=(WrongCat const &rhs);
    void        makeSound(void) const;
    std::string getType(void) const;
};

#endif