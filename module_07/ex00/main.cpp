# include "template.hpp"

int main(){

    {
    std::cout << "__________________________SWAP__________________________" << std::endl;
    int x = 5;
    int y = 10;
    char a = 'a';
    char b = 'b';
    std::string s1 = "mama";
    std::string s2 = "huevos";

    swap(x , y);
    swap(a, b);
    swap(s1, s2);
    std::cout << "x = " << x << " and y = " << y << std::endl;
    std::cout << "a = " << a << " and b = " << b << std::endl;
    std::cout << "s1 = " << s1 << " and s2 = " << s2 << std::endl;
    }

    {
    std::cout << "__________________________min/max__________________________" << std::endl;

    int x = 5;
    int y = 10;
    char a = 'a';
    char b = 'b';
    std::string s1 = "mama";
    std::string s2 = "huevos";

    std::cout << "min - " << ::min(s1, s2) << std::endl;
    std::cout << "max - " << ::max(s1, s2) << std::endl;

    std::cout << "min - " << min(x, y) << std::endl;
    std::cout << "max - " << max(x, y) << std::endl;
    std::cout << "min - " << min(a, b) << std::endl;
    std::cout << "max - " << max(a, b) << std::endl;
    
    }
}