# include "MutantStack.hpp"

int main(){

    {
        std::cout << "____________________________________________subject test__________________________________" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }


    {
        std::cout << "____________________________________________other test__________________________________" << std::endl;
        MutantStack<std::string> strstack;

        strstack.push("str0");
        strstack.push("str1");
        strstack.push("str3");
        std::cout << strstack.size() << std::endl;
        std::cout << strstack.top() << std::endl;
        strstack.push("str4");
        strstack.push("str5");
        strstack.push("str6");

        MutantStack<std::string>::iterator it = strstack.begin();
        MutantStack<std::string>::iterator it2 = strstack.end();

        while (it != it2)
        {
            std::cout << *it << std::endl;
            ++it;
        }



        std::cout << '\n';
        std::cout << "copy test" << std::endl;
        std::stack<std::string> copytest(strstack);
        std::cout << copytest.size() << std::endl;
        std::cout << copytest.top() << std::endl;
    }

}