# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "WrongAnimal.hpp"

int main(){

    {
    std::cout << " _________________________main test__________________________" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
    }

    {
    std::cout << " _________________________main test__________________________" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    
    
    
    }

}