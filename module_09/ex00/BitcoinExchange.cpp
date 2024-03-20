# include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

int valid_file(const std::string str){
    std::ifstream in(str);

    if(!in.is_open()){
        std::cout << "no able to open file" << std::endl;
        return 0;
    }

    
}

void do_conversion(){

}