# include "Form.hpp"
# include "Bureaucrat.hpp"


Form::Form() : _name("unkown"), _signed(0), _signGrade(0), _requiredGrade(0)
{
}

Form::~Form()
{
}

Form::Form(  Form const & copy) : _name(copy._name), _signed(copy._signed), _requiredGrade(copy._requiredGrade), _signGrade(copy._signGrade){
}

Form& Form::operator=( const Form& copy ){
    (void)copy;
    return *this;
}

Form::Form(std::string name, int signgrade, int requiredgrade) : _name(name), _requiredGrade(requiredgrade), _signGrade(signgrade), _signed(0){
    if (_signGrade > 150 || _requiredGrade > 150)
        throw Form::GradeTooLowException();
    else if(_signGrade < 1 || _requiredGrade < 1)
        throw Form::GradeTooHighException();
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
    if (obj.getGrade() <= _requiredGrade){
        _signed = 1;
        return 1;
    }
    else
        throw Form::GradeTooLowException();

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
    os << "name-" << obj.getName() << " required Grade-" << obj.getRequiredGrade() << "exec grade-" << obj.getSignGrade() << std::endl; 
    return os;
}