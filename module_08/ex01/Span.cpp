# include "Span.hpp"

Span::Span(/* args */)
{
}

Span::~Span()
{
}

Span::Span(unsigned int N){
    _N = N;
}

Span::Span(const Span& obj){
    _N = obj._N;
    vec = obj.vec;
}

Span& Span::operator=(const Span& obj){
    _N = obj._N;
    vec = obj.vec;
    return *this;
}

void Span::addNumber(int nb){
    if (vec.size() < _N)
        vec.push_back(nb);
    else
        throw std::out_of_range("out of space in array");
}

int Span::shortestSpan(){ // menor diferenca
    if(vec.size() < 2)
        throw std::out_of_range("size of array is 0");
    
    std::sort(vec.begin(), vec.end());

}

/*int Span::longestSpan(){ // maior diferenca

}*/