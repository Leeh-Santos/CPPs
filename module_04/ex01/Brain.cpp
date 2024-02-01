# include "Brain.hpp"

Brain::Brain()
{
    std::cout << " Brain constructor called" << std::endl;
    for (int i = 0 ; i < 100 ; i++){
        ideas[i] = "nothing yet";
    }
}

Brain::~Brain()
{
    std::cout << " Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& obj){
    std::cout << " Brain copy constructor called" << std::endl;
    *this = obj;
}
Brain& Brain::operator=(const Brain& obj){ // if is a brain only copies brain
    std::cout << " Brain assignment called" << std::endl;
    for (int i = 0 ; i < 100 ; i++){
        ideas[i] = obj.ideas[i];
    }
    return *this;
}

std::string Brain::giveidea(){
    return(ideas[0]);
}
