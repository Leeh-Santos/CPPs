# include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    _materias[0] = NULL;
    _materias[1] = NULL;
    _materias[2] = NULL;
    _materias[3] = NULL;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL)
            delete this->_materias[i];
    }
}
MateriaSource::MateriaSource(const MateriaSource& obj){
    for (int i = 0; i < 4 ; i++)
        _materias[i] = NULL;
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
    for (int i = 0; i < 4 ; i++){
        if (_materias[i])
            delete _materias[i];
        if(!_materias[i] && obj._materias[i])
            _materias[i] = obj._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* obj){

    if (!obj){
        std::cout << "empty obj passed, not able to learn" << std::endl;
        return; 
    }

    for (int i = 0; i < 4 ; i++){
        if (!_materias[i]){
            _materias[i] = obj;
            std::cout << "new materia learned :" << obj->getType() << std::endl;
            return; 
        }
    }

    std::cout << "not able to learn materia, slots are full" << std::endl;
    std::cout << "materia passed: " << obj->getType() << " was deleted" << std::endl;
    delete obj;
}

 AMateria* MateriaSource::createMateria(std::string const & type){

    for(int i = 0; i < 4 ; i++){
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }

    std::cout << "materia not found, not able to create " << type << std::endl;
    return NULL;

 }