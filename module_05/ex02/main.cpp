# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(){

    {
        std::cout << "_____________shitbbery test__________________" << std::endl;

        Bureaucrat b1("Cuca Beludo", 145);
        Bureaucrat b2("Armando pinto", 1);
        ShrubberyCreationForm f1("shitberry");
        b1.signForm(f1);
        try
        {
            f1.execute(b2);
            f1.execute(b1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    }


    {
        std::cout << "_____________presidential test__________________" << std::endl;

        Bureaucrat b1("Cuca Beludo", 145);
        Bureaucrat b2("Armando pinto", 1);
        PresidentialPardonForm f1("FORMIZIN");
        b2.signForm(f1);
        try
        {
            f1.execute(b2);
            f1.execute(b1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }


    {
        std::cout << "_____________ROBOT test__________________" << std::endl;

        Bureaucrat b1("Cuca Beludo", 145);
        Bureaucrat b2("Armando pinto", 1);
        RobotomyRequestForm f1("robozera");
        b2.signForm(f1);
        try
        {
            f1.execute(b2);
            f1.execute(b1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "___________buro execform method_______________________"<< std::endl;
        Bureaucrat b1("Cuca Beludo", 145);
        Bureaucrat b2("Armando pinto", 1);
        RobotomyRequestForm f1("dale");
        b2.signForm(f1);

        b1.executeForm(f1);
        b2.executeForm(f1);

    }
    return 0;
}