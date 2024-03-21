# include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::valid_file(const std::string str, BitcoinExchange &obj){
    std::ifstream in(str.c_str());
    std::ifstream database("data.csv");

    std::string str1;

    if(!in.is_open()){
        std::cout << "no able to open file: " << str << std::endl;
        return 0;
    }

    if(!database.is_open()){
        std::cout << "no able to open database" << std::endl;
        return 0;
    }
    else
        while(std::getline(database, str1)){    
            std::string date = str1.substr(0, str1.find(","));
            double amount = atof(str1.substr(str1.find_last_of(",") + 1).c_str());
            obj._database[date] = amount;
        }
    return 1;
}

void BitcoinExchange::print_database(){
    std::map<std::string, double>::iterator it;
    it = _database.begin();
    while(it != _database.end()){
        std::cout << it->first << "           " << it->second << std::endl;
        it++;
    }
}

/*void do_conversion(){

}*/