# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(/* args */) : AForm("ShrubberyForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getRequiredGrade()) {
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
    _target = obj._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (isSigned() && executor.getGrade() <= getRequiredGrade()){
        std::string out_name;
        out_name = _target;
        out_name += "_shrubbery";
        std::ofstream out(out_name.c_str());

        if (!out.is_open()){
        std::cout << "fail to open : " << out_name << std::endl;
        return ;
        }

        std::string tree = 
			" /~~~~~~~~~~\\\n"
			"/~~~~~~~~~~~~\\\n"
		   "/~~~~~~o~~o~~~\\\n"
		   "|~~~~o~~~~~~~~|\n"
		   "\\~~~~~~~o~~~~/\n"
		   " \\~~~~~~~~~~/\n"
		   "  \\~~~~~~~~/\n"
			"   | |   |\n"
		    "   | |   |\n"
		    "   | |   |   O\n"
			"   O |   |  /|\\\n"
			"     |   |  / \\\n"
		"================\n";
        out << tree;
        out.close();
        std::cout << _target << " file has been created by " << executor.getName() << std::endl;
    }
        else{
            std::cout << executor.getName();
            throw ShrubberyCreationForm::exec_error();
        }
}

const char* ShrubberyCreationForm::exec_error::what() const throw(){
    return " not able to exec shitberry, Form no signed or Grade not enough to execute, deu ruim";
}
