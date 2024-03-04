# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj){
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){
    (void)obj;
    return *this;
}

void ScalarConverter::convert(std::string str){

    std::string literals[6] = {"+inff", "-inff", "nanf", "-inf", "+inf", "nan"};

    for (int i = 0; i < 6 ; i++){
        if (!str.compare(literals[i])){
            pseudo(str);
            return;
        }
    }
    int x = get_type(str);


}

void pseudo(std::string str){
    std::cout << "Char: Can't be printed" <<std::endl;
	std::cout << "Int: Can't be printed" << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(strtod(str.c_str(), NULL)) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(strtod(str.c_str(), NULL)) << std::endl;
	return ;
}

int get_type(std::string str){
    
}