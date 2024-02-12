#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
    // subject example
    {
        std::cout << "--------> SUBJECT EXAMPLE <--------" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
        std::cout << std::endl;
    }
    // testing MateriaSource
    {
        std::cout << std::endl;
        std::cout << "--------> TESTING MATERIASOURCE <--------" << std::endl;
        IMateriaSource *src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice()); // MateriaSource can't learn more than 4 materias
        
        AMateria    *tmp;
        tmp = src->createMateria("fire"); // materia doesn't exist  
        tmp = src->createMateria("ice"); // create existing materias
        delete tmp;
        tmp = src->createMateria("cure");
        delete tmp;
       
        delete src;
        std::cout << std::endl;
        MateriaSource src1; // create a original src
        src1.learnMateria(new Ice());
        src1.learnMateria(new Cure());
        MateriaSource src2;
        src2 = src1;    // copy src1 to src2
        AMateria    *tmp1;
        AMateria    *tmp2;
        tmp1 = src1.createMateria("ice"); // prove that is a copy of the
        std::cout << tmp1 << std::endl;   // materia by printing the address
        tmp2 = src2.createMateria("ice");
        std::cout << tmp2 << std::endl;
        delete tmp1;
        delete tmp2;
        std::cout << std::endl;
    }
    // testing character and materia handling
    {
        std::cout << std::endl;
        std::cout << "--------> TESTING CHAR AND MATERIA HANDLE <--------" << std::endl;
        IMateriaSource  *src = new MateriaSource();
        src->learnMateria(new Ice());   // learning and creating materias
        src->learnMateria(new Cure());
        AMateria    *tmp;
        AMateria    *tmp1;   
        AMateria    *tmp2;
        AMateria    *tmp3;
        AMateria    *tmp4;
        tmp = src->createMateria("ice");
        tmp1 = src->createMateria("fire"); // materia type doesnt exist
        tmp2 = src->createMateria("cure");
        tmp3 = tmp->clone();    // prove that clone() creates a new copy

        std::cout << std::endl;

        ICharacter  *ze = new Character("Ze"); // create 2 char
        ICharacter  *manel = new Character("Manel");

        std::cout << std::endl;
        ze->equip(tmp);     // test equip
        ze->equip(tmp1); // Trying to equip empty materia
        manel->equip(tmp2);
        manel->equip(tmp3);
        tmp3 = src->createMateria("ice"); // creating a new materia to keep equip in manel
        manel->equip(tmp3);
        tmp4 = tmp3;
        tmp3 = src->createMateria("cure");
        manel->equip(tmp3);
        tmp3 = src->createMateria("ice"); 
        manel->equip(tmp3); // trying to equip more that 4 materia

        std::cout << std::endl;
        delete tmp3;
        delete src; // delete src to prove the materias passed to char are new copys

        std::cout << std::endl;
        ze->use(0, *manel); // testing use
        ze->use(2, *manel); // testing in range slot but with no materia
        manel->use(0, *ze);
        manel->use(1, *ze);
        manel->use(2, *ze);
        manel->use(5, *ze); // testing out of range slots
        manel->use(-1, *ze);
        std::cout << std::endl;

        manel->unequip(2); // test unequip materia
        manel->use(2, *ze); // try use unequiped materia
        manel->unequip(2); // try unequip a empty materia
        manel->unequip(5); // try to unequip a out of range materia
        manel->equip(tmp4); // equip materia again
        manel->use(2, *ze); // try to use materia again

        delete ze;
        delete manel;
        std::cout << std::endl;
    }
    // character deep copy proof
    {
        std::cout << std::endl;
        std::cout << "--------> CHARACTER DEEP COPY <--------" << std::endl;
        IMateriaSource  *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        AMateria    *tmp;
        tmp = src->createMateria("ice");

        Character  *ze = new Character("Ze"); // create original char
        ze->equip(tmp);
        tmp = src->createMateria("cure");
        ze->equip(tmp); // equip it with ice and cure
        std::cout << std::endl;
        Character  *ze2 = new Character(*ze); // create a new character passing the first as parameter
        std::cout << "name: " << ze2->getName() << std::endl; // print char name
        ze2->use(0, *ze); // use as ze2
        ze2->use(1, *ze);
        ze2->use(2, *ze);
        ze2->use(3, *ze);
        std::cout << "pau agora meu nego" << std::endl;
        delete ze; // delete original char
        Character   ze3("Ze Luis"); // create a third char to use as target
         
        std::cout << std::endl;
        std::cout << "pau agora meu nego" << std::endl;
        ze2->use(0, ze3); // use ze2 after ze was deleted to prove its a new copy
        std::cout << "nao chegou" << std::endl;
        ze2->use(1, ze3);
        
        ze2->use(2, ze3);
       
        ze2->use(3, ze3);
        std::cout << std::endl;
        
        delete ze2;
        delete src;

        
    }
}