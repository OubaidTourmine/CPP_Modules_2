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
