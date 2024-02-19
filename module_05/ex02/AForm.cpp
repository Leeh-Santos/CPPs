# include "AForm.hpp"
# include "Bureaucrat.hpp"


AForm::AForm() : _name("unkown"), _signed(0), _signGrade(0), _requiredGrade(0)
{
}

AForm::~AForm()
{
}

AForm::AForm(std::string name, int signgrade, int requiredgrade) : _name(name), _signed(0), _signGrade(signgrade), _requiredGrade(requiredgrade){
    if (_signGrade > 150 || _requiredGrade > 150)
        throw AForm::GradeTooLowException();
    else if(_signGrade < 1 || _requiredGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(  AForm const & copy) : _name(copy._name), _signed(0), _signGrade(copy._signGrade), _requiredGrade(copy._requiredGrade){
}

AForm& AForm::operator=( AForm const & copy ){
    (void)copy;
    return *this;
}



const std::string AForm::getName() const{
    return _name;
}

int     AForm::getSignGrade() const{
    return _signGrade;
}

int    AForm::getRequiredGrade() const{
    return _requiredGrade;
}

bool	AForm::beSigned( Bureaucrat const &obj) {
    if (obj.getGrade() <= _signGrade){
        _signed = 1;
        return 1;
    }
    else {
        std::cout << obj.getName() << " could not sign: " << getName() << " because of grade issues" << std::endl;
        throw AForm::GradeTooLowException();
    }

}

bool	AForm::isSigned( void ) const{
	return _signed;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("AForm Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw(){
     return ("AForm Grade is too low");
}

std::ostream& operator<<(std::ostream &os, AForm& obj){
    os << "name:" << obj.getName() << " required Grade: " << obj.getRequiredGrade() << " exec grade: " << obj.getSignGrade() << std::endl; 
    return os;
}