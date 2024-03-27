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
    std::string indate;
    double invalue;
public:
    BitcoinExchange(/* args */);
    ~BitcoinExchange();

    static bool valid_file(const std::string str, BitcoinExchange &obj);
    void do_conversion(const std::string input);
    bool lineCheck(std::string);
    bool dateCheck(std::string);
    bool precisecheck(int, int);
    bool checkValue(std::string);
    void print_database();

};

//BitcoinExchange coin;

//void do_conversion();

