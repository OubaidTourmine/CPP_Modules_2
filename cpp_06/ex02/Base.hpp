#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
    public:
        virtual ~Base();
    class baseException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif