# include "iter.hpp"

int main(void){
    {
    std::string str[] = {"meu", "lele", "dale"};
    std::cout << "_________String__________" << std::endl;
    ::iter(str, 3, print);

    int nb[] = {1,2,3,4};
    std::cout << "_________int_________" << std::endl;
    ::iter(nb, 4, print);

    char bit[] = {'a','b','c'};
    std::cout << "_________char__________" << std::endl;
    ::iter(bit, 3, print);

    float fl[] = {1.5, 2.3, 3.5, 4.5};
    std::cout << "_________float__________" << std::endl;
    ::iter(fl, 4, print);
    }
  

    
    
}