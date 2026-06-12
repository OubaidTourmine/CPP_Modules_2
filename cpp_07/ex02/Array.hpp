#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


template <typename T>
class Array
{
    private:
        unsigned int _size;
        T *array;
    public:
        Array() : _size(0), array(NULL) {}
        Array(unsigned int n) : _size(n), array(new T[n]()) {}
        Array(const Array& other) : _size(other._size), array(new T[other._size])
        {
            for (unsigned int i = 0; i < _size; i++)
            {
                array[i] = other.array[i];
            }
        }
        ~Array()
        {
            delete[] array;
        }

        Array<T>& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] array;
                _size = other._size;
                array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }
        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return array[index];
        }
        unsigned int size() const
        {
            return _size;
        }
    };

#endif