#include "Serialization.hpp"

int main ()
{
    Data *ptr = new Data();
    ptr->num = 42;
    
    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Original value: " << ptr->num << std::endl;
    

    uintptr_t raw = Serialization::serialize(ptr);
    std::cout << "Serialized: " << raw << std::endl;
    
    Data *ptr2 = Serialization::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;
    std::cout << "Deserialized value: " << ptr2->num << std::endl;
    
    if (ptr == ptr2)
        std::cout << " Pointers match!" << std::endl;
    
    delete ptr;
    return 0;
}