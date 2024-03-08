#pragma once
#include <iostream>
#include <string>

template <typename T>
void    iter(T *arr, int len, void (*func)(T&)){
    if (!arr | len <= 0)
        return;

    for (int i = 0 ; i < len ; i++)
        func[i];
}

template <typename T>
void    printer(T& x){
    std::cout << x << std::endl;
}