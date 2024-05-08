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
    std::vector<int> main_vector;
    std::vector<int> small_vector;

    std::list<int> main_list;
    std::list<int> small_list;

    int smallestpairnb;
    int flag;    
       
public:
    
    PmergeMe();
    PmergeMe(std::vector<std::string> &vec);
    PmergeMe& operator=(const PmergeMe& obj);
    PmergeMe(const PmergeMe& obj);
    
    ~PmergeMe();

    void m_init();
    void print_container(int);
    void getSmallElement(std::vector<int>);
    void print_vec(std::vector<int>);
    

    void recursive_main(std::vector<int> &);
    void recursive_main(std::list<int> &);

    void divideNconquer(std::vector<int> &vec);
    void divideNconquer(std::list<int> &vec);
    
    void insert_smallnb(int);

    void jacobsthalInsert(std::vector<int> &bigVec, std::vector<int> &smallVec);
    void jacobsthalInsert(std::list<int> &bigVec, std::list<int> &smallVec);
    //int jacobsthal(int n);

    void insertNumber(std::vector<int> &vec, int n);
    void insertNumber(std::list<int> &vec, int n);

    void vec();
};

void checkInput( std::vector<std::string> &args);
