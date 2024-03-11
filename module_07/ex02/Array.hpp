#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<class T>
class Array { 
	private:
		T* arr;
		unsigned int len;
	public:
		Array( void );
		~Array( void );
		Array( unsigned int n );
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		T& operator[](unsigned int idx); // unsigned porque tava dando int compare com unsignied int

		unsigned int size(void) const;

		/*class deuRuim : public std::exception{
			public:
			const char *what() const throw;
		}*/
		
};

#include "Array.tpp"

#endif