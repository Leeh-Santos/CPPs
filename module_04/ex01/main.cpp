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
  
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    }
    {
    std::cout << " _________________________main test2__________________________" << std::endl;
    const Animal *animals[10];
    for(int i = 0; i < 9; i++){
        if (i % 2 == 0){
            std::cout << "animal number: " << i << " created" << std::endl;
            animals[i] = new Dog();
            animals[i]->print_idea();
        }
        else{
            std::cout << "animal number: " << i << " created" << std::endl;
            animals[i] = new Cat();
            animals[i]->print_idea();
        }
    }

    for(int i = 0; i < 9; i++){
        std::cout << "animal number: " << i << " deleted" << std::endl;
        delete animals[i];
    }
    }

    {
    std::cout << " _________________________other test__________________________" << std::endl;
    const Animal* x = new Dog();
    const Animal* y = new Cat();
    
    x->print_idea();
    y->print_idea();

    Cat cat1;
    Cat cat2;

    std::cout << "____________________trying assignment overload" << std::endl;
    cat1.print_idea();
    cat1 = cat2;
    cat1.print_idea();
    delete x;
    delete y;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    }

    return 0;

}