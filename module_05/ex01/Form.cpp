# include "Form.hpp"
# include "Bureaucrat.hpp"


Form::Form() : _name("unkown"), _signed(0), _signGrade(0), _requiredGrade(0)
{
}

Form::~Form()
{
}

Form::Form(std::string name, int signgrade, int requiredgrade) : _name(name), _signed(0), _signGrade(signgrade), _requiredGrade(requiredgrade){
    if (_signGrade > 150 || _requiredGrade > 150)
        throw Form::GradeTooLowException();
    else if(_signGrade < 1 || _requiredGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(  Form const & copy) : _name(copy._name), _signed(0), _signGrade(copy._signGrade), _requiredGrade(copy._requiredGrade){
}

Form& Form::operator=( Form const & copy ){
    (void)copy;
    return *this;
}



const std::string Form::getName() const{
    return _name;
}

int     Form::getSignGrade() const{
    return _signGrade;
}

int    Form::getRequiredGrade() const{
    return _requiredGrade;
}

bool	Form::beSigned( Bureaucrat const &obj) {
    if (obj.getGrade() <= _signGrade){
        _signed = 1;
        return 1;
    }
    else {
        std::cout << obj.getName() << " could not sign: " << getName() << " because of grade issues" << std::endl;
        throw Form::GradeTooLowException();
    }

}

bool	Form::isSigned( void ) const{
	return _signed;
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Form Grade is too high");
}

const char * Form::GradeTooLowException::what() const throw(){
     return ("Form Grade is too low");
}

std::ostream& operator<<(std::ostream &os, Form& obj){
    os << "name:" << obj.getName() << " required Grade: " << obj.getRequiredGrade() << " exec grade: " << obj.getSignGrade() << std::endl; 
    return os;
}