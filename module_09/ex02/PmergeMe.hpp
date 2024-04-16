# pragma once

# include <iostream>
# include <vector>
#include <cstdlib>
#include <algorithm>
# include <list> 
# include <ctime>

class PmergeMe
{
private:
    static const int	jacobsthal[35];
    std::vector<int> main_vector;
    std::list<int> main_list;
       
public:
    
    PmergeMe(std::vector<std::string> &vec);
    ~PmergeMe();
    void m_init();
    void print_container(int);
    void fordzin(std::vector<int> &);
    void fordzin(std::list<int> &);

    void	binaryJacobsthalInsert(std::vector<int>& base, std::vector<int>& merge);
    void printVector(std::vector<int> vector);
};

void checkInput( std::vector<std::string> &args);