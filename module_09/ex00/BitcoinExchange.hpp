#pragma once

# include <iostream>
# include <fstream>
# include <map>
#include <string>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;
public:
    BitcoinExchange(/* args */);
    ~BitcoinExchange();

    static bool valid_file(const std::string str, BitcoinExchange &obj);
    void print_database();
};

//BitcoinExchange coin;

//void do_conversion();

