# include "PmergeMe.hpp"

int main(int argc, char *argv[]){

    if (argc <= 1){
        std::cout << "Please provide args" << std::endl;
        exit(1);
    }

    std::vector<std::string> args(argv, argv + argc); // range constructor
    checkInput(args);
    PmergeMe merge(args);
    merge.m_init();
    
}