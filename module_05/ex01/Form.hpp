# ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool		_signed;
	const int	_signGrade;
	const int	_requiredGrade;  
public:
    Form(/* args */);
    ~Form();
    Form( const Form& copy);
	Form& operator=( const Form& copy );
    Form(std::string name, int signgrade, int requiredgrade);

    const std::string getName() const;
    int     getSignGrade() const;
    int     getRequiredGrade() const;
    bool	beSigned(Bureaucrat &obj);
    bool                isSigned(void) const;

    class GradeTooHighException : public std::exception{
        public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception{
        public:
        const char *what() const throw();
    }; 
};

std::ostream& operator<<(std::ostream &os, const Form& obj);


#endif