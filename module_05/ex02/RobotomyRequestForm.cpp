# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(/* args */) : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45){
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getRequiredGrade()){
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
    _target = obj._target;
    return *this;
}

const char* RobotomyRequestForm::RoboError::what() const throw(){
    return " not able to exec robo form, Form not signed or Grade not enough to execute, deu ruim";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (isSigned() && executor.getGrade() <= getRequiredGrade()){
        std::cout << "VRAAAAAAAAAAAAAAAAAAAAAAAUUUUUUUUUUUUUUUUUU" << '\n';
        srand((unsigned) time(0));
        if(rand() % 2 == 0)
            std::cout << _target << " has been robotomized" << '\n';
        else
            std::cout <<  _target << " was not robotomized" << '\n';
    }
    else 
        throw RobotomyRequestForm::RoboError();
}