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

    
    std::string literals[] = {"+inff", "-inff", "nanf", "-inf", "+inf", "nan"};

    for (int i = 0; i < 6 ; i++){
        if (!str.compare(literals[i])){
            pseudo(str);
            return;
        }
    }

    if (is_char(str))
        return dale_char();
    else if(is_int(str))
        return dale_int();


}

void pseudo(std::string str){
    std::cout << "Char: Impossible" <<std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(strtod(str.c_str(), NULL)) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(strtod(str.c_str(), NULL)) << std::endl;
	return ;
}


int is_char(std::string str){
    if (str.size() == 1 && !std::isdigit(str[0]))
        return 1;
    return 0;
}

void dale_char(std::string str){
    if (!std::isprint(str[0]))
        std::cout << "Char: not printable" << std::endl;
    else
        std::cout << "Char: '" << str[0] << "'" << std::endl; 
    std::cout << "Int :" << static_cast<int>(str[0]) << std::endl;
    std::cout << "Float :" << static_cast<float>(str[0]) << std::endl;
    std::cout << "Double :" << static_cast<double>(str[0]) << std::endl;
    
}