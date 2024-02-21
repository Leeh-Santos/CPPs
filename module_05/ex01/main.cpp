
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
    {
        std::cout << "__________________valid FORM creation//invalid__________________" << std::endl;
        try
        {
            Form f1("formzin", 160, 4);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Form creation detected, please check values meu parceiro" << std::endl;
        }

        try
        {
            Form f2("formzin", 150, 1);
            std::cout << "no exception thrown " << std::endl;
            std::cout << f2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Form creation detected, please check values meu parceiro" << std::endl;
        }
    }


    {
        std::cout << "_______________Member functions________________" << std::endl;
        Bureaucrat b1("Thomas Turbano", 3);
        Bureaucrat b2("Cuca Beludo", 1);
        Form f1("Formzin", 1, 5);
        try
        {
            b1.signForm(f1);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        b2.signForm(f1);
        
    }


}