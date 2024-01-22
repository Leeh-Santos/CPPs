# include "Harl.hpp"

int main(){
    Harl speak;

    std::cout << "debug" << std::endl;
    speak.complain("DEBUG");

    std::cout << "info" << std::endl;
    speak.complain("INFO");

    std::cout << "warning" << std::endl;
    speak.complain("WARNING");

    std::cout << "error" << std::endl;
    speak.complain("ERROR");

    
}