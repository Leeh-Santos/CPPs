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
    for (unsigned int i = 0 ; i < vec.size() - 1 ; i += 2)
        vecpair.push_back(std::make_pair(vec[i], vec[i + 1]));

    smallestpairnb = 0;

    for (unsigned int  i = 0 ; i <= (vecpair.size() - 1) ; i++){
        for (unsigned int  k = 0 ; k <= (vecpair.size() - 1) ; k++)
            if(vecpair[i].first < vecpair[k].first){
                if(vecpair[i].second == -1)
                    continue;
                smallestpairnb = vecpair[i].second;
            }
    } 
    std::cout << smallestpairnb << std::endl;
 }

void PmergeMe::m_init(){

    std::cout << "Before : ";
    getSmallElement(main_vector);
    print_container(0);

    //int begin = std::clock();
    this->fordzin(main_vector);
    //int done = std::clock();


}

void PmergeMe::fordzin(std::vector<int> &m_vector){

    
    if (m_vector.size() < 2)
        return ;

    unsigned int size = m_vector.size() - 1;
    unsigned int i = 0;
    std::vector<int> tmp = m_vector;
    m_vector.clear();
    std::vector<int> unordered;

    while (i < size)
    {
        if (tmp[i] > tmp[i + 1]){
            m_vector.push_back(tmp[i]);         
            unordered.push_back(tmp[i + 1]);
        }
        else{
            m_vector.push_back(tmp[i + 1]);
            unordered.push_back(tmp[i]);
        }
        i += 2;
    }
    if(tmp.size() % 2)
        m_vector.push_back(tmp[i]);

    fordzin(m_vector); //first half sorted
 
    //print_container(0); 

    binaryJacobsthalInsert(m_vector, unordered);

}

void	PmergeMe::binaryJacobsthalInsert(std::vector<int>& base, std::vector<int>& merge) {

	std::vector<int>::iterator	where;
	int	index, current;

	index = 0;
	do {
		index++;
		current = (jacobsthal[index] < (int)merge.size() ? jacobsthal[index] : merge.size() - 1);
		while (current > jacobsthal[index - 1]) {
			where = std::lower_bound(base.begin(), base.end(), merge[current]);
			base.insert(where, merge[current]);
			current--;
		}
	} while (jacobsthal[index] < (int)merge.size());
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