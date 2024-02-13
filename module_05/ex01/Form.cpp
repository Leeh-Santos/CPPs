# include "Form.hpp"

Form::Form() : _name("unkown"), _signed(0), _signGrade(0), _requiredGrade(0)
{
}

Form::~Form()
{
}

Form::Form( const Form& copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _requiredGrade(copy._requiredGrade){

}

Form& Form::operator=( const Form& copy ){
    (void)copy;
    return *this;
}

Form::Form(std::string name, int signgrade, int requiredgrade) : _name(name), _requiredGrade(requiredgrade), _signGrade(signgrade), _signed(0){
}

const std::string Form::getName(){
    return _name;
}

int     Form::getSignGrade() const{
    return _signGrade;
}

int    Form::getRequiredGrade() const{
    return _requiredGrade;
}