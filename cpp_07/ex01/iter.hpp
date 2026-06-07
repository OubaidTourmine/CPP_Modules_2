#ifndef ITER_HPP
#define ITER_HPP


template <typename A, typename B, typename C>
void iter(A *array, B length, C func)
{
    for (B i = 0; i < length; ++i)
        func(array[i]);
}
#endif