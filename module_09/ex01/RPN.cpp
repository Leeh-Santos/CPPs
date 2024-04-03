# include "RPN.hpp"

int rpn::calculator(int nb2, int nb, char c){

    switch (c)
    {
    case '+':
        return nb2 + nb;
        break;
    case '-':
        return nb - nb2;
        break;
    case '*':
        return nb2 * nb;
        break;
    case '/':
        if (nb2 == 0 || nb == 0){
            std::cout << "division by zero detected invalid RPN input" << std::endl;
            exit(1);
        }
        return nb / nb2;
        break;
    }
    return 0;
}

bool rpn::isOp(const char c){
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return 1;
    return 0;
}

void rpn::validString(const std::string str){

    for (unsigned int i = 0; i < str.size() ; i++){
        if (isdigit(str[i]) || isOp(str[i])){
            if (str[i + 1] && str[i + 1] != ' '){
                std::cout << "invalid input or missing space" << std::endl;
                exit(1);
            }
        }
        else if (str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && !isdigit(str[i])){
            std::cout << "invalid input, is not as RPN valid notation" << std::endl;
            exit(1);
        }
    }

    dale(str);
}

void   rpn::dale(const std::string str){
    std::stack<int> stackzin;

    for (unsigned int i = 0; i < str.size() ; i++){
        if (isdigit(str[i])){
            stackzin.push(atoi(&str[i]));
        }
        else if(isOp(str[i])){
            if (stackzin.size() < 2){
                std::cout << "missing values for math, Invalid RPN" << std::endl;
                exit(1);
            }
            int nb2 = stackzin.top();
            stackzin.pop();
            int nb = stackzin.top();
            stackzin.pop();
            int res = calculator(nb2, nb, str[i]);
            stackzin.push(res);
        }
    }

    if(stackzin.size() != 1){
        std::cout << "invalid RPN format" << std::endl;
        exit(1);
    }
    std::cout << "result: " << stackzin.top() << std::endl;
}