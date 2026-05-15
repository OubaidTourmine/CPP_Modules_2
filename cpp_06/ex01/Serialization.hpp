#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h> 
#include <iostream>
#include <ostream>

typedef struct Data
{
    unsigned int num;
}Data;

class Serialization
{
    private:
        Serialization();
        Serialization(const Serialization &other);
        Serialization &operator=(const Serialization &other);
        ~Serialization();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif