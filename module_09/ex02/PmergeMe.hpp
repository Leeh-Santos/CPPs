# pragma once

# include <iostream>
# include <vector>
#include <cstdlib>
#include <algorithm>
# include <list> 
# include <ctime>
#include <utility> 

class PmergeMe
{
private:
    static const int	jacobsthal[35];
    std::vector<int> main_vector;
    std::list<int> main_list;

    std::vector<int> unordered;
    int smallestpairnb;
       
public:
    
    PmergeMe(std::vector<std::string> &vec);
    ~PmergeMe();
    void m_init();
    void print_container(int);
    void print_vec(std::vector<int>);
    void fordzin(std::vector<int> &);
    void fordzin(std::list<int> &);
    void getSmallElement(std::vector<int>);

    void	binaryJacobsthalInsert(std::vector<int>& base, std::vector<int>& merge);
    
};

void checkInput( std::vector<std::string> &args);