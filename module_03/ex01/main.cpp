# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main(){

    { //When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order.
    std::cout << "_____________const and destruc chain :___________________ " <<std::endl;
    ClapTrap p1("clappy");
    ScavTrap P2("scavy");
    }

    {
    std::cout << "_____________funcs___________________ " <<std::endl;
    ClapTrap p1("clappy");
    ScavTrap p2("scavy");

    p1.attack("mom");
    p2.attack("mom");
    p2.guardGate();
    }
    

  



}