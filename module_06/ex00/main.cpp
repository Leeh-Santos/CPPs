# include "ScalarConverter.hpp"

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cout << "wrong args bro, try it again" << std::endl;
        return 0;
    }
    else
        ScalarConverter::convert(argv[1]);
        
    
}