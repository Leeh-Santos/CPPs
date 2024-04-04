# include "Serializer.hpp"

int main(){

    Data *d1 = new Data();

    d1->x = 5, d1->y = 10;

    std::cout << d1->x << std::endl;
    std::cout << d1->y << std::endl;
    std::cout << "pointer at d1" << d1 << std::endl;
    
    uintptr_t ptr = Serializer::serialize(d1); 
	Data *d2 = Serializer::deserialize(ptr);
    

    std::cout << "**deserialized pointer**" << std::endl;

    std::cout << d1->x << std::endl;
    std::cout << d1->y << std::endl;
    std::cout << d2->x << std::endl;
    std::cout << d2->y << std::endl;

    delete d1;
    


    

}