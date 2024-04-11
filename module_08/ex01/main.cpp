# include "Span.hpp"

int main(){

    {
        std::cout << "___________________ fill fuction iteretor________________" << std::endl;
        Span obj(5);

        try {
            obj.addNumber(1);
            obj.addNumber(2);
            obj.addNumber(3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        
        std::vector<int> v1;

        v1.push_back(4);
        v1.push_back(5);
        //v1.push_back(6); //beyond span limit
        try
        {
            obj.filler(v1.begin(), v1.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        obj.printer();    
    }

    {
        std::cout << "___________________ shortest and largest span________________" << std::endl;

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }
}