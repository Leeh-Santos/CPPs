# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getRequiredGrade()){
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
    _target = obj._target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5){
    _target = target;
}


const char* PresidentialPardonForm::deuruim::what() const throw(){

    return "not able to exec presidential form, Form no signed or Grade not enough to execute, deu ruim";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (isSigned() && executor.getGrade() <= getRequiredGrade()){
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << '\n';
    }
    else
        throw PresidentialPardonForm::deuruim();
}