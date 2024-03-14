#pragma once

# include <algorithm>
# include <vector>
# include <iostream> 

class Span
{
private:
    unsigned int _N;
    std::vector<int> vec;

public:
    Span();
    ~Span();
    Span(unsigned int N);
    Span(const Span& obj);
    Span& operator=(const Span& obj);
    void addNumber(int nb);

    int shortestSpan();
    //int longestSpan();


};

