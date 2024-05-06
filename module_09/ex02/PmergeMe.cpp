# include "PmergeMe.hpp"

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
    std::cout << " big vec ---------------------------------> "  << std::endl;
    print_vec(main_vector);
    std::cout << " small vec ---------------------------------> "  << std::endl;
    print_vec(small_vector);
    jacobsthalInsert(main_vector, small_vector); // binary + jacobsthal

    //exit(1);
    std::time_t done = std::clock();
    double vector_process = (double)(done - begin) / CLOCKS_PER_SEC;
    std::cout << "After : ";
    print_container(0);

    //********LIST Pmerge part****************

    std::time_t begin2 = std::clock();
    std::cout << '\n';
    this->divideNconquer(main_list);
    this->recursive_main(main_list);
    insert_smallnb(1);

    this->jacobsthalInsert(main_list, small_list);
   
    std::time_t done2 = std::clock();
    double list_process = (double)(done2 - begin2) / CLOCKS_PER_SEC;
    std::cout << std::fixed;
    std::cout << "Time to process a range of " << main_vector.size() << " elements with std::vector : " << vector_process << " us" << std::endl;
    std::cout << "Time to process a range of " << main_list.size() << " elements with std::list : " << list_process << " us" << std::endl;

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

int PmergeMe::jacobsthal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::jacobsthalInsert(std::vector<int> &bigVec, std::vector<int> &smallVec) {
    int j = 0; // J counter
    int bigVecSize = bigVec.size();
    
    // Iterate over the elements of the smaller vector


    std::vector<int> toInsert;
    for (unsigned int i = 0; i < smallVec.size(); i++) {
       // Calculate the position to insert using Jacobsthal sequence
        int pos = jacobsthal(j);
        // Adjust the position if it exceeds the size of the big vector
        if (pos >= bigVecSize)
            pos = bigVecSize;
        
        // Check if the element already exists in bigVec
        if (std::binary_search(bigVec.begin(), bigVec.end(), smallVec[i])) {
            continue; // Skip insertion if the element already exists
        }

        // Find the insertion position using lower_bound
        std::vector<int>::iterator it = std::lower_bound(toInsert.begin(), toInsert.end(), smallVec[i]);
        
        // Insert the element at the calculated position in the temporary vector
        toInsert.insert(it, smallVec[i]);

        // Update bigVecSize
        ++bigVecSize;
        
        // Increment Jacob
        ++j;
    }

    bigVec.reserve(bigVec.size() + toInsert.size());
    bigVec.insert(bigVec.end(), toInsert.begin(), toInsert.end());
    std::cout << " nao saiu " << std::endl;
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


void PmergeMe::jacobsthalInsert(std::list<int> &bigList, std::list<int> &smallList) {
    int j = 0; // J counter

    for (std::list<int>::iterator it = smallList.begin(); it != smallList.end(); ++it) {
        int pos = jacobsthal(j);
        std::list<int>::iterator insertPos = bigList.begin();
        std::advance(insertPos, std::min(pos, static_cast<int>(bigList.size())));
        std::list<int>::iterator lb = std::lower_bound(bigList.begin(), bigList.end(), *it);
        bigList.insert(lb, *it);

        ++j; 
    }
}