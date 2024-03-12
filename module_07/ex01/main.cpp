# include "iter.hpp"

int main(){

    std::string str[] = {"meu", "lele", "dale"};
    int nb[] = {1,2,3};
    char bit[] = {'a','b','c'};
    float fl[] = {1.5, 2.3, 3.5};

    std::cout << "_________String__________" << std::endl;
    ::iter(str, 3, printer);
    std::cout << "_________int_________" << std::endl;
    ::iter(nb, 3, printer);
    std::cout << "_________char__________" << std::endl;
    ::iter(bit, 3, printer);
    std::cout << "_________float__________" << std::endl;
    ::iter(fl, 3, printer);
  
}