#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria{
	protected:
		std::string	 _type;
	public:
		AMateria();
		AMateria( const AMateria& obj);
		AMateria& operator=( const AMateria& obj);
		virtual ~AMateria();

		AMateria(std::string const & type); //setter
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; //returns same type
		virtual void use(ICharacter& target);
};

#endif