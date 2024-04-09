//#pragma once

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>   


template <typename T>
void    iter(T *arr, size_t len, void (*func)(const T)){
    if ((!arr) || (len <= 0))
        return;

    for (size_t i = 0 ; i < len ; i++)
        func(arr[i]);
}

template <typename T>
void    print(T x){
    std::cout << x << std::endl;
}

#endif