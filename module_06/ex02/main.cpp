# include "Base.hpp"

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



int main(){

    Base *b1 = generate();
}