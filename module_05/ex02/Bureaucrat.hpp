# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# include "AForm.hpp" 
# include <iostream>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    ~Bureaucrat();

    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    
    int getGrade() const;
    const std::string getName() const;
    void    Increment();
    void    Decrement();
    void    signForm(AForm& obj) const;

    void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
        public :
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception{
        public :
        const char *what() const throw(); //const char *what() const noexcept override; throw in the end of func is not used anymore
    };

    
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);


#endif 