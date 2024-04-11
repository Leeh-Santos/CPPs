#pragma once

# include <algorithm>
# include <vector>
# include <iostream> 

class Span
{
private:
    unsigned int _N;
    std::vector<int> vec;
    Span();

public:
    ~Span();
    Span(unsigned int N);
    Span(const Span& obj);
    Span& operator=(const Span& obj);
    void addNumber(int nb);

    int longestSpan();
    int shortestSpan();

    void filler(std::vector<int>::iterator front, std::vector<int>::iterator back);

    void printer(void);
    


};

