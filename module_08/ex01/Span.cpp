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
        throw std::out_of_range("size of array is 0 or less than 2");

    std::sort(vec.begin(), vec.end());

    int mem = 2147483647;

    for (int i = 0; i < vec.size(); i++)
        mem = std::min(mem, vec[i + 1] - vec[i]);
    return mem;
}

int Span::longestSpan(){ // maior diferenca
    if(vec.size() < 2)
        throw std::out_of_range("size of array is 0 or less than 2");
    
    std::sort(vec.begin(), vec.end());

    int idx = vec.size() - 1;
    return vec[idx] - vec[0];

}

void Span::filler(std::vector<int>::iterator front, std::vector<int>::iterator back){

    if (std::distance(front, back) + vec.size() > _N)
        throw std::out_of_range("not able to add values to array");

    vec.insert(vec.end(), front, back);
}