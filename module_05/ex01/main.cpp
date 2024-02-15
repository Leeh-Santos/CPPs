
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(){
    {
        std::cout << "__________________valid FORM creation//invalid__________________" << std::endl;
        try
        {
            Form f1("formzin", 160, 4);
            std::cout << "no exception thrown " << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Form creation detected, please check values meu parceiro" << std::endl;
        }
        
    }


}