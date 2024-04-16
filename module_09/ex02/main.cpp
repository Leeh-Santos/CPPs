# include "PmergeMe.hpp"

int main(int argc, char *argv[]){

    if (argc <= 1){
        std::cout << "Please provide args" << std::endl;
        exit(1);
    }

    std::vector<std::string> args(argv, argv + argc); // range constructor
    checkInput(args);
    PmergeMe merge(args);
    merge.m_init();
    
}

/*    Grouping the Elements: First, we take a bunch of items and put them into pairs. If there's an odd number of items, we leave one unpaired.

    Comparing Each Pair: Then, for each pair, we compare the two items to find the larger one. We do this for each pair we made earlier.

    Sorting the Larger Elements: After comparing, we take all the larger items we found and sort them. We make a new list, called S, with these larger items, arranging them in order from smallest to largest.

    Adding the Smallest Element's Partner: We take the smallest item from the initial pairs we made and add it to the start of our new list, S.

    Adding the Remaining Items: Next, we take the rest of the items that weren't included in S and add them into S. But we do this in a special way. We use binary search to find where each item should go in the list S, and then we insert it there.*/