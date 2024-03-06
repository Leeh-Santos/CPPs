#pragma once
# include <iostream>

#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter(/* args */);
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator=(const ScalarConverter& obj);
    ~ScalarConverter();

    static void convert(const std::string str);
};

void pseudo(std::string str);
void dale_char(std::string str);
int is_char(std::string str);
int is_int(std::string str);
void dale_int(std::string str);
void    dale_float(std::string str);
int is_float(std::string str);