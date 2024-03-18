# include "Span.hpp"

int main(){
    Span obj(5);

    obj.addNumber(1);
    obj.addNumber(2);
    obj.addNumber(3);

    std::vector<int> v1;

    v1.push_back(4);
    v1.push_back(5);
    //v1.push_back(6);

    try
    {
        obj.filler(v1.begin(), v1.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    obj.printer();

    //std::cout << obj.shortestSpan() << std::endl;
}