#pragma once
# include <iostream>

#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

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
int get_type(std::string str);
