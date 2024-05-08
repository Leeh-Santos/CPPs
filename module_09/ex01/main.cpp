# include "RPN.hpp"

int main(int argc, char *argv[]){

    if (argc != 2){
        std::cout << "wrong args, usage: ./RPN postfix notation" << std::endl;
        exit(1);
    }
    rpn::validString(argv[1]);

}