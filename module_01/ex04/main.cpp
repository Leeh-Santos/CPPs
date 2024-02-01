# include <fstream>
# include <iostream>
# include <string.h>
#include <string>

std::string replace_Str(std::string buff, std::string s1, std::string s2){

    size_t occur = buff.find(s1);

    while (occur != std::string::npos){
        buff.erase(occur, s1.length());
        buff.insert(occur, s2);
        //buff.replace(occur, s2.length(), s2);//nao pode
        occur = buff.find(s1);
    }

    return buff;
   

}
int main(int argc, char *argv[]) {

    if (argc != 4){
        std::cout << "bad args bro" << std::endl; 
        return 1;
    }

    std::ifstream in(argv[1]);

    if (!in.is_open()){
        std::cout << "fail to open: " << argv[1] << std::endl;
        return 1;
    }
    std::string out_Name;
    out_Name = argv[1];
    out_Name += ".replace";
    std::ofstream out(out_Name.c_str()); //stupid c++98 doesnt let me just throw the var name,so I need to transform to const char* cstyleshit

    std::string line; 
    std::string buff; 

    
    if (!out.is_open()){
        std::cout << "fail to open : " << out_Name << std::endl;
        return 1;
    }

    while (getline(in, line)){
        buff += line;
        buff += '\n';
    }
    buff = replace_Str(buff, argv[2], argv[3]);
    out << buff;
    in.close();
    out.close();

    return 0;
}