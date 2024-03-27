# include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){

    BitcoinExchange coin;

    if (argc != 2){
        std::cout << "invalid arg meu parceiro, try: ./btc file" << std::endl;
        return 1;
    }
    if (BitcoinExchange::valid_file(argv[1], coin))
        coin.do_conversion(argv[1]);
    
}