# ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    
public:
    ShrubberyCreationForm(/* args */);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

    void execute(Bureaucrat const & executor) const;

    class exec_error : public std::exception{
        public:
        const char *what() const throw();
    };
};




# endif