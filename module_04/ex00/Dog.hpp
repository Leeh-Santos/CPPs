# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class  Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& obj);
    Dog& operator=(const Dog& obj);
    
    ~Dog();
    std::string getType() const;
    void        makeSound(void ) const;

};


#endif