# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
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

void    Bureaucrat::Increment(){
    if (_grade - 1 <= 0)
        return throw Bureaucrat::GradeTooHighException();
    else 
        _grade--;
}

void Bureaucrat::Decrement(){
    if (_grade + 1 > 150)
        return throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

std::ostream& operator<<(std::ostream os, Bureaucrat& obj){
    os << obj.getName() << ", bureucrat grade " << obj.getGrade() << std::endl;
    return os;
}