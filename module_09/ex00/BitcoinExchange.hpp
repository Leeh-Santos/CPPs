#pragma once

# include <iostream>
# include <fstream>
# include <map>


class BitcoinExchange
{
private:
    std::map<std::string, double> mapin;
public:
    BitcoinExchange(/* args */);
    ~BitcoinExchange();
};

int valid_file(std::string str);
void do_conversion();

