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
    insert_smallnb(); // insert smallest into main chain
    jacobsthalInsert(main_vector, small_vector); // binary + jacobsthal
    std::time_t done = std::clock();
    double vector_process = (double)(done - begin) / CLOCKS_PER_SEC;
    std::cout << "After : ";
    print_container(0);

    //********LIST Pmerge part****************
    std::time_t begin2 = std::clock();
    this->divideNconquer(main_list);
   
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
    int j = 0; // Counter for the Jacobsthal sequence
    int bigVecSize = bigVec.size();
    
    // Iterate over the elements of the smaller vector
    for (unsigned int i = 0; i < smallVec.size(); ++i) {
        // Calculate the position to insert using Jacobsthal sequence
        int pos = jacobsthal(j);
        
        // Adjust the position if it exceeds the size of the big vector
        if (pos >= bigVecSize)
            pos = bigVecSize;
        
        // Use lower_bound to find the position to insert the element
        std::vector<int>::iterator it = std::lower_bound(bigVec.begin(), bigVec.end(), smallVec[i]);
        
        // Insert the element from the smaller vector into the bigger vector at calculated position
        bigVec.insert(it, smallVec[i]);
        
        // Increment the Jacobsthal sequence counter
        ++j;
    }
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

void PmergeMe::insert_smallnb(){
    main_vector.insert(main_vector.begin(), smallestpairnb);

    std::vector<int>::iterator it = std::find(small_vector.begin(), small_vector.end() ,smallestpairnb);
    small_vector.erase(it);
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

    unsigned int size = vec.size() - 1;
    unsigned int i = 0;
    std::list<int> tmp = vec;
    vec.clear();
   
    /*while (i < size)
    {
        if (tmp[i] > tmp[i + 1]){
            vec.push_back(tmp[i]);         
            small_list.push_back(tmp[i + 1]);
        }
        else{
            vec.push_back(tmp[i + 1]);
            small_list.push_back(tmp[i]);
        }
        i += 2;
    }*/
    std::list<int>::iterator it = vec.begin();

    while (it != (--vec.end())){ //check the ++ in it
        std::list<int>::iterator tmp = it;
        if (*tmp > ++*tmp){
            vec.push_back(*it);
            small_list.push_back(*it);
        }
        else{
            vec.push_back(*tmp);
            small_list.push_back(--*tmp);
        }
        it++;
        it++;
    }

    if(vec.size() % 2)
        vec.push_back(*(--vec.end())); // manda o ultimo, testa esse negocio nojento depois
}