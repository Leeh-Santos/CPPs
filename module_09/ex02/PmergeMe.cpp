# include "PmergeMe.hpp"

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){
    main_list = obj.main_list;
    small_list = obj.small_list;
    main_vector = obj.main_vector;
    small_vector = obj.main_vector;

    smallestpairnb = obj.smallestpairnb;
    flag = obj.flag;

    return *this;

}
PmergeMe::PmergeMe(const PmergeMe& obj){
    *this = obj;
}

PmergeMe::PmergeMe(std::vector<std::string> &vec)
{
    for(size_t i = 1; i < vec.size(); i++){
        int nb = std::atoi(vec[i].c_str());
        main_vector.push_back(nb);
        main_list.push_back(nb);
    }

    if (main_list.size() < 2 || main_vector.size() < 2){
        std::cout << "Please provide more numbers meu parceiro" << std::endl;
        exit(1);
    }
    
    flag = 0;
}

PmergeMe::~PmergeMe()
{
}

void checkInput( std::vector<std::string> &args){

    std::string::iterator it;

    for (size_t i = 1; i < args.size(); i++){
        for (it = args[i].begin(); it != args[i].end() ; it++){
            if(!isdigit(*it)){
                std::cout << "invalid input" << std::endl;
                exit(1);
            }
        }
        
    }
    /*std::cout << "Arguments:" << std::endl;
    for (size_t i = 0; i < args.size(); ++i) {
        std::cout << "argv[" << i << "]: " << args[i] << std::endl;
    }*/
}

 void PmergeMe::getSmallElement(std::vector<int> vec){
    if(vec.size() % 2)
        vec.push_back(-1);
    
    std::vector<std::pair<int, int> > vecpair;
    for (unsigned int i = 0 ; i <= (vec.size() - 1) ; i += 2)
        vecpair.push_back(std::make_pair(vec[i], vec[i + 1]));

    std::pair<int, int> smallestpair = std::make_pair(2147483647, 0);

    for (unsigned int  i = 0 ; i <= (vecpair.size() - 1) ; i++){
        if (vecpair[i].first < smallestpair.first){
            if(vecpair[i].second == -1)
                continue;
            smallestpair = vecpair[i];
        }
    }

    if (smallestpair.first < smallestpair.second) // get smallest nb from the pair
        smallestpairnb = smallestpair.first;
    else
        smallestpairnb = smallestpair.second;
 }

void PmergeMe::m_init(){

    std::cout << "Before : ";
    print_container(0);
    std::cout << '\n';
    std::time_t begin = std::clock();
    getSmallElement(main_vector);
    this->divideNconquer(main_vector);//split first the pairs
    this->recursive_main(main_vector); // recursive only main chain
    insert_smallnb(0); // insert smallest into main chain
    jacobsthalInsert(main_vector, small_vector); // binary + jacobsthal ta comendo um nuemro aqui 
    vec();
    std::time_t done = std::clock();
    double vector_process = (double)(done - begin) / CLOCKS_PER_SEC;
; 

    //********LIST Pmerge part****************
    std::time_t begin2 = std::clock();
    this->divideNconquer(main_list);
    this->recursive_main(main_list);
    insert_smallnb(1);
    this->jacobsthalInsert(main_list, small_list);
    std::time_t done2 = std::clock();
    double list_process = (double)(done2 - begin2) / CLOCKS_PER_SEC;
    std::cout << "After  : ";
    print_container(0);
    std::cout << '\n';
    std::cout << std::fixed;
    std::cout << "Time to process a range of " << main_vector.size() << " elements with std::vector : " << vector_process << " us" << std::endl;
    std::cout << "Time to process a range of " << main_list.size() + 1 << " elements with std::list : " << list_process << " us" << std::endl;

}

void PmergeMe::recursive_main(std::vector<int> &vec){

     if (vec.size() <= 1)
        return; 

    unsigned int pivot_index = vec.size() / 2;
    int pivot_value = vec[pivot_index];

    std::vector<int> less_than_pivot;
    std::vector<int> greater_than_pivot;
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (i == pivot_index)
            continue;
        if (vec[i] <= pivot_value)
            less_than_pivot.push_back(vec[i]);
        else
            greater_than_pivot.push_back(vec[i]);
    }

    recursive_main(less_than_pivot);
    recursive_main(greater_than_pivot);

    vec.clear();
    vec.insert(vec.end(), less_than_pivot.begin(), less_than_pivot.end());
    vec.push_back(pivot_value);
    vec.insert(vec.end(), greater_than_pivot.begin(), greater_than_pivot.end());

}


void PmergeMe::insertNumber(std::vector<int> &vec, int n) {
    vec.insert(std::upper_bound(vec.begin(), vec.end(), n), n); // if there is n, returns it from bigger one, if no just returns the last, sempre o segundo?
}

void PmergeMe::jacobsthalInsert(std::vector<int> &bigVec, std::vector<int> &smallVec) {

    size_t jacobsthal[] = {
        3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845
    };
    
    if (!flag)
        bigVec.insert(bigVec.begin(), small_vector[0]);
    
    size_t i = 0;
    size_t prev = 0;
    size_t current = jacobsthal[i];
    while (current < smallVec.size()) {
        do {
            insertNumber(bigVec, smallVec[current]);
        } while (--current > prev);
        prev = jacobsthal[i];
        current = jacobsthal[++i];
    }
    while (++prev < smallVec.size()) {
        insertNumber(bigVec, smallVec[prev]);
    }

    /*std::cout << "after jacobstal" << '\n' << '\n';
    std::cout << " big vec ---------------------------------> "  << std::endl;
    print_vec(main_vector);
    std::cout << " small vec ---------------------------------> "  << std::endl;
    print_vec(small_vector);
    exit(1);*/
    std::sort(bigVec.begin(), bigVec.end());
}


void    PmergeMe::divideNconquer(std::vector<int> &vec){

    unsigned int size = vec.size() - 1;
    unsigned int i = 0;
    std::vector<int> tmp = vec;
    vec.clear();
   
    while (i < size)
    {
        if (tmp[i] > tmp[i + 1]){
            vec.push_back(tmp[i]);         
            small_vector.push_back(tmp[i + 1]);
        }
        else{
            vec.push_back(tmp[i + 1]);
            small_vector.push_back(tmp[i]);
        }
        i += 2;
    }
    if(tmp.size() % 2)
        vec.push_back(tmp[i]);

    if (small_vector.size() <= 1)
        flag++;
}

void PmergeMe::insert_smallnb(int x){ // its ugly I know, my bad, I could use templates but it would require some extra changes but im too lazy to think
    if (!x){
        main_vector.insert(main_vector.begin(), smallestpairnb);
        std::vector<int>::iterator it = std::find(small_vector.begin(), small_vector.end() ,smallestpairnb);
        small_vector.erase(it);
    }
    else{
        main_list.insert(main_list.begin(), smallestpairnb);
        std::list<int>::iterator it = std::find(small_list.begin(), small_list.end() ,smallestpairnb);
        small_list.erase(it);
    }
}

void PmergeMe::print_container(int x){
    if (!x){
        for (std::vector<int>::iterator it = main_vector.begin() ; it != main_vector.end() ; it++)
            std::cout << *it << " ";
    }
    else{
        for (std::list<int>::iterator it = main_list.begin() ; it != main_list.end() ; it++)
            std::cout << *it << " ";   
    }
}

void PmergeMe::vec(){std::sort(main_vector.begin(), main_vector.end());}
void PmergeMe::print_vec(std::vector<int> vec){

    std::cout << "printing vector :" << std::endl;
    for (std::vector<int>::iterator it = vec.begin() ; it != vec.end() ; it++)
            std::cout << *it << " ";
    std::cout << std::endl;

}

// ________________________________My bad didnt use Templates so I created same fucs for vec and list, dont judge me

void    PmergeMe::divideNconquer(std::list<int> &vec){

    std::list<int> vecit = vec;
    vec.clear();
   
    std::list<int>::iterator it = vecit.begin();
    std::list<int>::iterator size = vecit.end();

    if(vecit.size() % 2) // if is odd we dont go to the end 
        --size;
    
    while (it != size){ 
        std::list<int>::iterator tmp2 = it++;
        if (*it > *tmp2){
            vec.push_back(*it);
            small_list.push_back(*tmp2);
        }
        else{
            vec.push_back(*tmp2);
            small_list.push_back(*it);
        }
        it++;
    }
    if(vecit.size() % 2)
        vec.push_back(*(size)); // we send the last one then
}

void PmergeMe::recursive_main(std::list<int> &lst) {
    if (lst.size() <= 1)
        return;

    std::list<int>::iterator slow = lst.begin();
    std::list<int>::iterator  fast = lst.begin();
    std::list<int>::iterator end = lst.end();

    while (fast != end && ++fast != end) {
        ++slow;
    }

    std::list<int> left(lst.begin(), slow);
    std::list<int> right(slow, lst.end());

    recursive_main(left);
    recursive_main(right);

    lst.clear();
    std::list<int>::iterator  left_it = left.begin();
    std::list<int>::iterator  right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            lst.push_back(*left_it);
            ++left_it;
        } else {
            lst.push_back(*right_it);
            ++right_it;
        }
    }

    lst.insert(lst.end(), left_it, left.end());
    lst.insert(lst.end(), right_it, right.end());
}

void PmergeMe::insertNumber(std::list<int> &vec, int n) {
    vec.insert(std::upper_bound(vec.begin(), vec.end(), n), n); // if there is n, returns it from bigger one, if no just returns the last
}

void PmergeMe::jacobsthalInsert(std::list<int> &big, std::list<int> &small) {

    size_t jacobsthal[] = {
        3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845
    };
    size_t i = 0;
    size_t prev = 0;
    size_t current = jacobsthal[i];
    std::list<int>::iterator it = small.begin();
    while (current < small.size()) {
        do {
            std::advance(it, current);
            insertNumber(big, *it);
        } while (--current > prev);
        prev = jacobsthal[i];
        current = jacobsthal[++i];
    }
    std::list<int>::iterator it1 = small.begin();
    while (++prev < small.size()) {
        std::advance(it1, prev);
        insertNumber(big, *it1);
    }
    
}


