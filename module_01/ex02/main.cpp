#include <iostream>
#include <string>

int main( void )
{
	std::string example = "HI THIS IS BRAIN";
	std::string *PTR = &example;
	std::string &REF = example;

   

	std::cout << "Memory Adress string:    " << &example << std::endl;
	std::cout << "Memory Adress pointer:   " << PTR << std::endl;
	std::cout << "Memory Adress reference: " << &REF << std::endl;

	std::cout << "Value of pointer:        " << *PTR << std::endl;
	std::cout << "Value of reference:      " << REF << std::endl;

}