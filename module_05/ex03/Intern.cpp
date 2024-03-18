# include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& obj){
    *this = obj;
}

Intern& Intern::operator=(const Intern& obj){
    (void)obj;
    return *this;
}

AForm *Intern::makeForm(std::string form, std::string target){

    std::string forms[3] = {"presidential", "robot", "shru"};
    
    int i = 0;
    while (i < 3){
        if (!forms[i].compare(form))
            break;
        i++;
    }
    
    switch (i)
    {
    case 0:
        std::cout << "presidential form was created with target " << target << std::endl;
        return new PresidentialPardonForm(target);
        break;
    case 1:
        std::cout << "robot form was created with target " << target << std::endl;
        return new RobotomyRequestForm(target);
        break;
    case 2:
        std::cout << "shru form was created with target " << target << std::endl;
        return new ShrubberyCreationForm(target);
        break;
    default:
        std::cout << "input form: " << form << " was not found, please do not use any method of this obj" << std::endl;
        std::cout << "no form was found, try again meu parceiro" << std::endl;
        return NULL;    
    }

}