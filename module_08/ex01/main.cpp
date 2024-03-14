# include "Span.hpp"

int main(){
    Span obj(5);
    obj.addNumber(2);
    std::cout << obj.shortestSpan() << std::endl;
}