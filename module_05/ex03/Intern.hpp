# pragma once
# include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# include <iostream>

class Intern
{
private:
    
public:
    Intern(/* args */);
    Intern(const Intern& obj);
    Intern& operator=(const Intern& obj);
     ~Intern();
    AForm *makeForm(std::string form, std::string target);
   
};


