#pragma once

#include "AForm.hpp"
#include <time.h>
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
    /* data */
public:
    RobotomyRequestForm(/* args */);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

    void execute(Bureaucrat const & executor) const;

    class RoboError : public std::exception{
        public:
        const char *what() const throw();
    };


};

