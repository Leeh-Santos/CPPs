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

const int PmergeMe::jacobsthal[35] = {
	-1, 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765
};


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

    //std::cout << "Before : ";
    getSmallElement(main_vector);


    //int begin = std::clock();
    this->divideNconquer(main_vector);
    this->recursive_main(main_vector);
    insert_smallnb();
    
    //int done = std::clock();

    print_vec(main_vector);
    print_vec(small_vector);
   
    /*std::cout << '\n';
    std::cout << "semi after : ";
    print_container(0); */


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

void	PmergeMe::binaryJacobsthalInsert(std::vector<int>& main, std::vector<int>& smaller) {

    main.insert(main.begin(), smallestpairnb);
    std::vector<int>::iterator it = std::find(smaller.begin(), smaller.end(), smallestpairnb);
    (void)it;
    //smaller.erase(it);

    std::cout << "main :" << std::endl;
    for (std::vector<int>::iterator it = main.begin() ; it != main.end() ; it++)
            std::cout << *it << " ";
    std::cout << "smaller :" << std::endl;
    for (std::vector<int>::iterator it = smaller.begin() ; it != smaller.end() ; it++)
            std::cout << *it << " ";
    std::cout << std::endl;


	std::vector<int>::iterator	where;
	int	index, current;

	index = 0;
	do {
		index++;
		current = (jacobsthal[index] < (int)smaller.size() ? jacobsthal[index] : smaller.size() - 1);
		while (current > jacobsthal[index - 1]) {
			where = std::lower_bound(main.begin(), main.end(), smaller[current]);
			main.insert(where, smaller[current]);
			current--;
		}
	} while (jacobsthal[index] < (int)smaller.size());
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
    else 
    for (std::list<int>::iterator it = main_list.begin() ; it != main_list.end() ; it++)
        std::cout << *it << " ";   
}

void PmergeMe::print_vec(std::vector<int> vec){

    std::cout << "printing vector :" << std::endl;
    for (std::vector<int>::iterator it = vec.begin() ; it != vec.end() ; it++)
            std::cout << *it << " ";
    std::cout << std::endl;

}