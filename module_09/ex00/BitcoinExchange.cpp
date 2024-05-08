# include "BitcoinExchange.hpp"

#include <string>
# include <iostream>

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
    _database = obj._database;
    indate = obj.indate;
    invalue = obj.invalue;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
    *this = obj;
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
    for( unsigned int i = 0; i < in.length(); i++)
        if(!isdigit(in[i]) && in[i] != '.' && in[i] != '|' && in[i] != ' ' && in[i] != '-')
            return 1;
    return 0;
    
}

bool BitcoinExchange::precisecheck(int m, int d){
    if (m == 2){
        if (d > 28)
            return 1;
    }
    else if (m % 2 == 0){
        if (d > 30)
            return 1;
    }
    return 0;
}

bool BitcoinExchange::dateCheck(std::string in){

    
    if (in[4] != '-' || in[7] != '-' || in[10] != ' ')
        return 1;
    int year = atoi(in.substr(0, 4).c_str());
    int month = atoi(in.substr(5, 2).c_str());
    int day = atoi(in.substr(8, 2).c_str());

    if (year > 2024 || month > 12 || day > 31 || year < 2009 || month < 1 ) 
        return 1;
    else if (precisecheck(month, day))
        return 1;

    indate = in.substr(0, 10);
    return 0;
}

bool BitcoinExchange::checkValue(std::string in){
    

    if (in[11] != '|' || in[12] != ' ' || !isdigit(in[13]))
        return 1;
    double nb = std::atof(in.substr(in.find("|") + 1).c_str());
    if (nb > 1000 || nb < 0)
        return 1;
    invalue = nb;
    return 0;
}

void BitcoinExchange::do_conversion(const std::string input){
    std::ifstream in(input.c_str());
    std::string input_line;
    int lineflag = 0;
    std::cout << std::fixed << std::setprecision(2);

    while(std::getline(in, input_line)){
        if (!lineflag){
            lineflag++;
            if (input_line.compare("date | value")){
                std::cout << "Error: " << "no date | value detected: " << input_line << std::endl;
                continue;
            }
        }
        else if (lineCheck(input_line)){
            std::cout << "Error: " << input_line << " invalid input" << std::endl;
            continue; 
        }
        else if (dateCheck(input_line)){
            std::cout << "Error: " << input_line << " invalid date" << std::endl;
            continue;
        }
        else if (checkValue(input_line)){
            std::cout << "Error: " << input_line << " invalid value" << std::endl;
            continue;
        }
        else {
            std::map<std::string, double>::iterator it = _database.find(indate);
            if (it != _database.end()){
               std::cout << indate << " => " << invalue << " = " << it ->second * invalue << std::endl;
            }
            else{
                it = _database.lower_bound(indate);
                if (it != _database.begin())
                    it--;
                std::cout << indate << " => " << invalue << " = " << it ->second * invalue << std::endl;
            }
        }
        
    }
}