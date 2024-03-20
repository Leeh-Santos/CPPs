# include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){

    if (argc != 2){
        std::cout << "invalid arg meu parceiro, try: ./btc file" << std::endl;
        return 1;
    }
    if (valid_file(argv[1]))
        do_conversion();

}