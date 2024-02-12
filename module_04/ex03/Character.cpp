# include "Character.hpp"

Character::Character() : _name(""){
    slots[0] = NULL;
    slots[1] = NULL;
    slots[2] = NULL;
    slots[3] = NULL;
}

Character::Character(std::string name) : _name(name){
    slots[0] = NULL;
    slots[1] = NULL;
    slots[2] = NULL;
    slots[3] = NULL;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        if (slots[i])
            delete slots[i];
    }
}

Character::Character(const Character& obj){
    _name = obj._name;
    for (int i = 0; i < 4 ; i++)
        this->slots[i] = NULL;
    *this = obj;
}

Character& Character::operator=(const Character& obj){
    _name = obj._name;
    for (int i = 0; i < 4 ; i++){
        if (slots[i])
            delete slots[i];
        if (obj.slots[i] && this->slots[i] == NULL)
            this->slots[i] = obj.slots[i]->clone();
        else 
            this->slots[i] = NULL;
    }
    return *this;
}

std::string const & Character::getName() const{
    return _name;
}

void Character::equip(AMateria* m){
    if (!m){
        std::cout << "materia is empty meu brother, not able to equip" << std::endl;
        return ;
    }
    for (int i = 0; i < 4 ; i++){
        if (!slots[i]){
            slots[i] = m;
            std::cout << "materia: " << m->getType() << " added to " << _name << std::endl;
            return ;
        }
    }
    std::cout << " not able to equip materia, slots are full meu parceiro" << std::endl;
}

void Character::use(int idx, ICharacter& target){
    if ((idx < 0) || (idx > 3)){
        std::cout << " invalid index, not able to use on" << target.getName() << std::endl;
        return ;
    }
    else if (slots[idx])
        slots[idx]->use(target);
    else
        std::cout << "character slot is empty, not able to use on " << target.getName() << std::endl;


}

void Character::unequip(int idx){
    if ((idx < 0) || (idx > 3)){
        std::cout << " invalid index, not able to unequip" << std::endl;
        return ;
    }
    if (slots[idx] == NULL){
        std::cout << "slot is already empty " << std::endl;
        return ; 
    }
    else {
        std::cout << "just unequiped " << slots[idx]->getType() << "succesfully" << std::endl;
        slots[idx] = NULL;
    }
}