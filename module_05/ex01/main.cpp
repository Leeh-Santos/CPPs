# include "Bureaucrat.hpp"
# include <iostream>

int main(){
    {
        std::cout << "__________________valid Bure creation//invalid__________________" << std::endl;

        try
        {
            Bureaucrat b1("Thomas Turbano", 1);
            Bureaucrat b2("Isadora pinto", 150);
            std::cout << b1;
            std::cout << b2;
            std::cout << "no exception thrown " << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Bure creation detected, please check values meu parceiro" << std::endl;
        }

        std::cout << "invalid here .........." << std::endl;

        try
        {
            Bureaucrat b3("Cuca Beludo", 160);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "invalid Bure creation detected, please check values meu parceiro" << std::endl;
        }
        
    }

    {
        std::cout << '\n';
        std::cout << '\n';
        std::cout << "____________________________valid/invalid increment or decrement_____________________"<< std::endl;
        Bureaucrat b1("Armando Pinto", 1);
        Bureaucrat b2("Jacinto Pinto", 150);
        try
        {
            b1.Increment();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            std::cout << "not able to incremet meu anjo" << std::endl;
        }
        try
        {
            b2.Decrement();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            std::cout << "not able to decremet meu anjo" << std::endl;
        }

        std::cout << "now it works, no exepction will be thrown" << std::endl;

        try
        {
            b2.Increment();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            std::cout << "not able to incremet meu anjo" << std::endl;
        }
        try
        {
            b1.Decrement();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
            std::cout << "not able to decremet meu anjo" << std::endl;
        }

        std::cout << b1;
        std::cout << b2;
        
    }

}