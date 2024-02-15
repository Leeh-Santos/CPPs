# include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade <= 0)
        throw Bureaucrat::GradeTooLowException();
    else 
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name){
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
    _grade = obj._grade;
    return *this;
}

int Bureaucrat::getGrade(){
    return _grade;
}

const std::string Bureaucrat::getName(){
    return _name;
}

void   Bureaucrat::signForm( Form& obj) const{
    if (obj.beSigned(*this) == 1){
        std::cout << "Bureaucrat " << _name << " signed form " << obj.getName();  
    }
    else
        std::cout << "Bureaucrat " << _name << " could not sign form " << obj.getName() << " grade low af";
}

void    Bureaucrat::Increment(){
    if (_grade - 1 <= 0)
        throw Bureaucrat::GradeTooHighException();
    else 
        _grade--;
}


void Bureaucrat::Decrement(){
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
     return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj){
    os << obj.getName() << ", bureucrat grade " << obj.getGrade() << std::endl;
    return os;
}