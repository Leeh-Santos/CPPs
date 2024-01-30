# ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& obj);
    Animal& operator=(const Animal& obj);
    virtual ~Animal() = 0;
    virtual void makeSound() = 0;
    std::string getType();
};

#endif