#include <iostream>
//# include <string>

int oi(std::string str){

    int i = 0;

    while (str[i])
        i++;
    return i;
}

int main(int argc, char *argv[]){

    //std::string x = "l";
    std::cout << oi("lol") << std::endl;
    //return 0;
}