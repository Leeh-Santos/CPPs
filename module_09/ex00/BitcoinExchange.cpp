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
        std::cout << it->first << "  " << it->second << std::endl;
        it++;
    }
}

bool BitcoinExchange::lineCheck(std::string in){
    if(in.length() < 14 || in[11] != '|' || !isdigit(in[13]) || !isdigit(in[9]))
        return 1;
    for(int i = 0; i < in.length(); i++)
        if(!isdigit(in[i]) && in[i] != '.' && in[i] != '|' && in[i] != ' ' && in[i] != '-')
            return 1;
    return 0;
    
}

bool BitcoinExchange::dateCheck(std::string in){

}

void BitcoinExchange::do_conversion(const std::string input){
    std::ifstream in(input.c_str());
    std::string input_line;
    int lineflag = 0;

    while(std::getline(in, input_line)){
        if (!lineflag)
            if (input_line.compare("date | value")){
                std::cout << "Error: " << "no date | value detected" << std::endl;
                lineflag++;
                continue;
            }
        else if (lineCheck(input_line)){
            std::cout << "Error: " << input_line << " invalid input" << std::endl;
            continue; 
        }
        else if (dateCheck(input_line))
            std::cout << "Error: " << input_line << " invalid date" << std::endl;
    }
}