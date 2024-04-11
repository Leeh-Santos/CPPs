# include "easyFind.hpp"

int main(){

   //std::vector<int> vec = {1,2,3}; c++98 nao deixa assim

    std::vector<int> vec;

    for (int i = 0; i <= 10; i++)
        vec.push_back(i);

    std::cout << easyfind(vec, 5) << std::endl;
    std::cout << easyfind(vec, 8) << std::endl;
    std::cout << easyfind(vec, 15) << std::endl; // return -1

    std::cout << "string vec:__________________" << '\n';
    
    std::vector<std::string> str;
    str.push_back("dale");
    str.push_back("lele");
    str.push_back("lulu");
    str.push_back("lala");
    std::cout << str[2] << std::endl;

}