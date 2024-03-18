# include "AForm.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(){

    {
        Bureaucrat b1("Isadora Pinto", 1);
        //Bureaucrat b2("Cuca Beludo", 1);
        //Bureaucrat b3("Armando pinto", 1);

        Intern dale;

        AForm *f1;
        AForm *f2;
        AForm *f3;

        std::cout << "president form_______________________" << std::endl;
        f1 = dale.makeForm("presidential", "mom");
        b1.signForm(*f1);
        f1->execute(b1);

        std::cout << '\n';

        std::cout << "robot form_______________________" << std::endl;
        f2 = dale.makeForm("robot", "Dad");
        b1.signForm(*f2);
        f2->execute(b1);
        std::cout << '\n';

        std::cout << "shru form_______________________" << std::endl;
        f3 = dale.makeForm("shru", "treezinha");
        b1.signForm(*f3);
        f3->execute(b1);
        std::cout << '\n';

        std::cout << "non valid form_______________________" << std::endl;
        AForm *f4 = dale.makeForm("qualquercoisa", "naovaifuncionarmesmo");
        (void)f4;
        delete f1;
        delete f2;
        delete f3;

    }
    return 0;
}