#pragma once

# include <stdint.h>
# include <iostream>

struct Data
{
    int x;
    int y;
};


class Serializer
{
private:
    Serializer(/* args */);
public:
    
    ~Serializer();
    Serializer(const Serializer& obj);
    Serializer& operator=(const Serializer& obj);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
