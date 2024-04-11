#pragma once

#include <iostream>
#include <deque>
#include <stack>
#include <iterator>
#include <list>
# include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
    /* data */
public:
    MutantStack(/* args */);
    ~MutantStack();
    MutantStack( const MutantStack& obj);
	MutantStack& operator=( const MutantStack& obj);
    typedef typename std::deque<T>::iterator iterator;
    iterator begin(void){
        return this->c.begin();
    }
    iterator end(void){
        return this->c.end();
    }

};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& obj){
    *this = obj;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& obj){
    (void)obj;
    return *this;
}

/*template<typename T>
typename MutantStack<T>::iterador  MutantStack<T>::begin(void){
    
}

template<typename T>
typename MutantStack<T>::iterador  MutantStack<T>::end(void){

}*/