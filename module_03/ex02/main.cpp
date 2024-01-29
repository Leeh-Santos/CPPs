# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(){

    { //When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order.
    std::cout << "_____________const and destruc chain :___________________ " <<std::endl;
    ClapTrap p1("clappy");
    ScavTrap p2("scavy");
    FragTrap p3("fraggy");
    }

    {
    std::cout << "_____________funcs___________________ " <<std::endl;
    ClapTrap p1("clappy");
    ScavTrap p2("scavy");
    FragTrap p3("fraggy");
    p1.attack("mom");
    p2.attack("mom");
    p3.attack("mom");
    std::cout << std::endl;

    p2.guardGate();
    p3.highFivesGuys();
    }
    

  



}