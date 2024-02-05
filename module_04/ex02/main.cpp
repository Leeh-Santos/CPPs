# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "WrongAnimal.hpp"

int main(){

    {
    
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout <<" ________________________ "<<std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    //std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();
    //meta->makeSound();

    delete i;
    delete j;
    //delete meta;

    
    }

}