#pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    /* data */
public:
    PresidentialPardonForm(/* args */);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

    void execute(Bureaucrat const & executor) const;

    class deuruim : public std::exception{
        public:
        const char* what() const throw();
    };
};




