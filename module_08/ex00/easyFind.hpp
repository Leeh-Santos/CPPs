# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <list>

template<typename T>
int easyfind(T &vec, int nb){

    std::vector<int>::iterator it;

    it = std::find(vec.begin(), vec.end(), nb);
    if (it == vec.end())
        return -1;
    return *it;
    
}



# endif