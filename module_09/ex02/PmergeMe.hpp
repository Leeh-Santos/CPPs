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
    std::vector<int> small_vector;

    std::list<int> main_list;
    std::list<int> small_list;

    int smallestpairnb;
    
       
public:
    
    PmergeMe(std::vector<std::string> &vec);
    ~PmergeMe();
    void m_init();
    void print_container(int);
    void getSmallElement(std::vector<int>);
    void print_vec(std::vector<int>);
    

    void recursive_main(std::vector<int> &);
    void recursive_main(std::list<int> &);
    void divideNconquer(std::vector<int> &vec);
    void divideNconquer(std::list<int> &vec);

    void	binaryJacobsthalInsert(std::vector<int>& base, std::vector<int>& merge);
    void insert_smallnb();
};

void checkInput( std::vector<std::string> &args);