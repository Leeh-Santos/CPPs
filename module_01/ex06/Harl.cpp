# include "Harl.hpp"

Harl::Harl(){
    //ptr[0] = &Harl::debug;
    //ptr[1] = &Harl::error e por ai vai
}

Harl::~Harl(){

}

void    Harl::debug(void){
    std::cout << " love having extra bacon for my 7XL-double-cheese-triple" << std::endl;
}


void    Harl::info(void){
     std::cout << "I cannot believe adding extra bacon costs more money" << std::endl;
}

void    Harl::warning(void){
    std::cout << "I  think I deserve to have some extra bacon for free. I" << std::endl;
}

void    Harl::error(void){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level ){
    std::string str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void    (Harl::*ptr[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 5; i++){
        if (!str[i].compare(level))
            (this->*ptr[i])();
    }
    
    }