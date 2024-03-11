#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <cstdlib>
#include "Array.hpp"

template<class T> 
Array<T>::Array( void ) {
	arr = new T[0];
	len = 0;
}

template<class T>
Array<T>::~Array( void ) {
	delete []arr;
}

template<class T>
Array<T>::Array(unsigned int n){
	arr = new T[n];
	len = n;
}

template<class T>
Array<T>::Array(const Array& obj){
	arr = NULL;
	len = 0;
	*this = obj;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& obj){
	
	len = obj.len;
	if (this->arr != NULL)
		delete[] arr;
	arr = new T[obj.len];
	for (unsigned int i = 0; i < obj.len; i++)
		arr[i] = obj.arr[i];
	return *this;
}

template<class T>
T& Array<T>::operator[](unsigned int idx){

	if (idx < 0 || idx >= len)
		throw std::out_of_range("invalid index");
	return arr[idx];

}

template<class T>
unsigned int Array<T>::size(void) const{
	return len;
}


#endif
