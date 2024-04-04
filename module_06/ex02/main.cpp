# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

//dynamic cast failed pointer returns null
//dynamic cast failed at ref throws excpection std::bad_Cast

Base* generate(void){
    srand(time(NULL));

    int nb = rand() % 3;
    if (nb == 0)
        return (new A());
    else if (nb == 1)
        return (new B());
    else 
        return (new C());
}

void identify(Base* p){

    if (dynamic_cast<A*>(p))
        std::cout << "Type A class identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B class identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C class identified" << std::endl;
    else    
        std::cout << "Daaaa fu** is this?" << std::endl;

}

void identify(Base& p){
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type A class identified" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type B class identified" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type C class identified" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    std::cout << "daaaa fu** is this?" << std::endl;
}

int main(){

    Base *b = new Base(); // not derivated, should fail
    Base *b1 = generate();

    identify(b);
    identify(*b);
    identify(b1);
    identify(*b1);
    
    delete b1;
    delete b;
}