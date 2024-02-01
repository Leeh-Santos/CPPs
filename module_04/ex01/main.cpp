# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "WrongAnimal.hpp"

int main(){

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout <<" ________________________ "<<std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;
    
    std::cout <<" ________________________ "<<std::endl;

    const WrongAnimal *x = new WrongAnimal();
    const WrongAnimal *y = new WrongCat();
    const WrongCat *z = new WrongCat();

    std::cout << std::endl;
    std::cout << x->getType() << " " << std::endl;
    std::cout << y->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "method in base class WrongAnimal not set as virtual so will output the same sound " << std::endl;
    /*std::cout << "To ensure you understood how it works, implement a WrongCat class that inherits \
    from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones\
    in the code above, the WrongCat should output the WrongAnimal sound." << std::endl;*/
    x->makeSound();
    y->makeSound();
    std::cout << std::endl;
    std::cout << "this one not, since this time we are pointing diretamente a um tipo WrongCat class (already derived class)" << std::endl;
    z->makeSound();
    std::cout << std::endl;
    delete x;
    delete y;
    delete z;

    return 0;
}