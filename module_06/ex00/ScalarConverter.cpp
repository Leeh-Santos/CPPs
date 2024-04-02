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
        return dale_char(str);
    else if(is_int(str))
        return dale_int(str);
    else if(is_float(str))
        return dale_float(str);
    else if(is_double(str))
        return dale_double(str);

    std::cout << "error, invalid input meu parceiro" << std::endl;
   
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

int is_int(std::string str){
    int i = 0;

    if(str[0] == '+' || str[0] == '-')
        i++;
    
    while(str[i] && std::isdigit(str[i]))
        i++;

    if (str[i] != '\0')
        return 0;
    else 
        return 1;
}

void dale_int(std::string str){
    long long int nb = std::atoll(str.c_str());

    if (nb >= 32 && nb <= 127)
        std::cout << "Char : '" << static_cast<char>(nb) << "'" << std::endl;
    else
        std::cout << "Char : char unprintable or no ascii available" << std::endl;
    if (nb > 2147483647 || nb < -2147483648)
        std::cout << "Int : int overflow" << std::endl;
    else 
        std::cout << "Int : " << nb << std::endl;
    std::cout << "Float :" << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "Double :" << std::setprecision(1) << static_cast<double>(nb) << std::endl;

}

void dale_char(std::string str){
    if (!std::isprint(str[0]))
        std::cout << "Char: not printable" << std::endl;
    else
        std::cout << "Char: '" << str[0] << "'" << std::endl; 
    std::cout << "Int :" << static_cast<int>(str[0]) << std::endl;
    std::cout << "Float :" << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "Double :" << static_cast<double>(str[0]) << ".0" << std::endl;
}

int is_float(std::string str){
    int i = 0;
    int dot = 0;
    int nb = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[str.size() - 1] != 'f')
        return 0;
    while (str[i]){
        if (!std::isdigit(str[i]) && (str[i] != 'e' && str[i] != 'f' && str[i] != '.'))
            break;
        if (str[i] == '.')
            dot++;
        if (std::isdigit(str[i]))
            nb++;
        i++;
    }
    if (dot == 0 || nb == 0)
        return 0;
    return 1;
}

void    dale_float(std::string str){
    float nb_f = std::atof(str.c_str());

    if (nb_f >= 32 && nb_f <= 127)
		std::cout << "Char: " << "'" << static_cast<char>(nb_f) << "'" << std::endl;
	else
		std::cout << "Char: char unprintable or no ascii available" << std::endl;
	if (static_cast<int>(nb_f) > 2147483647 || static_cast<int>(nb_f) <= -2147483648) 
		std::cout << "Int: overflow value" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(nb_f) << std::endl;
    if (nb_f > std::numeric_limits<float>::max() || nb_f < std::numeric_limits<float>::min()){
        std::cout << "float: limit reached" << std::endl;
        std::cout << "double: limit reached" << std::endl;
    }
    else{
        std::cout << "Float: "  << std::fixed << std::setprecision(2) << nb_f << 'f' << std::endl;
        std::cout << "Double: " << std::setprecision(2) << static_cast<double>(nb_f) << std::endl;
    }
}

int is_double(std::string str){
    int i = 0;
    int flag = 0;

    if(str[i] == '+' || str[i] == '-')
        i++;
    while (str[i]){
        if(!std::isdigit(str[i]))
            if(str[i] != '.')
                break;
        if(str[i] == '.')
            flag++;
        i++;
    }
    if (flag > 1 || str[i] != '\0')
        return 0;
    return 1;
}

void dale_double(std::string str){
    //double dubs = std::stod(str);
    double dubs = strtod(str.c_str(), NULL);

	if (dubs >= 32 && dubs <= 127)
		std::cout << "Char: " << "'" << static_cast<char>(dubs) << "'" << std::endl;
	else
		std::cout << "Char: char unprintable or no ascii available" << std::endl;
	if (dubs > 2147483647 || dubs < -2147483648) 
		std::cout << "Int: overflow value" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(dubs) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(dubs) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << dubs << std::endl;
}