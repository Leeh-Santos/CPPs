# include "ClapTrap.hpp"

int main(){

    {
    
    std::cout << "___________attack test_________" << std::endl;
    ClapTrap p1("lele");
    for (int i = 0 ; i <= 10; i++)
        p1.attack("mom");
    p1.beRepaired(1);
    }

    {
    std::cout << std::endl;
    std::cout << "___________damage test_________" << std::endl;
    ClapTrap p1("lulu");
    p1.takeDamage(1);
    p1.takeDamage(9);
    }

    {
    std::cout << std::endl;
    std::cout << "___________Repair test/out of energy_________" << std::endl;
    ClapTrap p1("lolo");
    for (int i = 0 ; i <= 10; i++)
        p1.beRepaired(1);
    p1.attack("papa");
    p1.takeDamage(1);
    p1.takeDamage(19);
    p1.takeDamage(1);
    }



}